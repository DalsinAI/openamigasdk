# The Open SDK: a GadTools program for AmigaOS 3.2 and AROS, two binaries.
#   make            both
#   make os32       build/HelloWindow.os32 (bebbo's m68k-amigaos-gcc, NDK 3.2)
#   make aros       build/HelloWindow.aros (m68k-aros-gcc)
# ACKitchen sets CC_OS32 and CC_AROS to its stoves; SDK points at this SDK.
NAME     ?= HelloWindow
SRC      ?= hellowindow.c
SDK      ?= ../..
CC_OS32  ?= m68k-amigaos-gcc
CC_AROS  ?= m68k-aros-gcc
CFLAGS   ?= -O2 -Wall -Wextra -Wno-pointer-sign

all: os32 aros
os32: build/$(NAME).os32
aros: build/$(NAME).aros

build/$(NAME).os32: $(SRC)
	@mkdir -p build
	$(CC_OS32) -m68020 -noixemul $(CFLAGS) -I$(SDK)/Include -o $@ $(SRC)

build/$(NAME).aros: $(SRC)
	@mkdir -p build
	$(CC_AROS) $(CFLAGS) -I$(SDK)/Include -o $@ $(SRC)

clean:
	rm -rf build
.PHONY: all os32 aros clean
