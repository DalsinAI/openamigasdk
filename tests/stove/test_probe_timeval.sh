#!/bin/sh
# Probe: preprocessor guard lines around struct timeval (interface facts only).
P=$HOME/AmigaChrome/stoves/os32-gcc16/prefix/m68k-amigaos
for f in $P/sys-include/sys/_timeval.h; do echo "== $f"; grep -n '^[ 	]*#' "$f"; done
for d in $P/ndk-include.vendor $P/ndk-include*; do [ -f "$d/devices/timer.h" ] && { echo "== $d/devices/timer.h"; grep -n '^[ 	]*#\|timeval\|TimeVal' "$d/devices/timer.h"; }; done
ls -d $P/ndk* 
exit 0
