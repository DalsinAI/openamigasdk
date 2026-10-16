#ifndef GRAPHICS_GFXNODES_H
#define GRAPHICS_GFXNODES_H
/*
 * OpenNDK: the extended nodes GfxNew() makes and GfxAssociate() links.
 * Copyright (c) 2026 AmigaChrome Team. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif

struct ExtendedNode
{
    struct Node *xln_Succ;
    struct Node *xln_Pred;
    UBYTE        xln_Type;
    BYTE         xln_Pri;
    char        *xln_Name;
    UBYTE        xln_Subsystem;
    UBYTE        xln_Subtype;
    LONG         xln_Library;	/* the GfxBase that made it */
    LONG       (*xln_Init)();
};

/* xln_Subsystem */
#define SS_GRAPHICS	0x02

/* GfxNew() node types (xln_Subtype) */
#define VIEW_EXTRA_TYPE		1
#define VIEWPORT_EXTRA_TYPE	2
#define SPECIAL_MONITOR_TYPE	3
#define MONITOR_SPEC_TYPE	4

#endif /* GRAPHICS_GFXNODES_H */
