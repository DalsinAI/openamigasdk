#!/bin/sh
# Probe: interface facts from the vendor NDK the stoves kept (*.vendor).
P=$HOME/AmigaChrome/stoves/os32-gcc16/prefix/m68k-amigaos
V=$P/ndk-include.vendor
echo "== proto bases"; grep -h '^ *extern.*Base' $V/proto/*.h | sort | uniq -c | sort -rn | head -80
echo "== proto/dos.h"; grep -v '^ *$' $V/proto/dos.h | head -40
echo "== inline/dos.h head"; sed -n 1,30p $V/inline/dos.h
echo "== inline/dos.h UnLock"; grep -n -A12 'define UnLock' $V/inline/dos.h | head -20
echo "== _base names"; grep -ho '__[A-Za-z]*_base\b' $V/inline/*.h | sort -u | head; grep -lc '_base(' $V/inline/*.h | wc -l
grep -n -B2 -A10 'ObtainConfigBinding' $V/inline/expansion.h | head -30
echo "== macros.h"; ls $V/inline/macros.h $P/include/inline/macros.h 2>&1; grep -n 'define LP0\b\|define LP1(\|define LP10(' -A12 $V/inline/macros.h $P/include/inline/macros.h 2>/dev/null | head -60
echo "== stove include/inline"; ls $P/include/inline | head -50; ls -la $P/include | head
echo "== ie_X"; grep -rn 'ie_X\|ie_TimeStamp' $V/devices/inputevent.h $V/intuition/*.h | head
echo "== PDTA"; grep -n 'PDTA_ModeID\|define DTA_Dummy\|define PDTA_Dummy' $V/datatypes/*.h | head
echo "== WA"; grep -n 'WA_SizeGadget\|WA_Dummy\b\|define WA_Left' $V/intuition/intuition.h | head
echo "== TFERROR"; grep -rn 'TFERROR' $V | head -5
echo "== SecLabel"; grep -rn 'iotd_SecLabel' $V | head
echo "== libamiga"; for l in $P/lib/libamiga.a* $P/libnix/lib/libamiga.a*; do [ -e "$l" ] && { echo $l; m68k-amigaos-nm 2>/dev/null; $P/../bin/m68k-amigaos-nm $l 2>/dev/null | grep -c ' T '; $P/../bin/m68k-amigaos-nm $l 2>/dev/null | grep ' T _\(CreateNewProcTags\|OpenWindowTags\|NewObject\|SetWindowPointer\)$'; }; done
echo "== bsdsocket"; find $P -name bsdsocket.h | head
exit 0
