#ifndef IMAGES_PENMAP_H
#define IMAGES_PENMAP_H
/*
 * OpenNDK: penmap.image, a chunky picture drawn with pens it obtains.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_IMAGECLASS_H
#include <intuition/imageclass.h>
#endif

#define PENMAP_Dummy		(REACTION_Dummy + 0x18000)

#define PENMAP_SelectBGPen	(PENMAP_Dummy + 1)	/* background pen when selected */
#define PENMAP_SelectData	(PENMAP_Dummy + 2)	/* the picture for the selected state */
#define PENMAP_Transparent	(PENMAP_Dummy + 3)	/* BOOL: colour 0 is not drawn */
#define PENMAP_Palette		(PENMAP_Dummy + 4)	/* ULONG *: the picture's colours */
#define PENMAP_Screen		(PENMAP_Dummy + 5)	/* struct Screen *: where pens come from */

#endif /* IMAGES_PENMAP_H */
