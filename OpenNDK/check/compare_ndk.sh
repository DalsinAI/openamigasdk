#!/bin/sh
# Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
# Checks OpenNDK against a vendor NDK 3.2 installed on this machine: every
# structure size, field offset and constant value (layouts.py), and every
# call's offset, registers and prototype (compare_sfd.py). Writes the two
# reports to check/out/ and exits 1 if anything both have differs.
#   check/compare_ndk.sh NDK_DIR
# NDK_DIR holds the vendor's Include_H and SFD folders (on Daletop,
# ~/AmigaChrome/stoves/os32/ndk). The vendor's files are only read, never
# copied: check/out/ is ignored by git and keeps only names and numbers.
# CC must be an ELF m68k GCC (Ubuntu's m68k-linux-gnu-gcc, or the aros68k
# stove's); READELF any readelf.
set -eu
NDK=${1:?usage: compare_ndk.sh NDK_DIR}
HERE=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
OUT="$HERE/out"
mkdir -p "$OUT"
if [ -z "${CC:-}" ]; then
    for c in m68k-linux-gnu-gcc "$HOME"/AmigaChrome/stoves/aros68k-gcc16/prefix/bin/m68k-aros-gcc; do
        if command -v "$c" >/dev/null 2>&1; then CC=$c; break; fi
    done
fi
[ -n "${CC:-}" ] || { echo "no ELF m68k GCC: set CC=" >&2; exit 2; }
export CC
INC=$NDK/Include_H; [ -d "$INC" ] || INC=$NDK/include_h; [ -d "$INC" ] || INC=$NDK/include
SFD=$NDK/SFD; [ -d "$SFD" ] || SFD=$NDK/sfd
status=0
python3 "$HERE/layouts.py" dump "$HERE/../Include_H" "$OUT/openndk.json"
python3 "$HERE/layouts.py" dump "$INC" "$OUT/ndk.json"
python3 "$HERE/layouts.py" compare "$OUT/openndk.json" "$OUT/ndk.json" --report "$OUT/layouts.md" || status=1
if [ -d "$SFD" ]; then
    python3 "$HERE/compare_sfd.py" "$SFD" --report "$OUT/sfd.md" || status=1
fi
echo "reports: $OUT/layouts.md $OUT/sfd.md"
exit $status
