#!/bin/sh
# Probe: interface facts from the vendor NDK the stoves kept (*.vendor).
V=$HOME/AmigaChrome/stoves/os32-gcc16/prefix/m68k-amigaos/ndk-include.vendor
echo "== proto bases"; for f in $V/proto/*.h; do printf '%s ' "$(basename $f)"; awk '/^ *extern struct/ && !/IFace/ {t=$0; getline; print t, $0; exit}' $f | tr -s ' \t' ' '; echo; done
echo "== vararg dos"; grep -n -B1 -A8 'define CreateNewProcTags\|define Printf\b\|define Printf(' $V/inline/dos.h | head -40
grep -n -A6 'NO_INLINE_STDARG\|NO_INLINE_VARARGS' $V/inline/dos.h | head -20
echo "== vararg intuition"; grep -n -A5 'define OpenWindowTags\|define NewObject\b\|define NewObject(\|define SetWindowPointer(' $V/inline/intuition.h | head -40
echo "== intuition.h includes"; grep -n '#include' $V/intuition/intuition.h $V/intuition/screens.h $V/devices/inputevent.h
echo "== RefreshDTObjects"; grep -n 'RefreshDTObjects' $V/clib/datatypes_protos.h
echo "== ColorRegister"; grep -rln 'struct ColorRegister *{\|^struct ColorRegister' $V; grep -rn 'InstallClipRegion' $V/clib/*.h
echo "== includes of protos"; for f in datatypes graphics intuition dos layers; do echo "$f:"; grep -n '#include' $V/clib/${f}_protos.h; done
echo "== adtFrame"; grep -rn 'struct adtFrame\|struct adtNewFormatFrame' $V | head
exit 0
