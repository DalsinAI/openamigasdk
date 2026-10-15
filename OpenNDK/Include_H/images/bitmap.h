#ifndef IMAGES_BITMAP_H
#define IMAGES_BITMAP_H
/*
 * OpenNDK: bitmap.image, a picture from a BitMap or a file.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_IMAGECLASS_H
#include <intuition/imageclass.h>
#endif

#define BITMAP_Dummy		(REACTION_Dummy + 0x19000)

#define BITMAP_SourceFile	(BITMAP_Dummy + 1)	/* STRPTR: loaded through datatypes */
#define BITMAP_Screen		(BITMAP_Dummy + 2)	/* struct Screen *: remap for it */
#define BITMAP_Precision	(BITMAP_Dummy + 3)	/* pen precision for the remap */
#define BITMAP_Masking		(BITMAP_Dummy + 4)	/* BOOL: draw through the mask */
#define BITMAP_BitMap		(BITMAP_Dummy + 5)	/* struct BitMap * */
#define BITMAP_Width		(BITMAP_Dummy + 6)
#define BITMAP_Height		(BITMAP_Dummy + 7)
#define BITMAP_MaskPlane	(BITMAP_Dummy + 8)	/* PLANEPTR */
#define BITMAP_SelectSourceFile	(BITMAP_Dummy + 9)	/* the same, for the selected state */
#define BITMAP_SelectBitMap	(BITMAP_Dummy + 10)
#define BITMAP_SelectWidth	(BITMAP_Dummy + 11)
#define BITMAP_SelectHeight	(BITMAP_Dummy + 12)
#define BITMAP_SelectMaskPlane	(BITMAP_Dummy + 13)
#define BITMAP_OffsetX		(BITMAP_Dummy + 14)	/* where in the BitMap to start */
#define BITMAP_OffsetY		(BITMAP_Dummy + 15)
#define BITMAP_SelectOffsetX	(BITMAP_Dummy + 16)
#define BITMAP_SelectOffsetY	(BITMAP_Dummy + 17)

#endif /* IMAGES_BITMAP_H */
