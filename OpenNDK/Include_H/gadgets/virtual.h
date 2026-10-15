#ifndef GADGETS_VIRTUAL_H
#define GADGETS_VIRTUAL_H
/*
 * OpenNDK: virtual.gadget, a scrolling view onto a layout larger than itself.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif
#ifndef GADGETS_LAYOUT_H
#include <gadgets/layout.h>
#endif

#define VIRTUALA_Dummy		(REACTION_Dummy + 0x2B000)

#define VIRTUALA_Contents	(VIRTUALA_Dummy + 1)	/* Object *: the layout inside */
#define VIRTUALA_Scroller	(VIRTUALA_Dummy + 2)	/* which scrollers it has */

#endif /* GADGETS_VIRTUAL_H */
