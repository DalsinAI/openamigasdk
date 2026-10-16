/* accontrol.device: AmigaChrome's control plane for Amiga programs.
 *
 * OpenDevice("accontrol.device", 0, (struct IORequest *)io, 0) with a
 * struct IOStdReq, then DoIO / SendIO. The device drives the ACBridge
 * control board (Zorro II, product 1; AmigaChrome Team $DA15, or 2011 before AmigaChrome Team),
 * one command at a time for every program that opens it.
 *
 *   ACCMD_GETPACE   io_Actual = the CPU's pace in Hz (0: hyper, as fast as
 *                   the host)
 *   ACCMD_SETPACE   io_Offset = the pace in Hz (0 hyper, else 1 to 200 MHz,
 *                   timing accurate); io_Actual = the pace now.
 *                   ACCERR_REFUSED if the machine will not take it.
 *   ACCMD_BOARD     io_Offset = a board query for the host (ACC_QUERY_*);
 *                   the answer (JSON text) goes to io_Data, at most io_Length
 *                   bytes; io_Actual = its length. ACCERR_HOST if the host
 *                   could not answer.
 *   ACCMD_CLIPSEQ   io_Actual = the number of the PC's latest clip (it goes
 *                   up each time the host PC's clipboard brings new text).
 *   ACCMD_CLIPGET   the PC's clip into io_Data, at most io_Length bytes;
 *                   io_Actual = its whole length (more than io_Length: call
 *                   again with room for it). Latin-1 text, LF line ends.
 *   ACCMD_CLIPPUT   io_Data, io_Length bytes of Latin-1 text, to the host
 *                   PC's clipboard.
 *                   The three clipboard commands (DSK-10, ACBridge 1.2) give
 *                   ACCERR_NOCLIP on a board without the clipboard.
 *   ACCMD_FILENEXT  the next file dropped on the instance's window: io_Offset
 *                   = 1 and io_Actual = its size, its name (Latin-1, NUL
 *                   ended) in io_Data (at most io_Length bytes); io_Offset =
 *                   0 when none waits.
 *   ACCMD_FILEREAD  that file's bytes from io_Offset into io_Data, at most
 *                   io_Length; io_Actual = the bytes read.
 *   ACCMD_FILEDONE  done with that file: the next one, if any, comes next.
 *   ACCMD_FILEPUT   a file for the host PC's tray: io_Data points to a struct
 *                   ACFilePut (its name, its bytes and their count).
 *                   The four file commands (ACBridge capability bit 12) give
 *                   ACCERR_NOFILES on a board without them.
 *   NSCMD_DEVICEQUERY  the standard query (NSDEVTYPE_UNKNOWN; the commands
 *                   above).
 *
 * Every command completes at once (the machine answers the board while the
 * Amiga's CPU waits), so AbortIO has nothing to abort.
 */
#ifndef DEVICES_ACCONTROL_H
#define DEVICES_ACCONTROL_H

#include <exec/io.h>

#define ACCONTROL_NAME "accontrol.device"

#define ACCMD_GETPACE  (CMD_NONSTD + 0)
#define ACCMD_SETPACE  (CMD_NONSTD + 1)
#define ACCMD_BOARD    (CMD_NONSTD + 2)
#define ACCMD_CLIPSEQ  (CMD_NONSTD + 3)
#define ACCMD_CLIPGET  (CMD_NONSTD + 4)
#define ACCMD_CLIPPUT  (CMD_NONSTD + 5)
#define ACCMD_FILENEXT (CMD_NONSTD + 6)
#define ACCMD_FILEREAD (CMD_NONSTD + 7)
#define ACCMD_FILEDONE (CMD_NONSTD + 8)
#define ACCMD_FILEPUT  (CMD_NONSTD + 9)

/* ACCMD_FILEPUT's io_Data */
struct ACFilePut {
    const char *name;                       /* the file's name for the PC (no path) */
    const UBYTE *data;                      /* its bytes */
    ULONG size;                             /* how many */
};

/* ACCMD_BOARD's queries (the ACBridge board's host commands) */
#define ACC_QUERY_STATUS    7      /* the host's system status */
#define ACC_QUERY_REFRESH   8      /* the same, read again */
#define ACC_QUERY_CATALOG   9      /* the machines and boot environments the host knows */

/* io_Error, beyond exec's */
#define ACCERR_NOBOARD   40        /* no ACBridge board: not an AmigaChrome machine */
#define ACCERR_OLDBOARD  41        /* an ACBridge from before ABI 1.1 (no pace) */
#define ACCERR_REFUSED   42        /* the machine refused the request (a pace outside 1-200 MHz) */
#define ACCERR_HOST      43        /* the host could not answer a query */
#define ACCERR_NOCLIP    44        /* an ACBridge from before ABI 1.2 (no clipboard) */
#define ACCERR_NOFILES   45        /* an ACBridge without files (capability bit 12) */

#endif
