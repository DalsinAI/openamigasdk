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

- **Covered:** the AmigaOS 3.2 C headers listed above and SFDs for exec,
  dos, graphics, layers, intuition, utility, the other ROM and disk
  libraries, the devices and resources with calls, and the ReAction classes.
  Every SFD that has an open library behind it matches that library's
  `.lvo` table, which the library's own build checks against the vendor's.
- **Checked in the cloud** (`tests/run.sh`): every header compiles alone in C
  and C++, 90 structure sizes, a program's calls, and `libamiga.a`.
- **Not yet checked:** the field-by-field and constant-by-constant
  comparison with NDK 3.2 (`check/compare_ndk.sh`), which needs a machine
  that has the vendor NDK installed. Until it has run clean, treat a value
  in OpenNDK that no open library uses yet as unconfirmed.
- **Not yet written:** the assembler structure includes (`Include_I` other
  than `lvo/`), `debug.lib`, autodocs, vbcc's inline headers, and the OS 4.1
  headers (OS 4.1 builds keep using Hyperion's SDK for now).
