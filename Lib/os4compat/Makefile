# The Open SDK: os4compat, OS 4 interfaces and calls for AmigaOS 3.2 (m68k).
#   make NDK=/path/to/NDK3.2        build/libos4compat.a and build/include/
#   make NDK=... LIBS="exec dos"    only these interfaces (default below)
# The interfaces are made from the NDK's own SFD files at build time, so
# nothing from the NDK is shipped. ACKitchen sets NDK and CC to its stove.
NDK      ?= /opt/amiga/m68k-amigaos/ndk-include/..
SFD      ?= $(NDK)/SFD
SDK      ?= ../..
CC       ?= m68k-amigaos-gcc
AR       ?= m68k-amigaos-ar
PYTHON   ?= python3
CPU      ?= -m68020
CFLAGS   ?= -O2 -Wall -Wno-pointer-sign -fno-common
LIBS     ?= exec dos utility graphics intuition layers gadtools asl icon wb \
            locale diskfont keymap commodities datatypes iffparse rexxsyslib \
            expansion timer
B        := build
SFDS     := $(foreach l,$(LIBS),$(SFD)/$(l)_lib.sfd)
EXTRAS   := iface exec_extras dos_extras utility_fmt utility_extras graphics_extras intuition_extras
GEN_OBJS := $(foreach l,$(LIBS),$(B)/obj/$(l)_iface.o $(B)/obj/$(l)_ivar.o) $(B)/obj/os4c_registry.o
OBJS     := $(GEN_OBJS) $(foreach e,$(EXTRAS),$(B)/obj/$(e).o)
INC      := -I$(SDK)/Include -I$(B)/include

all: $(B)/libos4compat.a

$(B)/.generated: $(SFDS) $(SDK)/tools/os4ifgen.py
	@mkdir -p $(B)
	$(PYTHON) $(SDK)/tools/os4ifgen.py $(B) $(SFDS)
	@touch $@

# the members are compiled against the NDK's own proto/ headers, so the
# generated proto/ overrides are not on this include path
$(B)/obj/%_iface.o: $(B)/.generated
	@mkdir -p $(B)/obj
	$(CC) $(CPU) -noixemul $(CFLAGS) -I$(SDK)/Include -c -o $@ $(B)/src/$*_iface.c
$(B)/obj/%_ivar.o: $(B)/.generated
	@mkdir -p $(B)/obj
	$(CC) $(CPU) -noixemul $(CFLAGS) -I$(SDK)/Include -c -o $@ $(B)/src/$*_ivar.c
$(B)/obj/os4c_registry.o: $(B)/.generated
	@mkdir -p $(B)/obj
	$(CC) $(CPU) -noixemul $(CFLAGS) -I$(SDK)/Include -c -o $@ $(B)/src/os4c_registry.c
$(B)/obj/%.o: src/%.c src/os4c_internal.h $(SDK)/Include/os4compat/os4compat.h $(B)/.generated
	@mkdir -p $(B)/obj
	$(CC) $(CPU) -noixemul $(CFLAGS) -I$(SDK)/Include -c -o $@ $<

$(B)/libos4compat.a: $(OBJS)
	rm -f $@
	$(AR) rcs $@ $(OBJS)

clean:
	rm -rf $(B)
.PHONY: all clean
