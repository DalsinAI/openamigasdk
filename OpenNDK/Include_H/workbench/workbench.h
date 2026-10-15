#ifndef WORKBENCH_WORKBENCH_H
#define WORKBENCH_WORKBENCH_H
/*
 * OpenNDK: Workbench's icons (struct DiskObject), drawer data and the
 * application windows, icons and menu items of workbench.library.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif
#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef EXEC_TASKS_H
#include <exec/tasks.h>
#endif
#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef WORKBENCH_STARTUP_H
#include <workbench/startup.h>
#endif

#define WORKBENCH_NAME	"workbench.library"

/* DiskObject.do_Type: what an icon stands for */
#define WBDISK		1
#define WBDRAWER	2
#define WBTOOL		3
#define WBPROJECT	4
#define WBGARBAGE	5
#define WBDEVICE	6
#define WBKICK		7
#define WBAPPICON	8

/* A drawer's window as icons stored it before V36 */
struct OldDrawerData
{
    struct NewWindow dd_NewWindow;
    LONG dd_CurrentX;			/* the scroll position */
    LONG dd_CurrentY;
};

/* The size of an OldDrawerData in an icon file */
#define OLDDRAWERDATAFILESIZE	(sizeof(struct OldDrawerData))

/* A drawer's window as icons store it */
struct DrawerData
{
    struct NewWindow dd_NewWindow;
    LONG dd_CurrentX;
    LONG dd_CurrentY;
    ULONG dd_Flags;			/* DDFLAGS_ */
    UWORD dd_ViewModes;			/* DDVM_ */
};

/* The size of a DrawerData in an icon file */
#define DRAWERDATAFILESIZE	(sizeof(struct DrawerData))

/* dd_Flags: which files the drawer shows */
#define DDFLAGS_SHOWDEFAULT	0
#define DDFLAGS_SHOWICONS	1
#define DDFLAGS_SHOWALL		2

/* dd_ViewModes */
#define DDVM_BYDEFAULT		0
#define DDVM_BYICON		1
#define DDVM_BYNAME		2
#define DDVM_BYDATE		3
#define DDVM_BYSIZE		4
#define DDVM_BYTYPE		5

/* An icon */
struct DiskObject
{
    UWORD do_Magic;			/* WB_DISKMAGIC */
    UWORD do_Version;			/* WB_DISKVERSION */
    struct Gadget do_Gadget;		/* its images and box */
    UBYTE do_Type;			/* WBDISK and friends */
    STRPTR do_DefaultTool;
    STRPTR *do_ToolTypes;		/* NULL-ended */
    LONG do_CurrentX;
    LONG do_CurrentY;
    struct DrawerData *do_DrawerData;
    STRPTR do_ToolWindow;
    LONG do_StackSize;
};

#define WB_DISKMAGIC		0xE310
#define WB_DISKVERSION		1
#define WB_DISKREVISION		1
#define WB_DISKREVISIONMASK	255

/* What icon.library frees together with an icon */
struct FreeList
{
    WORD fl_NumFree;
    struct List fl_MemList;
};

/* do_Gadget.Flags: the second image is a backfill */
#define GFLG_GADGBACKFILL	0x0001
#define GADGBACKFILL		0x0001

/* do_CurrentX and do_CurrentY of an icon Workbench may place */
#define NO_ICON_POSITION	(0x80000000)

/* ---- Application windows, icons and menu items ---------------------- */

/* The message sent to an AppWindow, AppIcon or AppMenuItem's port */
struct AppMessage
{
    struct Message am_Message;
    UWORD am_Type;			/* AMTYPE_ */
    ULONG am_UserData;
    ULONG am_ID;
    LONG am_NumArgs;
    struct WBArg *am_ArgList;
    UWORD am_Version;			/* AM_VERSION */
    UWORD am_Class;			/* AMCLASSICON_ for an AppIcon */
    WORD am_MouseX;
    WORD am_MouseY;
    ULONG am_Seconds;
    ULONG am_Micros;
    ULONG am_Reserved[8];
};

#define AM_VERSION	1

/* am_Type */
#define AMTYPE_APPWINDOW	7
#define AMTYPE_APPICON		8
#define AMTYPE_APPMENUITEM	9
#define AMTYPE_APPWINDOWZONE	10	/* V44 */

/* am_Class of an AppIcon's message (V44) */
#define AMCLASSICON_Open		0
#define AMCLASSICON_Copy		1
#define AMCLASSICON_Rename		2
#define AMCLASSICON_Information		3
#define AMCLASSICON_Snapshot		4
#define AMCLASSICON_UnSnapshot		5
#define AMCLASSICON_LeaveOut		6
#define AMCLASSICON_PutAway		7
#define AMCLASSICON_Delete		8
#define AMCLASSICON_FormatDisk		9
#define AMCLASSICON_EmptyTrash		10

