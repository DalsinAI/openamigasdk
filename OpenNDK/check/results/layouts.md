# OpenNDK against the vendor NDK

## Differences in what both have


## Missing from OpenNDK

Headers: dos/ansiio.h, resources/ciabase.h

Structures (0): none

Constants (8): AN_AVLNotImpl=0x1000011, AN_CLIObsolete=0x700000f, AN_DeadIntui=0x4000012, AN_MemoryInsane=0x100000c, AN_TreeNotImpl=0x1000012, BATTMEM_IDE_EXTRA_WAIT_ADDR=0x47, BATTMEM_IDE_EXTRA_WAIT_LEN=0x1, RPTAG_OutLinePen=0x80000005

## In OpenNDK only

Constants (5753): (too many to list)

## OpenNDK headers that don't compile alone (0)


## NDK headers that don't compile alone (266)

- classes/arexx.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- classes/requester.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- classes/window.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- datatypes/animationclass.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- datatypes/datatypes.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- datatypes/datatypesclass.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- datatypes/pictureclass.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- datatypes/soundclass.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- datatypes/textclass.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/audio.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/bootblock.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/cd.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/clipboard.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/console.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/conunit.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/gameport.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/hardblocks.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/input.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/inputevent.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/keyboard.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/keymap.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/narrator.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/newstyle.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/parallel.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/printer.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/prtbase.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/prtgfx.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/scsidisk.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/serial.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/timer.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/trackdisk.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- devices/trackfile.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- diskfont/diskfont.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- diskfont/diskfonttag.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- diskfont/glyph.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- dos/datetime.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- dos/dos.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- dos/dosasl.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- dos/dosextens.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- dos/dostags.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- dos/exall.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- dos/filehandler.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- dos/notify.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- dos/rdargs.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- dos/record.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- dos/shell.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- dos/var.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/devices.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/exec.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/execbase.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/interrupts.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/io.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/libraries.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/lists.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/memory.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/nodes.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/ports.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/resident.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/semaphores.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory
- exec/tasks.h: exec/types.h:39:20: fatal error: stdint.h: No such file or directory

1 structures and 502 constants compared, 0 differences.
