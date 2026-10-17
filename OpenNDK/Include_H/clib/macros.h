#ifndef CLIB_MACROS_H
#define CLIB_MACROS_H
/*
 * OpenNDK: three small helpers OS 3.2 sources use.
 * Copyright (c) 2026 AmigaChrome Team. MIT licence (see OpenNDK/LICENSE).
 */


#ifndef MAX
#define MAX(a, b)	((a) > (b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a, b)	((a) < (b) ? (a) : (b))
#endif
#ifndef ABS
#define ABS(x)		((x) < 0 ? -(x) : (x))
#endif

#endif /* CLIB_MACROS_H */
