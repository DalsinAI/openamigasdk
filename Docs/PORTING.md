# Building for the Open platform

The Open platform is AmigaOS 3.2.x with the Open libraries. The same sources
build for AROS 68k, as two separate binaries from one source, with no
`#ifdef` maze.

## Start from a template

| Template | What you get |
| --- | --- |
| `Templates/shell-command` | A Shell command with ReadArgs, Ctrl-C and a version string |
| `Templates/gadtools-app` | A font-sensitive GadTools window with a menu, keys and a status line, following the Open apps' rules |

Copy the drawer, rename the program, then run `make`. That gives you
`build/<Name>.os32` and `build/<Name>.aros`. ACKitchen sets `CC_OS32` and
`CC_AROS` to its stoves. Elsewhere, put `m68k-amigaos-gcc` (bebbo's, with
NDK 3.2) and `m68k-aros-gcc` on your PATH.

## The platform's rules

- **Set FPCR to 0 when doubles matter.** OS 3.2.3's ROM `mathieeesingbas`
  sets single precision in each task that opens it, so a program that needs
  double precision sets FPCR itself.
- **Give a big program its own stack** with `StackSwap`, because libnix
  ignores `__stack`.
- **Build libraries with `-fno-common`**, so library bases aren't merged.
- **Never require an accelerator.** Every Open library works on a real
  68040 with no Cradle. OpenGPU always has its CPU back end, and a feature
  that needs the services card says so in words.
- **Use published interfaces only:** OS 4's RTG calls by name, the standard
  bsdsocket numbers, MUI's function table through Zune and AROS's GLA calls.

## What's in this SDK (0.1)

| Part | Headers | Function table |
| --- | --- | --- |
| openrtg.library 0.10 | `openrtg/openrtg.h`, `openrtg/modes.h`, `proto/`, `inline/` | `SFD/openrtg_lib.sfd`, `FD/openrtg_lib.fd` |
| opensocket.library | `acnetwork.h`, `proto/acnetwork.h`, `opensocket/acnet_socket_tags.h` | in the proto header |
| accontrol.device | `accontrol/accontrol.h` | device commands |
| oapspool.device | `openprint/oap_device.h` | device commands |

`manifest.json` lists the commit each part comes from, and
`tools/gather.py --check` says whether the copies here still match.
