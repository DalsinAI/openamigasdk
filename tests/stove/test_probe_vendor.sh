#!/bin/sh
# Probe: the vendor NDK's varargs wrappers (interface facts only).
V=$HOME/AmigaChrome/stoves/os32-gcc16/prefix/m68k-amigaos/ndk-include.vendor
for f in intuition dos; do echo "== $f"; grep -n -B3 -A14 '__NewObject_va\b\|^__CreateNewProcTags_va\|__CreateNewProcTags_va(' $V/inline/$f.h | head -60; done
echo "== wrappers naming a base inside"; for f in $V/inline/*.h; do awk -v F=$(basename $f) '/_va\(/ && /^[a-zA-Z_].*\(/ {inf=1; n=$0} inf && /BASE_NAME/ {print F": "n; inf=0} /^}/ {inf=0}' $f; done | sort | uniq -c | sort -rn | head -40
echo "== count _va defs"; grep -c '_va(' $V/inline/intuition.h
exit 0
