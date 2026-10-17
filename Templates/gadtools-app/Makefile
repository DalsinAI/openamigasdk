# The Open SDK: a GadTools program for AmigaOS 3.2 and AROS, two binaries.
#   make            both
#   make os32       build/HelloWindow.os32 (bebbo's m68k-amigaos-gcc, NDK 3.2)
#   make aros       build/HelloWindow.aros (m68k-aros-gcc)
# ACKitchen sets CC_OS32 and CC_AROS to its stoves; SDK points at this SDK.
# The OS 3.2 build is soft float (-m68040, no -m68881): one binary for 68040s
# with or without an FPU. SPECS keeps its link on libnix's soft maths.
NAME     ?= HelloWindow
SRC      ?= hellowindow.c
SDK      ?= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))../..)
SPECS    ?= $(abspath $(SDK)/Lib/m68k-soft-m68040.specs)
CC_OS32  ?= m68k-amigaos-gcc
CC_AROS  ?= m68k-aros-gcc
# -fno-delete-null-pointer-checks: address 0 is memory on an Amiga; without it GCC
# puts TRAP #7 (Software Failure 80000027) where it proves a pointer null.
CFLAGS   ?= -O2 -fno-delete-null-pointer-checks -Wall -Wextra -Wno-pointer-sign

all: os32 aros
os32: build/$(NAME).os32
aros: build/$(NAME).aros

build/$(NAME).os32: $(SRC)
	@mkdir -p build
	$(CC_OS32) -m68040 -specs=$(SPECS) -noixemul $(CFLAGS) -I$(SDK)/Include -o $@ $(SRC)

build/$(NAME).aros: $(SRC)
	@mkdir -p build
	$(CC_AROS) -m68040 $(CFLAGS) -Wno-volatile-register-var -I$(SDK)/Include -o $@ $(SRC)

clean:
	rm -rf build
.PHONY: all os32 aros clean
