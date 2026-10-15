# OpenNDK

An open native developer kit for 68k AmigaOS 3.x: the C headers, function
tables and link library a program needs to build, written from the
published interface and owned by the Team. It sits in The Open SDK beside
the Open libraries' own headers, so the open libraries, the boot-disk
commands and third-party software can be built with no vendor NDK.

MIT, Copyright (c) 2026 DalsinAI. What it may and may not be written from
is in [CLEAN-ROOM.md](CLEAN-ROOM.md); how to add to it is in
[CONTRIBUTING.md](CONTRIBUTING.md).

## What's in it

| Folder | Holds |
| --- | --- |
| `Include_H/` | The C headers, under the OS's own paths (`exec/`, `dos/`, `graphics/`, `intuition/`, `utility/`, `libraries/`, `devices/`, `hardware/`, `resources/`, `workbench/`, `datatypes/`, `rexx/`, `diskfont/`, `prefs/`, and ReAction's `gadgets/`, `images/`, `classes/` and `reaction/`) |
| `Include_H/proto/`, `clib/`, `inline/`, `pragmas/` | Generated from the SFDs: the header a program includes, the prototypes, GCC inline calls and SAS/C-style pragmas. `inline/macros.h` gives the LPn macros for hand-written inline headers |
| `Include_I/lvo/` | Generated `_LVO` equates for assembler |
| `SFD/`, `FD/` | Each library's calls: the SFDs are written by hand, the FDs generated |
| `lib/` | `libamiga.a`: a stub for every call (including the varargs forms such as `OpenWindowTags`) and the classic helpers (`NewList`, `CreatePort`, `CreateExtIO`, `CreateTask`, `BeginIO`, `DoMethod` and the other BOOPSI helpers, `HookEntry`, `CallHook`, `FastRand`, `RangeRand`, the `Lib*Pool` calls, `TimeDelay`, `ArgArrayInit` and friends, `HotKey`) |
| `tools/` | `ndkgen.py`, the generator; `mkmacros.py` for `inline/macros.h` |
| `tests/` | `run.sh`: the cloud tests, needing only an m68k GCC |
| `check/` | `compare_ndk.sh`: the full comparison with a vendor NDK where one is installed; `check_lvo.py`: the SFDs against the open libraries' `.lvo` tables |

The layout follows the vendor NDK's (`Include_H`, `Include_I`, `SFD`,
`FD`), so a stove can point at OpenNDK where it pointed at `ndk/`.

## Using it

With the os32-gcc16 stove (GCC 16 for m68k-amigaos):

```sh
sh OpenNDK/lib/build.sh                     # makes lib/build/<prefix>/libamiga.a
m68k-amigaos-gcc -nostdinc -isystem "$(m68k-amigaos-gcc -print-file-name=include)" \
    -I OpenNDK/Include_H -O2 -fomit-frame-pointer -c prog.c
```

`-nostdinc` keeps a vendor NDK installed in the compiler's own search path
out. A C library (libnix, clib2) brings its own `stdio.h` and friends:
put its include folder after OpenNDK's.

The inline calls bind the library base to `a6`, so code using them needs
a frame pointer other than `a6`: `-fomit-frame-pointer`, or the amigaos
GCC's default (`a5`). A call's base can be swapped by defining
`<LIBRARY>_BASE_NAME` (for example `INTUITION_BASE_NAME`) before including
its `proto/` header, and `__NOLIBBASE__` leaves out the base's declaration.
`__OPENNDK_NO_INLINE__` uses the stubs in `libamiga.a` instead of inlines.

## Status, 15 October 2026

- **Written:** 209 C headers in the OS's own paths and 77 SFDs: exec, dos,
  graphics, layers, intuition, utility, gadtools, asl, icon, workbench,
  expansion, the other disk libraries (amigaguide, commodities, datatypes,
  diskfont, iffparse, keymap, locale, lowlevel, the six math libraries,
  nonvolatile, realtime, rexxsyslib, translator, bullet), the devices and
  resources with calls, and the ReAction classes. With the generated files,
  519 headers in all.
- **Checked here** (`tests/run.sh`, about 20 minutes): every header compiles
  alone in C and C++ and all together in one unit; 89 structure sizes that
  the open libraries' own tests measured against NDK 3.2; a program's calls;
  `libamiga.a` (1,278 objects). 73 SFDs match the open libraries' `.lvo`
  tables with no difference; icon, workbench, input and translator have no
  table to compare with yet.
- **Checked against NDK 3.2** (`check/compare_ndk.sh`, first run on Daletop
  15 October; reports in `check/results/`): four exec alert codes, the
  types of 34 calls, `listbrowser.gadget`'s column-info registers,
  `UpdateWorkbench` and `texteditor.gadget`'s base name were corrected from
  it. That run read only part of the NDK (its headers did not compile with
  Ubuntu's GCC, and its multi-line SFDs were not read), so the compare now
  measures both header sets with the os32 stove's GCC and reads every SFD.
  Until its next run is clean, treat a value in OpenNDK that no open
  library uses yet as unconfirmed. Still open: `WA_` tags from
  `WA_WindowName` on, `PDTA_ModeID` and the picture tags (200 or 201),
  datebrowser's three Julian calls, `texteditor.gadget`'s
  `HighlightSetFormat`, the `listview` and `trackfile` SFDs,
  `dos/ansiio.h` and `resources/ciabase.h`. OpenNDK keeps
  `struct timeval` in timer's calls and `struct DiscResourceUnit` in
  `GetUnit`, which the NDK's SFDs name differently; both are the same
  layout.
- **Not yet written:** the assembler structure includes (`Include_I` other
  than `lvo/`), `debug.lib`, autodocs, vbcc's inline headers,
  `gadgets/sketchboard.h` and `piechart.h`, and the OS 4.1 headers (OS 4.1
  builds keep using Hyperion's SDK for now).
