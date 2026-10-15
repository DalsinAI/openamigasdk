#ifndef GRAPHICS_GFX_H
#define GRAPHICS_GFX_H
/*
 * OpenNDK: graphics.library's basic shapes: rectangles, points and bitmaps.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/* Set and clear forms of a custom-chip control word */
#define BITSET	0x8000
#define BITCLR	0

/* Chip RAM addresses need no translation on any shipped Agnus */
#define AGNUS
#define TOBB(a)	((long)(a))

/* A rectangle in 16-bit and 32-bit coordinates; Max is inclusive */
struct Rectangle
{
    WORD MinX, MinY;
    WORD MaxX, MaxY;
};

struct Rect32
{
    LONG MinX, MinY;
    LONG MaxX, MaxY;
};

typedef struct tPoint
{
    WORD x, y;
} Point;

/* One bitplane */
typedef UBYTE *PLANEPTR;

struct BitMap
{
    UWORD    BytesPerRow;
    UWORD    Rows;
    UBYTE    Flags;
    UBYTE    Depth;
    UWORD    pad;
    PLANEPTR Planes[8];
};

/* Bytes in one plane of w by h pixels, rows padded to whole words */
#define RASSIZE(w, h)	((ULONG)(h) * ((((ULONG)(w) + 15) >> 3) & 0xFFFE))

/* AllocBitMap() flags */
#define BMB_CLEAR	0
#define BMB_DISPLAYABLE	1
#define BMB_INTERLEAVED	2
#define BMB_STANDARD	3
#define BMB_MINPLANES	4
#define BMB_SPECIALFMT	7	/* pixel format in the top byte (SHIFT_PIXFMT) */

#define BMF_CLEAR	(1L << BMB_CLEAR)
#define BMF_DISPLAYABLE	(1L << BMB_DISPLAYABLE)
#define BMF_INTERLEAVED	(1L << BMB_INTERLEAVED)
#define BMF_STANDARD	(1L << BMB_STANDARD)
#define BMF_MINPLANES	(1L << BMB_MINPLANES)
#define BMF_SPECIALFMT	(1L << BMB_SPECIALFMT)

#define SHIFT_PIXFMT(fmt)	(((ULONG)(fmt)) << 24)

/* GetBitMapAttr() attributes */
#define BMA_HEIGHT	0
#define BMA_DEPTH	4
#define BMA_WIDTH	8
#define BMA_FLAGS	12

#endif /* GRAPHICS_GFX_H */
