#!/bin/sh
# Probe: where the vendor NDK uses the timeval switches (interface facts only).
V=$HOME/AmigaChrome/stoves/os32-gcc16/prefix/m68k-amigaos/ndk-include.vendor
grep -rn 'TimeVal_Type\|TimeRequest_Type\|__USE_NEW_TIMEVAL__\|_TIMEVAL_DEFINED\|__TIME_TYPES_DEFINED__' $V | sed "s|$V/||"
echo ==; grep -rln 'struct timeval\|struct TimeVal\|struct timerequest' $V | sed "s|$V/||"
echo ==; sed -n '72,116p' $V/devices/timer.h | grep -v '^ \*\|^/\*'
exit 0
