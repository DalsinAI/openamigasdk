#!/bin/sh
# throwaway: interface facts from the stove's vendor trackfile.h
V=$HOME/AmigaChrome/stoves/os32-gcc16/prefix/m68k-amigaos/ndk-include.vendor
grep -n "#include\|#define[ \t]*[A-Z_]*NAME" $V/devices/trackfile.h
exit 0
