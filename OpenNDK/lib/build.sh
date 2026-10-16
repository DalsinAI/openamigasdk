#!/bin/sh
# Copyright (c) 2026 AmigaChrome Team. MIT licence (see OpenNDK/LICENSE).
# Builds OpenNDK's libamiga.a: a stub for every public call in SFD/ (each
# a real function that loads the base and jumps through it, for compilers
# and code that don't use the inline headers, and the varargs forms such
# as OpenWindowTags), plus the helpers in alib/.
#   lib/build.sh                 with the os32-gcc16 stove (m68k-amigaos-)
#   PREFIX=m68k-linux-gnu- lib/build.sh   with an ELF m68k GCC (cloud tests)
# Output: lib/build/<prefix>/libamiga.a
set -eu
NDK=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
STOVE=${STOVE:-"$HOME/AmigaChrome/stoves/os32-gcc16"}
if [ -z "${PREFIX:-}" ]; then
    if [ -x "$STOVE/prefix/bin/m68k-amigaos-gcc" ]; then
        PREFIX="$STOVE/prefix/bin/m68k-amigaos-"
    else
        PREFIX=m68k-amigaos-
    fi
fi
CC=${CC:-${PREFIX}gcc}
AR=${AR:-${PREFIX}ar}
OUT="$NDK/lib/build/$(basename -- "$PREFIX" | sed 's/-$//')"
rm -rf "$OUT"
mkdir -p "$OUT/stubs" "$OUT/obj"
python3 "$NDK/tools/ndkgen.py" --out "$OUT/gen" --stubs "$OUT/stubs" "$NDK"/SFD/*.sfd >/dev/null
# -nostdinc keeps the vendor NDK out even when the compiler was set up with
# one; the compiler's own include folder still gives stdarg.h
CFLAGS="-nostdinc -isystem $($CC -print-file-name=include) -I$NDK/Include_H
  -O2 -m68000 -fomit-frame-pointer -fno-builtin -Wall -Wextra -Werror
  -Wno-unused-parameter ${EXTRA_CFLAGS:-}"
n=0
for src in "$OUT"/stubs/*.c "$NDK"/lib/alib/*.c "$NDK"/lib/alib/*.S; do
    obj="$OUT/obj/$(basename "$src" | sed 's/\.[cS]$/.o/')"
    # shellcheck disable=SC2086
    "$CC" $CFLAGS -c "$src" -o "$obj"
    n=$((n + 1))
done
rm -f "$OUT/libamiga.a"
"$AR" rcs "$OUT/libamiga.a" "$OUT"/obj/*.o
echo "$OUT/libamiga.a: $n objects"
