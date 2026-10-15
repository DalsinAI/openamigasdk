#ifndef PREFS_WORKBENCH_H
#define PREFS_WORKBENCH_H
/*
 * OpenNDK: Workbench preferences (the WBNC chunk).
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif
#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#define ID_WBNC		MAKE_ID('W','B','N','C')
#define ID_WBHD		MAKE_ID('W','B','H','D')	/* a hidden device's name */

struct WorkbenchPrefs
{
    /* V44 */
    ULONG wbp_DefaultStackSize;
    ULONG wbp_TypeRestartTime;		/* ticks before type-ahead restarts */
    ULONG wbp_IconPrecision;		/* PRECISION_ of graphics/view.h */
    struct Rectangle wbp_EmbossRect;
    BOOL wbp_Borderless;
    LONG wbp_MaxNameLength;
    BOOL wbp_NewIconsSupport;
    BOOL wbp_ColorIconSupport;
    /* V45 */
    ULONG wbp_ImageMemType;
    BOOL wbp_LockPens;
    BOOL wbp_NoTitleBar;
    BOOL wbp_NoGauge;
};

#endif /* PREFS_WORKBENCH_H */
