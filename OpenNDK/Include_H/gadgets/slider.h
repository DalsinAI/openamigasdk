#ifndef GADGETS_SLIDER_H
#define GADGETS_SLIDER_H
/*
 * OpenNDK: slider.gadget, a knob that picks a value in a range.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

#define SLIDER_Dummy		(REACTION_Dummy + 0x0028000)

#define SLIDER_Min		(SLIDER_Dummy + 0x0001)
#define SLIDER_Max		(SLIDER_Dummy + 0x0002)
#define SLIDER_Level		(SLIDER_Dummy + 0x0003)	/* the value */
#define SLIDER_Orientation	(SLIDER_Dummy + 0x0004)	/* SLIDER_HORIZONTAL or _VERTICAL */
#define SLIDER_DispHook		(SLIDER_Dummy + 0x0005)
#define SLIDER_Ticks		(SLIDER_Dummy + 0x0006)
#define SLIDER_ShortTicks	(SLIDER_Dummy + 0x0007)
#define SLIDER_TickSize		(SLIDER_Dummy + 0x0008)
#define SLIDER_KnobImage	(SLIDER_Dummy + 0x0009)
#define SLIDER_BodyFill		(SLIDER_Dummy + 0x000A)
#define SLIDER_BodyImage	(SLIDER_Dummy + 0x000B)
#define SLIDER_Gradient		(SLIDER_Dummy + 0x000C)	/* BOOL: a gradient body */
#define SLIDER_PenArray		(SLIDER_Dummy + 0x000D)	/* UWORD *: the gradient's pens */
#define SLIDER_Invert		(SLIDER_Dummy + 0x000E)	/* BOOL: maximum at the left or top */
#define SLIDER_KnobDelta	(SLIDER_Dummy + 0x000F)
#define SLIDER_LevelFormat	(SLIDER_Dummy + 0x0010)	/* STRPTR: show the level as text */
#define SLIDER_LevelPlace	(SLIDER_Dummy + 0x0011)
#define SLIDER_LevelMaxLen	(SLIDER_Dummy + 0x0012)

/* The same values as propgclass's FREEHORIZ and FREEVERT */
#define SLIDER_HORIZONTAL	0x0002
#define SLIDER_VERTICAL		0x0004

#endif /* GADGETS_SLIDER_H */
