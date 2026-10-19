#!/usr/bin/env python3
# Copyright (c) 2026 AmigaChrome Team. The Open SDK, MIT licence (LICENSE).
# SPDX-License-Identifier: MIT
"""Gather the SDK's headers and function tables from each library's repository.

    tools/gather.py            fetch each part at its pinned commit and copy its files
    tools/gather.py --check    the same, but only say whether the copies here match

manifest.json names each part's repository, commit and files. The FD files
are made from the SFD files, so there is one source for each function table.
"""
import json, os, subprocess, sys, tempfile, shutil

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def fetch(repo, commit, cache):
    d = os.path.join(cache, repo.replace("/", "_"))
    if not os.path.isdir(os.path.join(d, ".git")):
        subprocess.run(["git", "init", "-q", d], check=True)
        subprocess.run(["git", "-C", d, "remote", "add", "origin", f"https://github.com/{repo}"], check=True)
    subprocess.run(["git", "-C", d, "fetch", "-q", "--depth", "1", "origin", commit], check=True)
    subprocess.run(["git", "-C", d, "checkout", "-q", "--force", commit], check=True)
    return d


def sfd_to_fd(sfd):
    """An FD file from an SFD file: ##base, ##bias, ##public and one line a function."""
    out, base = [], None
    for line in sfd.splitlines():
        s = line.strip()
        if s.split()[:1] == ["==base"]:
            base = s.split()[1]
            out.append(f"##base {base}")
        elif s.startswith("==bias"):
            out.append(f"##bias {s.split()[1]}")
        elif s in ("==public", "==private"):
            out.append("##" + s[2:])
        elif s == "==end":
            out.append("##end")
        elif s and not s.startswith(("==", "*")):
            # "ULONG Name(ULONG a, ULONG b)(d0,d1)" -> "Name(a,b)(d0,d1)"
            head, regs = s.rsplit(")(", 1)
            ret_name, args = head.split("(", 1)
            name = ret_name.split()[-1].lstrip("*")
            names = [a.strip().split()[-1].lstrip("*") for a in args.split(",") if a.strip()]
            out.append(f"{name}({','.join(names)})({regs}")
    return "\n".join(out) + "\n"


def main():
    check = "--check" in sys.argv
    manifest = json.load(open(os.path.join(ROOT, "manifest.json")))
    cache = os.environ.get("OPENSDK_CACHE") or os.path.join(tempfile.gettempdir(), "opensdk-cache")
    os.makedirs(cache, exist_ok=True)
    stale = []
    for part in manifest["parts"]:
        src = fetch(part["repo"], part["commit"], cache)
        for frm, to in part["files"].items():
            data = open(os.path.join(src, frm), "rb").read()
            outs = [(to, data)]
            # OpenNDK's own tools/ndkgen.py makes its FD and the rest
            if to.endswith(".sfd") and not to.startswith("OpenNDK/"):
                fd = sfd_to_fd(data.decode("latin-1")).encode("latin-1")
                outs.append(("FD/" + os.path.basename(to)[:-4] + ".fd", fd))
            for path, body in outs:
                dst = os.path.join(ROOT, path)
                have = open(dst, "rb").read() if os.path.exists(dst) else None
                if have != body:
                    stale.append(path)
                    if not check:
                        os.makedirs(os.path.dirname(dst), exist_ok=True)
                        open(dst, "wb").write(body)
        print(f"{part['name']}: {part['repo']} {part['commit'][:7]}")
    if check and stale:
        print("out of date: " + ", ".join(stale))
        return 1
    print("up to date" if check else f"{len(stale)} file(s) written")
    return 0


if __name__ == "__main__":
    sys.exit(main())
