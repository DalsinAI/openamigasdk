#ifndef IMAGES_GLYPH_H
#define IMAGES_GLYPH_H
/*
 * OpenNDK: glyph.image, the small symbols ReAction gadgets draw.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_IMAGECLASS_H
#include <intuition/imageclass.h>
#endif

#define GLYPH_Dummy		(REACTION_Dummy + 0x15000)

#define GLYPH_Glyph		(GLYPH_Dummy + 1)	/* which symbol, below */
#define GLYPH_DrawInfo		(GLYPH_Dummy + 2)

#define GLYPH_NONE		0
#define GLYPH_DOWNARROW		1
#define GLYPH_UPARROW		2
#define GLYPH_LEFTARROW		3
#define GLYPH_RIGHTARROW	4
#define GLYPH_DROPDOWN		5
#define GLYPH_POPUP		6
#define GLYPH_CHECKMARK		7
#define GLYPH_POPFONT		8
#define GLYPH_POPFILE		9
#define GLYPH_POPDRAWER		10
#define GLYPH_POPSCREENMODE	11
#define GLYPH_POPTIME		12
#define GLYPH_RADIOBUTTON	0x12
#define GLYPH_RETURNARROW	0x14

#endif /* IMAGES_GLYPH_H */
