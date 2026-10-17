#!/bin/sh
# Probe: interface facts from the vendor NDK the stoves kept.
V=$HOME/AmigaChrome/stoves/os32-gcc16/prefix/m68k-amigaos/ndk-include.vendor
echo "== global-base va"; grep -n '^#define [A-Za-z0-9_]* __[A-Za-z0-9_]*_va *$' $V/inline/*.h | sed "s|$V/||"
echo "== types.h"; sed -n 60,130p $V/exec/types.h | grep -n '#\|typedef'
echo "== who includes compiler-specific"; grep -rln 'compiler-specific.h' $V | sed "s|$V/||" | head
echo "== consts"; grep -rn 'CACRF_CopyBack\|HUNKF_FAST\|define BMF_CHECK' $V/exec/execbase.h $V/dos/doshunks.h $V/graphics/gfx.h
echo "== bsdsocket protos"; grep -v '^ *$' $V/clib/bsdsocket_protos.h | grep -v '^/\*\|^ \*'
echo "== bsdsocket jsr"; awk '/^#define __[A-Za-z0-9_]*_base\(/ {n=$2} /jsr/ {print n, $0} /register .* __asm\("[ad][0-7]"\) = __p/ {print n, $0}' $V/inline/bsdsocket.h | tr -s ' '
echo "== bsdsocket proto"; cat $V/proto/bsdsocket.h | grep -v '^ *$'
echo "== libraries/bsdsocket.h head"; grep -n '#include\|^struct\|#define SBTC\|#define SBTF' $V/libraries/bsdsocket.h | head -40
exit 0
