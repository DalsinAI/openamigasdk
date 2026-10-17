#!/bin/sh
# Probe: the vendor NDK's function-pointer fields (interface facts only).
V=$HOME/AmigaChrome/stoves/os32-gcc16/prefix/m68k-amigaos/ndk-include.vendor
sed -n '48,78p' $V/graphics/monitor.h | sed 's|/\*.*\*/||' | tr -s ' \t' ' '
sed -n '186,191p' $V/graphics/monitor.h | sed 's|/\*.*\*/||'
sed -n '186,192p;262,268p' $V/devices/prtbase.h | sed 's|/\*.*\*/||'
grep -n 'include\|PRT_STDARGS' $V/devices/prtbase.h | head
exit 0
