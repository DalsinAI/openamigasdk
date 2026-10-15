#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H
/*
 * OpenNDK: timer.device's units, commands and time structures.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_IO_H
#include <exec/io.h>
#endif

/* Units */
#define UNIT_MICROHZ	0	/* a delay, precise */
#define UNIT_VBLANK	1	/* a delay, to the frame */
#define UNIT_ECLOCK	2	/* a delay in E-clock ticks */
#define UNIT_WAITUNTIL	3	/* until a system time */
#define UNIT_WAITECLOCK	4	/* until an E-clock count */

#define TIMERNAME	"timer.device"

/* A time: seconds and microseconds */
struct timeval {
	ULONG	tv_secs;
	ULONG	tv_micro;
};

/* The 64-bit E-clock count ReadEClock() gives */
struct EClockVal {
	ULONG	ev_hi;
	ULONG	ev_lo;
};

/* The request every timer command takes */
struct timerequest {
	struct IORequest	tr_node;
	struct timeval		tr_time;
};

/* Commands */
#define TR_ADDREQUEST	CMD_NONSTD
#define TR_GETSYSTIME	(CMD_NONSTD+1)
#define TR_SETSYSTIME	(CMD_NONSTD+2)

/* The same two, by the names the 3.2 interface uses */
struct TimeVal {
	ULONG	tv_secs;
	ULONG	tv_micro;
};

struct TimeRequest {
	struct IORequest	tr_node;
	struct TimeVal		tr_time;
};

#endif /* DEVICES_TIMER_H */
