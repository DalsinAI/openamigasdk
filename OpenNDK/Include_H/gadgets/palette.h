#ifndef GADGETS_PALETTE_H
#define GADGETS_PALETTE_H
/*
 * OpenNDK: palette.gadget, a grid of colours to pick one from.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

#define PALETTE_Dummy		(REACTION_Dummy + 0x4A000)

#define PALETTE_Colour		(PALETTE_Dummy + 1)	/* the chosen pen */
#define PALETTE_ColourOffset	(PALETTE_Dummy + 2)	/* the first pen shown */
#define PALETTE_ColourTable	(PALETTE_Dummy + 3)	/* UBYTE *: the pens shown */
#define PALETTE_NumColours	(PALETTE_Dummy + 4)

#endif /* GADGETS_PALETTE_H */
