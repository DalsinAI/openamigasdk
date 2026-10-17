#!/bin/sh
# Copyright (c) 2026 AmigaChrome Team. MIT licence (see OpenNDK/LICENSE).
# OpenNDK's own tests, with no vendor NDK anywhere:
#   1. every generated file is up to date with its SFD
#   2. every header compiles on its own, in C and C++
#   3. the structure sizes in sizes.c, and every field's offset in the
#      structures tests/layout.list names (layout.c)
#   4. a program built with the proto/ headers makes the calls it should
#   5. libamiga.a builds
#   6. with GUEST=<amigachrome-guest checkout> (and GFX=<openamigagfx>),
#      every SFD matches the open libraries' .lvo tables
# Needs an m68k cross GCC (Ubuntu: gcc-m68k-linux-gnu g++-m68k-linux-gnu).
set -eu
NDK=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
CC=${M68K_CC:-m68k-linux-gnu-gcc}
OBJDUMP=${M68K_OBJDUMP:-m68k-linux-gnu-objdump}
T=$(mktemp -d)
trap 'rm -rf "$T"' EXIT

echo "== generated files"
python3 "$NDK/tools/ndkgen.py" --check "$NDK"/SFD/*.sfd
cp "$NDK/Include_H/inline/macros.h" "$T/macros.h"
python3 "$NDK/tools/mkmacros.py"
cmp -s "$T/macros.h" "$NDK/Include_H/inline/macros.h" || { echo "inline/macros.h is stale: run tools/mkmacros.py"; exit 1; }

echo "== headers"
"$NDK/tests/compile_headers.sh"

FLAGS="-nostdinc -isystem $($CC -print-file-name=include) -idirafter $NDK/check/shim -I$NDK/Include_H -m68040 -O2 -fomit-frame-pointer -Wall -Wextra -Werror"
echo "== all headers in one unit"
# every header at once: two headers defining one name differently show here
# (the IEEE math headers rename the same functions as mathffp.h, as they
# always have, so only one of the three goes in a program)
(cd "$NDK/Include_H" && find . -name '*.h' ! -path './pragmas/*' ! -name 'mathieeedp.h' ! -name 'mathieeesp.h' | sed 's|^\./||' | sort |
    sed 's/.*/#include <&>/') > "$T/all.c"
# shellcheck disable=SC2086
"$CC" $FLAGS -std=gnu11 -fsyntax-only "$T/all.c"
echo "one unit ok"

echo "== sizes"
# shellcheck disable=SC2086
"$CC" $FLAGS -std=gnu11 -fsyntax-only "$NDK/tests/sizes.c"
echo "sizes ok"

echo "== layouts"
# every field's offset in tests/layout.list's structures, as 3.2 has them
# (check/layout_numbers.py); struct ClipRect both with and without Flags
# shellcheck disable=SC2086
"$CC" $FLAGS -std=gnu11 -fsyntax-only "$NDK/tests/layout.c"
# shellcheck disable=SC2086
"$CC" $FLAGS -std=gnu11 -fsyntax-only -DNEWCLIPRECTS_1_1 "$NDK/tests/layout.c"
echo "layouts ok"

echo "== a program"
# shellcheck disable=SC2086
# address 4 holds SysBase: GCC must not treat low addresses as invalid
"$CC" $FLAGS --param=min-pagesize=0 -c "$NDK/tests/hello.c" -o "$T/hello.o"
"$OBJDUMP" -dr "$T/hello.o" > "$T/hello.dis"
for want in 'jsr %fp@\(-552\)|jsr -552\(%fp\)|jsr %a6@\(-552\)' 'jsr %a6@\(-948\)|jsr %fp@\(-948\)' 'jsr %a6@\(-342\)|jsr %fp@\(-342\)' 'OpenWindowTags'; do
    grep -Eq "$want" "$T/hello.dis" || { echo "hello.o lacks $want"; sed -n 1,80p "$T/hello.dis"; exit 1; }
done
echo "program ok"

echo "== libamiga.a"
PREFIX=${M68K_PREFIX:-m68k-linux-gnu-} sh "$NDK/lib/build.sh"

if [ -n "${GUEST:-}" ]; then
    echo "== SFDs against the .lvo tables"
    python3 "$NDK/check/check_lvo.py" --guest "$GUEST" ${GFX:+--gfx "$GFX"}
fi
echo "all OpenNDK tests passed"
