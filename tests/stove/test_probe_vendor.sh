#!/bin/sh
# Probe: the vendor NDK's STRPTR and string-pointer fields (names only).
V=$HOME/AmigaChrome/stoves/os32-gcc16/prefix/m68k-amigaos/ndk-include.vendor
cd $V && grep -rnE '^\s*(CONST_)?STRPTR\s*\**\s*[A-Za-z_][A-Za-z0-9_]*\s*(\[[^]]*\])?\s*;' --include=*.h . | sed -E 's|^\./([^:]*):[0-9]+:\s*((CONST_)?STRPTR\s*\**)\s*([A-Za-z0-9_]+).*|\1 \2 \4|' | tr -s ' \t' ' ' | sort -u
exit 0
