# The Open SDK

One kit for one platform to build and port towards and from: headers, function tables, link libraries, autodocs, examples and ACKitchen templates for every Open library. We, 4 October 2026: "one 'platform' to build and port towards and from".

Status, 6 October 2026: phase 1 in progress. The headers and function tables of what exists today (openrtg.library, opensocket.library, accontrol.device, oapspool.device), gathered at pinned commits by `tools/gather.py` from `manifest.json`, plus a Shell command template and a GadTools template. `Docs/PORTING.md` is where to start; `DESIGN.md` is the design.

Also: **OpenNDK** (`OpenNDK/`), our own native developer kit for 68k
AmigaOS 3.x: the C headers, SFD and FD files, proto, inline and pragma
headers, LVO includes and `libamiga.a`, written clean-room, so the open
libraries and third-party software build without the vendor NDK.

Also: **os4compat** (`Lib/os4compat`, `Docs/PORTING-OS4.md`), which builds
AmigaOS 4 source for OS 3.2 by giving each library OS 4's interfaces and
adding the OS 4 calls OS 3.2 lacks.

Part of the Open family (internally, the Great Open Source Reunification
Project): one platform, AmigaOS 3.2.x with the Open libraries, that is easy
to set up, and to build and port for.

## Licence

MIT, Copyright (c) 2026 Dalsin Limited (`LICENSE`), for our own files.
Third-party code keeps its own licence (see `DESIGN.md`).

If you use or build on this work, we ask (we do not require) that you credit
Dalsin Limited and AmigaChrome, for example "based on The Open SDK by Dalsin
Limited".

## Contributors

The Open SDK is created and maintained by [SacredTrees](https://github.com/SacredTrees) with the AmigaChrome agent team, copyright Dalsin Limited. Everyone whose work it includes is credited in [`CONTRIBUTORS.md`](CONTRIBUTORS.md).
