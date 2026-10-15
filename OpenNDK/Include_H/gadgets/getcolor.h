#ifndef GADGETS_GETCOLOR_H
#define GADGETS_GETCOLOR_H
/*
 * OpenNDK: getcolor.gadget, a colour swatch with a colour requester behind it.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

#define GETCOLOR_Dummy		(REACTION_Dummy + 0x43000)

#define GETCOLOR_TitleText	(GETCOLOR_Dummy + 1)	/* the requester's title */
#define GETCOLOR_LeftEdge	(GETCOLOR_Dummy + 2)	/* the requester's box */
#define GETCOLOR_TopEdge	(GETCOLOR_Dummy + 3)
#define GETCOLOR_Width		(GETCOLOR_Dummy + 4)
#define GETCOLOR_Height		(GETCOLOR_Dummy + 5)
#define GETCOLOR_Screen		(GETCOLOR_Dummy + 2)
#define GETCOLOR_Color		(GETCOLOR_Dummy + 3)	/* ULONG: 0x00RRGGBB */
#define GETCOLOR_RGB		(GETCOLOR_Dummy + 10)	/* ULONG *: three 32-bit values */

/* Method: open the requester */
#define GCOLOR_REQUEST	0x630001

#endif /* GADGETS_GETCOLOR_H */
