#!/bin/sh
# Probe: the vendor NDK's function-pointer fields (interface facts only).
V=$HOME/AmigaChrome/stoves/os32-gcc16/prefix/m68k-amigaos/ndk-include.vendor
for f in exec/interrupts.h exec/tasks.h libraries/commodities.h resources/mathresource.h utility/hooks.h hardware/blit.h devices/prtbase.h graphics/graphint.h graphics/gfxnodes.h graphics/monitor.h; do
  echo "== $f"; grep -n '(\s*\*\|( *__[a-z]* *\*\|(\* *[A-Z_]*\s' $V/$f | tr -s ' \t' ' '
done
grep -n 'CS_Buffer' $V/dos/rdargs.h
grep -rn 'define __stdargs\|define PRT_STDARGS\|define __ASM_STDARGS\|ASM_CALL\|define REGARGS' $V/exec/*.h $V/devices/prtbase.h $V/clib/compiler-specific.h | head
exit 0
