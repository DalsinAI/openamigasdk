#ifndef GADGETS_TEXTEDITOR_H
#define GADGETS_TEXTEDITOR_H
/*
 * OpenNDK: texteditor.gadget, a multi-line text editing field.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif
#ifndef INTUITION_CGHOOKS_H
#include <intuition/cghooks.h>
#endif

#define GA_TEXTEDITOR_Dummy		(REACTION_Dummy + 0x26000)

#define GA_TEXTEDITOR_Contents		0x45002	/* STRPTR: the whole text */
#define GA_TEXTEDITOR_PopWindow_Open	0x45003
#define GA_TEXTEDITOR_CursorX		0x45004
#define GA_TEXTEDITOR_CursorY		0x45005
#define GA_TEXTEDITOR_DoubleClickHook	0x45006
#define GA_TEXTEDITOR_TypeAndSpell	0x45007
#define GA_TEXTEDITOR_ExportHook	0x45008
#define GA_TEXTEDITOR_ExportWrap	0x45009
#define GA_TEXTEDITOR_FixedFont		0x4500A
#define GA_TEXTEDITOR_Flow		0x4500B	/* GV_TEXTEDITOR_Flow_ below */
#define GA_TEXTEDITOR_HasChanged	0x4500C
#define GA_TEXTEDITOR_Prop_DeltaFactor	0x4500D
#define GA_TEXTEDITOR_ImportHook	0x4500E
#define GA_TEXTEDITOR_InsertMode	0x4500F
#define GA_TEXTEDITOR_ImportWrap	0x45010
#define GA_TEXTEDITOR_KeyBindings	0x45011
#define GA_TEXTEDITOR_UndoAvailable	0x45012
#define GA_TEXTEDITOR_RedoAvailable	0x45013
#define GA_TEXTEDITOR_AreaMarked	0x45014
#define GA_TEXTEDITOR_Prop_Entries	0x45015	/* for a scroller: lines in all */
#define GA_TEXTEDITOR_Prop_Visible	0x45016	/* lines in view */
#define GA_TEXTEDITOR_Quiet		0x45017	/* BOOL: hold off redrawing */
#define GA_TEXTEDITOR_NumLock		0x45018
#define GA_TEXTEDITOR_ReadOnly		0x45019
#define GA_TEXTEDITOR_InVirtualGadget	(GA_TEXTEDITOR_Dummy + 0x1B)
#define GA_TEXTEDITOR_StyleBold		0x4501C
#define GA_TEXTEDITOR_StyleItalic	0x4501D
#define GA_TEXTEDITOR_StyleUnderline	0x4501E
#define GA_TEXTEDITOR_Prop_First	0x45020	/* the first line in view */
#define GA_TEXTEDITOR_WrapBorder	0x45021
#define GA_TEXTEDITOR_Separator		0x4502C
#define GA_TEXTEDITOR_Pen		0x4502E
#define GA_TEXTEDITOR_ColorMap		0x4502F
#define GA_TEXTEDITOR_Rows		(GA_TEXTEDITOR_Dummy + 0x32)
#define GA_TEXTEDITOR_Columns		(GA_TEXTEDITOR_Dummy + 0x33)
#define GA_TEXTEDITOR_AutoClip		(GA_TEXTEDITOR_Dummy + 0x34)

/* Values */
#define GV_TEXTEDITOR_ExportHook_Plain		0
#define GV_TEXTEDITOR_ExportHook_EMail		1
#define GV_TEXTEDITOR_ImportHook_Plain		0
#define GV_TEXTEDITOR_ImportHook_EMail		2
#define GV_TEXTEDITOR_ImportHook_MIME		3
#define GV_TEXTEDITOR_ImportHook_MIMEQuoted	4
#define GV_TEXTEDITOR_Flow_Left			0
#define GV_TEXTEDITOR_Flow_Center		1
#define GV_TEXTEDITOR_Flow_Right		2
#define GV_TEXTEDITOR_Flow_Justified		3
#define GV_TEXTEDITOR_InsertText_Cursor		0
#define GV_TEXTEDITOR_InsertText_Top		1
#define GV_TEXTEDITOR_InsertText_Bottom		2

