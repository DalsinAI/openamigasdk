#ifndef GADGETS_CHECKBOX_H
#define GADGETS_CHECKBOX_H
/*
 * OpenNDK: checkbox.gadget, a box with a tick and a label.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

#define CHECKBOX_Dummy		(REACTION_Dummy + 0x11000)

#define CHECKBOX_TextPen	(CHECKBOX_Dummy + 0x0001)
#define CHECKBOX_BackgroundPen	(CHECKBOX_Dummy + 0x0003)
#define CHECKBOX_TextPlace	(CHECKBOX_Dummy + 0x0005)	/* PLACETEXT_LEFT or _RIGHT */
#define CHECKBOX_Checked	GA_Selected

#endif /* GADGETS_CHECKBOX_H */
