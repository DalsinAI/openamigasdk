#!/bin/sh
# Probe: interface facts from the vendor NDK the stoves kept.
V=$HOME/AmigaChrome/stoves/os32-gcc16/prefix/m68k-amigaos/ndk-include.vendor
echo "== compiler-specific"; grep -n '^ *# *\(if\|ifdef\|ifndef\|elif\|else\|endif\|define\|include\)' $V/clib/compiler-specific.h
echo "== types.h strings"; grep -n 'STRPTR\|TEXT\|compiler-specific\|__cplusplus' $V/exec/types.h
echo "== roadshow files"; cd $V && for f in $(find . -name '*.h' | sort); do head -15 "$f" | grep -qi 'roadshow' && echo "$f"; done
echo "== non-roadshow folders"; ls $V
exit 0
