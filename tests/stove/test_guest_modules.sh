#!/bin/sh
# Copyright (c) 2026 AmigaChrome Team. MIT licence (see OpenNDK/LICENSE).
# Builds every amigachrome-guest module (each build-amiga.sh) twice with the
# os32-gcc16 stove: once against the vendor NDK the stove kept
# (ndk-include.vendor) and once against this checkout's OpenNDK, and lists
# each module that builds with the first but not the second, with its first
# errors. The live stove is not changed: each pass runs through a stove of
# links whose compilers put the chosen include folder first.
#   GUEST=/path/to/amigachrome-guest  (default: Cradle's checkout, its HEAD)
#   ONLY="libraries/opendos devices/opentimer.device"  (default: every module)
# Exits 1 if a module builds with the vendor NDK and not with OpenNDK.
set -u
HERE=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
REAL=${STOVE:-"$HOME/AmigaChrome/stoves/os32-gcc16"}
SRC=${GUEST:-"$HOME/AmigaChrome-dev/cradle-builds/DalsinAI__amigachrome-guest"}
JOBS=${JOBS:-6}
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT

fake_stove() { # $1 name, $2 include folder
    s="$tmp/stove-$1"
    mkdir -p "$s/prefix/bin"
    for e in "$REAL/prefix"/*; do [ "$(basename "$e")" = bin ] || ln -s "$e" "$s/prefix/"; done
    for b in "$REAL/prefix/bin"/*; do
        n=$(basename "$b")
        case $n in
        *-gcc|*-g++|*-c++|*-cpp)
            printf '#!/bin/sh\nexec "%s" -isystem "%s" "$@"\n' "$b" "$2" > "$s/prefix/bin/$n"
            chmod +x "$s/prefix/bin/$n" ;;
        *) ln -s "$b" "$s/prefix/bin/$n" ;;
        esac
    done
}
fake_stove vendor "$REAL/prefix/m68k-amigaos/ndk-include.vendor"
fake_stove openndk "$HERE/OpenNDK/Include_H"
[ -d "$REAL/prefix/m68k-amigaos/ndk-include.vendor" ] || { echo "no vendor NDK kept in $REAL"; exit 2; }

for m in vendor openndk; do
    git clone -q --shared "$SRC" "$tmp/guest-$m" || exit 2
done
echo "guest at $(git -C "$tmp/guest-vendor" log --oneline -1), OpenNDK at $(git -C "$HERE" log --oneline -1)"
if [ -n "${ONLY:-}" ]; then targets=$ONLY; else
    targets=$(cd "$tmp/guest-vendor" && find . -name build-amiga.sh -not -path './.git/*' | sed 's|^\./||;s|/build-amiga.sh$||' | sort)
fi
mkdir -p "$tmp/log"
for m in vendor openndk; do
    for t in $targets; do echo "$m $t"; done
done > "$tmp/list"
cat > "$tmp/one.sh" <<SH
#!/bin/sh
m=\$1; t=\$2; k=\$(echo "\$m-\$t" | tr / _)
cd "$tmp/guest-\$m/\$t" || exit 0
if STOVE="$tmp/stove-\$m" OUT="$tmp/out/\$k" timeout 600 sh ./build-amiga.sh > "$tmp/log/\$k" 2>&1; then echo ok > "$tmp/log/\$k.rc"; else echo fail > "$tmp/log/\$k.rc"; fi
SH
xargs -P "$JOBS" -L 1 sh "$tmp/one.sh" < "$tmp/list"

bad=0; both=0; good=0; vend=""
for t in $targets; do
    k=$(echo "$t" | tr / _)
    v=$(cat "$tmp/log/vendor-$k.rc" 2>/dev/null || echo none)
    o=$(cat "$tmp/log/openndk-$k.rc" 2>/dev/null || echo none)
    if [ "$o" = ok ]; then good=$((good+1)); [ "$v" = ok ] || vend="$vend $t"
    elif [ "$v" = ok ]; then
        bad=$((bad+1)); echo "== $t: builds with the vendor NDK, not with OpenNDK"
        grep -m 12 -E 'error|undefined reference|In file included|fatal' "$tmp/log/openndk-$k" | sed "s|$tmp/guest-openndk/||g;s|$HERE/||g"
    else both=$((both+1)); echo "-- $t: fails with both:"; grep -m 3 -E 'error|undefined|fatal|not' "$tmp/log/vendor-$k" | sed "s|$tmp/guest-vendor/||g"
    fi
done
[ -z "$vend" ] || echo "builds with OpenNDK only:$vend"
echo "summary: $good build with OpenNDK, $bad only with the vendor NDK, $both with neither"
[ $bad -eq 0 ]