/* GM_TEXTEDITOR_Search and _Replace flags */
#define GF_TEXTEDITOR_Search_FromTop		(1 << 0)
#define GF_TEXTEDITOR_Search_Next		(1 << 1)
#define GF_TEXTEDITOR_Search_CaseSensitive	(1 << 2)
#define GF_TEXTEDITOR_Search_DOSPattern		(1 << 3)
#define GF_TEXTEDITOR_Search_Backwards		(1 << 4)

/* Methods */
#define GM_TEXTEDITOR_Dummy		0x45000

#define GM_TEXTEDITOR_HandleError	(GM_TEXTEDITOR_Dummy + 0x1F)
#define GM_TEXTEDITOR_AddKeyBindings	(GM_TEXTEDITOR_Dummy + 0x22)
#define GM_TEXTEDITOR_ARexxCmd		(GM_TEXTEDITOR_Dummy + 0x23)
#define GM_TEXTEDITOR_ClearText		(GM_TEXTEDITOR_Dummy + 0x24)
#define GM_TEXTEDITOR_ExportText	(GM_TEXTEDITOR_Dummy + 0x25)
#define GM_TEXTEDITOR_InsertText	(GM_TEXTEDITOR_Dummy + 0x26)
#define GM_TEXTEDITOR_MacroBegin	(GM_TEXTEDITOR_Dummy + 0x27)
#define GM_TEXTEDITOR_MacroEnd		(GM_TEXTEDITOR_Dummy + 0x28)
#define GM_TEXTEDITOR_MacroExecute	(GM_TEXTEDITOR_Dummy + 0x29)
#define GM_TEXTEDITOR_Replace		(GM_TEXTEDITOR_Dummy + 0x2A)
#define GM_TEXTEDITOR_Search		(GM_TEXTEDITOR_Dummy + 0x2B)
#define GM_TEXTEDITOR_MarkText		(GM_TEXTEDITOR_Dummy + 0x2C)
#define GM_TEXTEDITOR_BlockInfo		(GM_TEXTEDITOR_Dummy + 0x30)
#define GM_TEXTEDITOR_QueryKeyAction	(GM_TEXTEDITOR_Dummy + 0x31)

struct GP_TEXTEDITOR_ARexxCmd
{
	ULONG			MethodID;
	struct GadgetInfo	*GInfo;
	STRPTR			command;	/* a command line; the answer is the method's result */
};

struct GP_TEXTEDITOR_BlockInfo
{
	ULONG			MethodID;
	struct GadgetInfo	*GInfo;
	ULONG			*startx;	/* filled in with the marked block's corners */
	ULONG			*starty;
	ULONG			*stopx;
	ULONG			*stopy;
};

struct GP_TEXTEDITOR_ClearText
{
	ULONG			MethodID;
	struct GadgetInfo	*GInfo;
};

struct GP_TEXTEDITOR_ExportText
{
	ULONG			MethodID;
	struct GadgetInfo	*GInfo;
};

struct GP_TEXTEDITOR_InsertText
{
	ULONG			MethodID;
	struct GadgetInfo	*GInfo;
	STRPTR			text;
	LONG			pos;		/* GV_TEXTEDITOR_InsertText_ */
};

struct GP_TEXTEDITOR_MarkText
{
	ULONG			MethodID;
	struct GadgetInfo	*GInfo;
	ULONG			start_crsr_x;
	ULONG			start_crsr_y;
	ULONG			stop_crsr_x;
	ULONG			stop_crsr_y;
};

struct GP_TEXTEDITOR_Replace
{
	ULONG			MethodID;
	struct GadgetInfo	*GInfo;
	STRPTR			NewString;
	ULONG			Flags;
};

struct GP_TEXTEDITOR_Search
{
	ULONG			MethodID;
	struct GadgetInfo	*GInfo;
	STRPTR			SearchString;
	ULONG			Flags;		/* GF_TEXTEDITOR_Search_ */
};

#endif /* GADGETS_TEXTEDITOR_H */
