# The Open SDK: an OS 4 style program built for AmigaOS 3.2 with os4compat.
#   make -C ../../Lib/os4compat NDK=...   once, to build the kit
#   make                                  build/HelloOS4
SDK      ?= ../..
CC       ?= m68k-amigaos-gcc
CFLAGS   ?= -O2 -Wall -Wno-pointer-sign
include $(SDK)/Lib/os4compat/os4compat.mk

build/HelloOS4: hello_os4.c
	@mkdir -p build
	$(CC) -m68020 -noixemul $(CFLAGS) $(OS4COMPAT_CFLAGS) -o $@ hello_os4.c $(OS4COMPAT_LIBS)

clean:
	rm -rf build
.PHONY: clean
