# The Open SDK: an OS 4 style program built for AmigaOS 3.2 with os4compat.
#   make -C ../../Lib/os4compat NDK=...   once, to build the kit
#   make                                  build/HelloOS4
SDK      ?= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))../..)
CC       ?= m68k-amigaos-gcc
# -fno-delete-null-pointer-checks: address 0 is memory on an Amiga; without it GCC
# puts TRAP #7 (Software Failure 80000027) where it proves a pointer null.
CFLAGS   ?= -O2 -fno-delete-null-pointer-checks -Wall -Wno-pointer-sign
include $(SDK)/Lib/os4compat/os4compat.mk

build/HelloOS4: hello_os4.c
	@mkdir -p build
	$(CC) -m68040 -noixemul $(CFLAGS) $(OS4COMPAT_CFLAGS) -o $@ hello_os4.c $(OS4COMPAT_LIBS)

clean:
	rm -rf build
.PHONY: clean
