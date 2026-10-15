#ifndef GADGETS_CLICKTAB_H
#define GADGETS_CLICKTAB_H
/*
 * OpenNDK: clicktab.gadget, a row of tabs that can turn a page group.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

#define CLICKTAB_Dummy			(REACTION_Dummy + 0x27000)

#define CLICKTAB_Labels			(CLICKTAB_Dummy + 0x0001)	/* struct List * of AllocClickTabNode()s */
#define CLICKTAB_Current		(CLICKTAB_Dummy + 0x0002)	/* the current tab's TNA_Number */
#define CLICKTAB_CurrentNode		(CLICKTAB_Dummy + 0x0003)	/* struct Node * */
#define CLICKTAB_Orientation		(CLICKTAB_Dummy + 0x0004)	/* CTORIENT_ below */
#define CLICKTAB_PageGroup		(CLICKTAB_Dummy + 0x0005)	/* a page.gadget turned with the tabs */
#define CLICKTAB_PageGroupBackFill	(CLICKTAB_Dummy + 0x0006)	/* struct Hook *: the page's backfill */

#define CTORIENT_HORIZ	0
#define CTORIENT_VERT	1

/* A tab node's attributes (AllocClickTabNodeA and friends) */
#define TNA_Dummy	(TAG_USER + 0x010000)

#define TNA_UserData	(TNA_Dummy + 1)
#define TNA_Enabled	(TNA_Dummy + 2)
#define TNA_Spacing	(TNA_Dummy + 3)
#define TNA_Highlight	(TNA_Dummy + 4)
#define TNA_Image	(TNA_Dummy + 5)		/* struct Image * */
#define TNA_SelImage	(TNA_Dummy + 6)
#define TNA_Text	(TNA_Dummy + 7)		/* STRPTR */
#define TNA_Number	(TNA_Dummy + 8)		/* the value CLICKTAB_Current takes */
#define TNA_TextPen	(TNA_Dummy + 9)
#define TNA_Disabled	(TNA_Dummy + 10)

#endif /* GADGETS_CLICKTAB_H */
