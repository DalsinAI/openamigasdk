#!/bin/sh
# Probe: the stove's include search order and its extra-SDK folder.
P=$HOME/AmigaChrome/stoves/os32-gcc16/prefix
echo | $P/bin/m68k-amigaos-gcc -xc -E -v - 2>&1 | sed -n '/search starts/,/End of/p'
echo | $P/bin/m68k-amigaos-g++ -xc++ -E -v - 2>&1 | sed -n '/<...> search starts/,/End of/p'
echo "== include/"; find $P/m68k-amigaos/include -maxdepth 2 | sed "s|$P/m68k-amigaos/include/||" | head -60
cat $P/m68k-amigaos/include/EXTRA-SDKS.txt
echo "== sys-include sys"; ls $P/m68k-amigaos/sys-include/sys | head -50
V=$P/m68k-amigaos/ndk-include.vendor
echo "== amitcp etc heads"; for f in pwd.h resolv.h amitcp/*.h; do echo "-- $f"; head -6 $V/$f | tr -d '\r'; done 2>&1 | head -40
exit 0
