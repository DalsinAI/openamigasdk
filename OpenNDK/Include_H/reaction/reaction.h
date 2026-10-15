#ifndef REACTION_REACTION_H
#define REACTION_REACTION_H
/*
 * OpenNDK: what every ReAction class shares: the base of their tag space.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/* Each class's tags are an offset from here */
#define REACTION_Dummy		(TAG_USER + 0x5000000)

/* Tags any ReAction object may be given */
#define REACTION_TextAttr	(REACTION_Dummy + 5)	/* struct TextAttr *: the font */
#define REACTION_ChangePrefs	(REACTION_Dummy + 6)	/* the user's settings changed */
#define REACTION_SpecialPens	(REACTION_Dummy + 7)	/* struct SpecialPens * */

/* Extra pens for the 3D look */
struct SpecialPens
{
	WORD	sp_Version;	/* 0 */
	LONG	sp_DarkPen;	/* -1: none */
	LONG	sp_LightPen;	/* -1: none */
};

/* More names from the 3.2 interface */
#define REACTION_Justification	(REACTION_Dummy + 8)

#endif /* REACTION_REACTION_H */
