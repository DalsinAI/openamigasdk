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

#define GA_TEXTEDITOR_Contents		(GA_TEXTEDITOR_Dummy + 0x02)	/* STRPTR: the whole text */
#define GA_TEXTEDITOR_PopWindow_Open	(GA_TEXTEDITOR_Dummy + 0x03)
#define GA_TEXTEDITOR_CursorX		(GA_TEXTEDITOR_Dummy + 0x04)
#define GA_TEXTEDITOR_CursorY		(GA_TEXTEDITOR_Dummy + 0x05)
#define GA_TEXTEDITOR_DoubleClickHook	(GA_TEXTEDITOR_Dummy + 0x06)
#define GA_TEXTEDITOR_TypeAndSpell	(GA_TEXTEDITOR_Dummy + 0x07)
#define GA_TEXTEDITOR_ExportHook	(GA_TEXTEDITOR_Dummy + 0x08)
#define GA_TEXTEDITOR_ExportWrap	(GA_TEXTEDITOR_Dummy + 0x09)
#define GA_TEXTEDITOR_FixedFont		(GA_TEXTEDITOR_Dummy + 0x0A)
#define GA_TEXTEDITOR_Flow		(GA_TEXTEDITOR_Dummy + 0x0B)	/* GV_TEXTEDITOR_Flow_ below */
#define GA_TEXTEDITOR_HasChanged	(GA_TEXTEDITOR_Dummy + 0x0C)
#define GA_TEXTEDITOR_Prop_DeltaFactor	(GA_TEXTEDITOR_Dummy + 0x0D)
#define GA_TEXTEDITOR_ImportHook	(GA_TEXTEDITOR_Dummy + 0x0E)
#define GA_TEXTEDITOR_InsertMode	(GA_TEXTEDITOR_Dummy + 0x0F)
#define GA_TEXTEDITOR_ImportWrap	(GA_TEXTEDITOR_Dummy + 0x10)
#define GA_TEXTEDITOR_KeyBindings	(GA_TEXTEDITOR_Dummy + 0x11)
#define GA_TEXTEDITOR_UndoAvailable	(GA_TEXTEDITOR_Dummy + 0x12)
#define GA_TEXTEDITOR_RedoAvailable	(GA_TEXTEDITOR_Dummy + 0x13)
#define GA_TEXTEDITOR_AreaMarked	(GA_TEXTEDITOR_Dummy + 0x14)
#define GA_TEXTEDITOR_Prop_Entries	(GA_TEXTEDITOR_Dummy + 0x15)	/* for a scroller: lines in all */
#define GA_TEXTEDITOR_Prop_Visible	(GA_TEXTEDITOR_Dummy + 0x16)	/* lines in view */
#define GA_TEXTEDITOR_Quiet		(GA_TEXTEDITOR_Dummy + 0x17)	/* BOOL: hold off redrawing */
#define GA_TEXTEDITOR_NumLock		(GA_TEXTEDITOR_Dummy + 0x18)
#define GA_TEXTEDITOR_ReadOnly		(GA_TEXTEDITOR_Dummy + 0x19)
#define GA_TEXTEDITOR_InVirtualGadget	(GA_TEXTEDITOR_Dummy + 0x1B)
#define GA_TEXTEDITOR_StyleBold		(GA_TEXTEDITOR_Dummy + 0x1C)
#define GA_TEXTEDITOR_StyleItalic	(GA_TEXTEDITOR_Dummy + 0x1D)
#define GA_TEXTEDITOR_StyleUnderline	(GA_TEXTEDITOR_Dummy + 0x1E)
#define GA_TEXTEDITOR_Prop_First	(GA_TEXTEDITOR_Dummy + 0x20)	/* the first line in view */
#define GA_TEXTEDITOR_WrapBorder	(GA_TEXTEDITOR_Dummy + 0x21)
#define GA_TEXTEDITOR_Separator		(GA_TEXTEDITOR_Dummy + 0x2C)
#define GA_TEXTEDITOR_Pen		(GA_TEXTEDITOR_Dummy + 0x2E)
#define GA_TEXTEDITOR_ColorMap		(GA_TEXTEDITOR_Dummy + 0x2F)
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
