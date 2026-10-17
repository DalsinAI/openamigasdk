#!/bin/sh
# Probe: interface facts from the vendor NDK the stoves kept.
V=$HOME/AmigaChrome/stoves/os32-gcc16/prefix/m68k-amigaos/ndk-include.vendor
echo "== _va bodies"; grep -n -A12 '__NewObject_va\b' $V/inline/intuition.h | head -40
grep -n -B2 -A10 '^__CreateNewProcTags_va\|__CreateNewProcTags_va(' $V/inline/dos.h | head -30
echo "== va naming base"; grep -n 'INTUITION_BASE_NAME\|IntuitionBase' $V/inline/intuition.h | grep -v '#define [A-Z][A-Za-z0-9]*(' | head -20
echo "== pictureclass users"; grep -rln 'pictureclass.h' $V | head
echo "== icon/workbench includes"; grep -n '#include' $V/workbench/icon.h $V/workbench/workbench.h $V/clib/icon_protos.h $V/clib/wb_protos.h
echo "== stdargs"; grep -rn 'define __STDARGS__\|define BITMAPFLAGS_ARE_EXTENDED\|define __stdargs' $V | head
echo "== wa_Name"; grep -rn 'wa_Name' $V/workbench/startup.h; grep -n 'BYTE;\|typedef.*BYTE\b' $V/exec/types.h
echo "== PDHOOK"; grep -rn 'PDHOOK_' $V/devices/printer.h
echo "== bsdsocket"; wc -l $V/inline/bsdsocket.h $V/proto/bsdsocket.h $V/clib/bsdsocket_protos.h 2>&1; ls $V/../ndk/sfd 2>/dev/null | head; find $V/.. -maxdepth 3 -name 'bsdsocket*' | head
echo "== MEMF"; grep -n 'NO_EXPUNGE' $V/exec/memory.h
exit 0