#define AMCLASSICON_Selected		11
#define AMCLASSICON_Unselected		12

/* Handles; their insides belong to workbench.library */
struct AppWindow
{
    APTR aw_PRIVATE;
};

struct AppWindowDropZone
{
    APTR awdz_PRIVATE;
};

struct AppIcon
{
    APTR ai_PRIVATE;
};

struct AppMenuItem
{
    APTR ami_PRIVATE;
};

/* ---- workbench.library's tags (V44) ---------------------------------- */

#define WBA_Dummy	(TAG_USER + 0xA000)

/* AddAppIconA() */
#define WBAPPICONA_SupportsOpen		(WBA_Dummy + 1)
#define WBAPPICONA_SupportsCopy		(WBA_Dummy + 2)
#define WBAPPICONA_SupportsRename	(WBA_Dummy + 3)
#define WBAPPICONA_SupportsInformation	(WBA_Dummy + 4)
#define WBAPPICONA_SupportsSnapshot	(WBA_Dummy + 5)
#define WBAPPICONA_SupportsUnSnapshot	(WBA_Dummy + 6)
#define WBAPPICONA_SupportsLeaveOut	(WBA_Dummy + 7)
#define WBAPPICONA_SupportsPutAway	(WBA_Dummy + 8)
#define WBAPPICONA_SupportsDelete	(WBA_Dummy + 9)
#define WBAPPICONA_SupportsFormatDisk	(WBA_Dummy + 10)
#define WBAPPICONA_SupportsEmptyTrash	(WBA_Dummy + 11)
#define WBAPPICONA_PropagatePosition	(WBA_Dummy + 12)
#define WBAPPICONA_RenderHook		(WBA_Dummy + 13)
#define WBAPPICONA_NotifySelectState	(WBA_Dummy + 14)

/* AddAppMenuItemA() */
#define WBAPPMENUA_CommandKeyString	(WBA_Dummy + 15)

/* OpenWorkbenchObjectA() */
#define WBOPENA_ArgLock			(WBA_Dummy + 16)
#define WBOPENA_ArgName			(WBA_Dummy + 17)

/* WorkbenchControlA() */
#define WBCTRLA_IsOpen			(WBA_Dummy + 18)
#define WBCTRLA_DuplicateSearchPath	(WBA_Dummy + 19)
#define WBCTRLA_FreeSearchPath		(WBA_Dummy + 20)
#define WBCTRLA_GetDefaultStackSize	(WBA_Dummy + 21)
#define WBCTRLA_SetDefaultStackSize	(WBA_Dummy + 22)
#define WBCTRLA_RedrawAppIcon		(WBA_Dummy + 23)
#define WBCTRLA_GetProgramList		(WBA_Dummy + 24)
#define WBCTRLA_FreeProgramList		(WBA_Dummy + 25)

/* AddAppWindowDropZoneA() */
#define WBDZA_Left			(WBA_Dummy + 26)
#define WBDZA_RelRight			(WBA_Dummy + 27)
#define WBDZA_Top			(WBA_Dummy + 28)
#define WBDZA_RelBottom			(WBA_Dummy + 29)
#define WBDZA_Width			(WBA_Dummy + 30)
#define WBDZA_RelWidth			(WBA_Dummy + 31)
#define WBDZA_Height			(WBA_Dummy + 32)
#define WBDZA_RelHeight			(WBA_Dummy + 33)
#define WBDZA_Box			(WBA_Dummy + 34)
#define WBDZA_Hook			(WBA_Dummy + 35)

/* What a drop zone's hook is told (V44) */
struct AppWindowDropZoneMsg
{
    struct RastPort *adzm_RastPort;	/* the window's */
    struct IBox adzm_DropZoneBox;
    ULONG adzm_ID;
    ULONG adzm_UserData;
    LONG adzm_Action;			/* ADZMACTION_ */
};

#define ADZMACTION_Enter	(0)
#define ADZMACTION_Leave	(1)

/* What an AppIcon's render hook is told (V44) */
struct AppIconRenderMsg
{
    struct RastPort *arm_RastPort;
    struct DiskObject *arm_Icon;
    STRPTR arm_Label;
    struct TagItem *arm_Tags;		/* for DrawIconStateA() */
    WORD arm_Left;
    WORD arm_Top;
    WORD arm_Width;
    WORD arm_Height;
    ULONG arm_State;			/* IDS_ */
};

#endif /* WORKBENCH_WORKBENCH_H */
