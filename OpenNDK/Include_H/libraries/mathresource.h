#ifndef LIBRARIES_MATHRESOURCE_H
#define LIBRARIES_MATHRESOURCE_H
/*
 * OpenNDK: MathIEEE.resource, through which hardware offers IEEE math.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif

struct MathIEEEResource {
	struct Node	MathIEEEResource_Node;
	UWORD		MathIEEEResource_Flags;		/* MATHIEEERESOURCEF_ */
	UWORD		*MathIEEEResource_BaseAddr;	/* the coprocessor's registers, if mapped */
	/* each sets up one library's vectors for the hardware */
	VOID		(*MathIEEEResource_DblBasInit)(VOID);
	VOID		(*MathIEEEResource_DblTransInit)(VOID);
	VOID		(*MathIEEEResource_SglBasInit)(VOID);
	VOID		(*MathIEEEResource_SglTransInit)(VOID);
	VOID		(*MathIEEEResource_ExtBasInit)(VOID);
	VOID		(*MathIEEEResource_ExtTransInit)(VOID);
};

/* MathIEEEResource_Flags: which kinds the hardware handles */
#define MATHIEEERESOURCEF_DBLBAS	(1<<0)
#define MATHIEEERESOURCEF_DBLTRANS	(1<<1)
#define MATHIEEERESOURCEF_SGLBAS	(1<<2)
#define MATHIEEERESOURCEF_SGLTRANS	(1<<3)
#define MATHIEEERESOURCEF_EXTBAS	(1<<4)
#define MATHIEEERESOURCEF_EXTTRANS	(1<<5)

#endif /* LIBRARIES_MATHRESOURCE_H */
