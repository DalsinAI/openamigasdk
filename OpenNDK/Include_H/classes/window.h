#ifndef CLASSES_WINDOW_H
#define CLASSES_WINDOW_H
/*
 * OpenNDK: window.class, which opens a window round a layout and turns
 * its input into simple events.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

#define WINDOW_Dummy		(REACTION_Dummy + 0x25000)

/* Tags; the class also takes Intuition's WA_ tags for the window it opens */
#define WINDOW_Window		(WINDOW_Dummy + 1)	/* (get) struct Window *: NULL while closed */
#define WINDOW_SigMask		(WINDOW_Dummy + 2)	/* (get) the signals to Wait() for */
#define WINDOW_MenuStrip	(WINDOW_Dummy + 4)	/* struct Menu * */
#define WINDOW_Layout		(WINDOW_Dummy + 5)	/* Object *: the top layout */
#define WINDOW_ParentLayout	WINDOW_Layout
#define WINDOW_ParentGroup	WINDOW_Layout
#define WINDOW_UserData		(WINDOW_Dummy + 6)
#define WINDOW_SharedPort	(WINDOW_Dummy + 7)	/* struct MsgPort *: IDCMP shared with others */
#define WINDOW_Zoom		(WINDOW_Dummy + 8)	/* BOOL (set): zoom it */
#define WINDOW_FrontBack	(WINDOW_Dummy + 9)	/* WT_ below */
#define WINDOW_Activate		(WINDOW_Dummy + 10)	/* BOOL (set): activate it */
#define WINDOW_LockWidth	(WINDOW_Dummy + 11)	/* BOOL: not sizeable across */
#define WINDOW_LockHeight	(WINDOW_Dummy + 12)
#define WINDOW_AppPort		(WINDOW_Dummy + 13)	/* struct MsgPort *: for iconify and AppWindow */
#define WINDOW_Position		(WINDOW_Dummy + 14)	/* WPOS_ below */
#define WINDOW_IDCMPHook	(WINDOW_Dummy + 15)	/* struct Hook *: sees raw messages */
#define WINDOW_IDCMPHookBits	(WINDOW_Dummy + 16)	/* the IDCMP classes it sees */
#define WINDOW_GadgetUserData	(WINDOW_Dummy + 17)
#define WINDOW_IconTitle	(WINDOW_Dummy + 18)	/* STRPTR: the iconified window's icon label */
#define WINDOW_AppMsgHook	(WINDOW_Dummy + 19)	/* struct Hook *: for AppMessages */
#define WINDOW_Icon		(WINDOW_Dummy + 20)	/* struct DiskObject *: for iconify */
#define WINDOW_AppWindow	(WINDOW_Dummy + 21)	/* BOOL: accept dropped icons */
#define WINDOW_GadgetHelp	(WINDOW_Dummy + 22)	/* BOOL: gadget help on */
#define WINDOW_IconifyGadget	(WINDOW_Dummy + 23)	/* BOOL: an iconify button in the border */
#define WINDOW_TextAttr		(WINDOW_Dummy + 24)	/* struct TextAttr *: the gadgets' font */
#define WINDOW_MenuUserData	(WINDOW_Dummy + 25)
#define WINDOW_BackFillName	(WINDOW_Dummy + 26)	/* STRPTR: a picture file for the background */
#define WINDOW_RefWindow	(WINDOW_Dummy + 41)	/* struct Window *: WPOS_CENTERWINDOW's */
#define WINDOW_InputEvent	(WINDOW_Dummy + 42)	/* (get) struct InputEvent * */
#define WINDOW_HintInfo		(WINDOW_Dummy + 43)	/* struct HintInfo *: help bubbles */

/* WINDOW_FrontBack */
#define WT_FRONT	1
#define WT_BACK		0

/* WINDOW_Position */
#define WPOS_CENTERSCREEN	1
#define WPOS_CENTERMOUSE	2
#define WPOS_TOPLEFT		3
#define WPOS_CENTERWINDOW	4
#define WPOS_FULLSCREEN		5

/* One help bubble; an array ends with hi_GadgetID -1 */
struct HintInfo
{
	WORD	hi_GadgetID;	/* the gadget's GA_ID */
	WORD	hi_Code;	/* -1: any code */
	STRPTR	hi_Text;
	ULONG	hi_Flags;
};

/* Methods */
#define WM_HANDLEINPUT	0x570001	/* struct wmHandle */
#define WM_OPEN		0x570002	/* answers the struct Window * */
#define WM_CLOSE	0x570003
#define WM_NEWPREFS	0x570004
#define WM_ICONIFY	0x570005
#define WM_RETHINK	0x570006

struct wmHandle
{
	ULONG	MethodID;	/* WM_HANDLEINPUT */
	WORD	*wmh_Code;	/* the event's code is stored here */
};

/* WM_HANDLEINPUT's answer: the class in the high word, a value in the low */
#define WMHI_LASTMSG		0		/* nothing more on the port */
#define WMHI_IGNORE		(~0L)		/* nothing to act on */
#define WMHI_GADGETMASK		0xffff		/* the gadget's GA_ID */
#define WMHI_MENUMASK		0xffff		/* the menu number */
#define WMHI_KEYMASK		0xff		/* the key */
#define WMHI_CLASSMASK		0xffff0000

#define WMHI_CLOSEWINDOW	(1 << 16)
#define WMHI_GADGETUP		(2 << 16)
#define WMHI_INACTIVE		(3 << 16)
#define WMHI_ACTIVE		(4 << 16)
#define WMHI_NEWSIZE		(5 << 16)
#define WMHI_MENUPICK		(6 << 16)
#define WMHI_MENUHELP		(7 << 16)
#define WMHI_GADGETHELP		(8 << 16)
#define WMHI_ICONIFY		(9 << 16)
#define WMHI_UNICONIFY		(10 << 16)
#define WMHI_RAWKEY		(11 << 16)
#define WMHI_VANILLAKEY		(12 << 16)
#define WMHI_CHANGEWINDOW	(13 << 16)
#define WMHI_INTUITICK		(14 << 16)
#define WMHI_MOUSEMOVE		(15 << 16)
#define WMHI_MOUSEBUTTONS	(16 << 16)
#define WMHI_DISPOSEDWINDOW	(17 << 16)

#endif /* CLASSES_WINDOW_H */
