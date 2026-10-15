#ifndef REACTION_REACTION_MACROS_H
#define REACTION_REACTION_MACROS_H
/*
 * OpenNDK: shorthand for building ReAction object trees in one expression.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 *
 * Each XxxObject opens a NewObject() call on the class (its library must
 * be open, or the class made by name), the tags follow, and an End macro
 * closes it. The *_GetClass() calls come from the classes' proto headers.
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

/* Closing a NewObject() call */
#define End		TAG_END)
#define EndObject	TAG_END)

/* Classes */
#define WindowObject		NewObject(WINDOW_GetClass(), NULL
#define RequesterObject		NewObject(REQUESTER_GetClass(), NULL
#define ARexxObject		NewObject(AREXX_GetClass(), NULL

#define WindowEnd		TAG_END)
#define EndWindow		TAG_END)
#define RequesterEnd		TAG_END)
#define ARexxEnd		TAG_END)

/* Gadgets */
#define ButtonObject		NewObject(BUTTON_GetClass(), NULL
#define CheckBoxObject		NewObject(CHECKBOX_GetClass(), NULL
#define ChooserObject		NewObject(CHOOSER_GetClass(), NULL
#define ClickTabObject		NewObject(CLICKTAB_GetClass(), NULL
#define DateBrowserObject	NewObject(DATEBROWSER_GetClass(), NULL
#define FuelGaugeObject		NewObject(FUELGAUGE_GetClass(), NULL
#define GetColorObject		NewObject(GETCOLOR_GetClass(), NULL
#define GetFileObject		NewObject(GETFILE_GetClass(), NULL
#define GetFontObject		NewObject(GETFONT_GetClass(), NULL
#define GetScreenModeObject	NewObject(GETSCREENMODE_GetClass(), NULL
#define IntegerObject		NewObject(INTEGER_GetClass(), NULL
#define LayoutObject		NewObject(LAYOUT_GetClass(), NULL
#define ListBrowserObject	NewObject(LISTBROWSER_GetClass(), NULL
#define PageObject		NewObject(PAGE_GetClass(), NULL
#define PaletteObject		NewObject(PALETTE_GetClass(), NULL
#define RadioButtonObject	NewObject(RADIOBUTTON_GetClass(), NULL
#define ScrollerObject		NewObject(SCROLLER_GetClass(), NULL
#define SketchBoardObject	NewObject(SKETCHBOARD_GetClass(), NULL
#define SliderObject		NewObject(SLIDER_GetClass(), NULL
#define SpaceObject		NewObject(SPACE_GetClass(), NULL
#define SpeedBarObject		NewObject(SPEEDBAR_GetClass(), NULL
#define StringObject		NewObject(STRING_GetClass(), NULL
#define TabsObject		NewObject(TABS_GetClass(), NULL
#define TextEditorObject	NewObject(TEXTEDITOR_GetClass(), NULL
#define VirtualObject		NewObject(VIRTUAL_GetClass(), NULL
#define ColorWheelObject	NewObject(NULL, "colorwheel.gadget"
#define GradientSliderObject	NewObject(NULL, "gradientslider.gadget"

#define ButtonEnd		TAG_END)
#define CheckBoxEnd		TAG_END)
#define ChooserEnd		TAG_END)
#define ClickTabEnd		TAG_END)
#define DateBrowserEnd		TAG_END)
#define FuelGaugeEnd		TAG_END)
#define GetColorEnd		TAG_END)
#define GetFileEnd		TAG_END)
#define GetFontEnd		TAG_END)
#define GetScreenModeEnd	TAG_END)
#define IntegerEnd		TAG_END)
#define LayoutEnd		TAG_END)
#define ListBrowserEnd		TAG_END)
#define PageEnd			TAG_END)
#define PaletteEnd		TAG_END)
#define RadioButtonEnd		TAG_END)
#define ScrollerEnd		TAG_END)
#define SketchBoardEnd		TAG_END)
#define SliderEnd		TAG_END)
#define SpaceEnd		TAG_END)
#define SpeedBarEnd		TAG_END)
#define StringEnd		TAG_END)
#define TabsEnd			TAG_END)
#define TextEditorEnd		TAG_END)
#define VirtualEnd		TAG_END)
#define ColorWheelEnd		TAG_END)
#define GradientSliderEnd	TAG_END)

/* Images */
#define BevelObject		NewObject(BEVEL_GetClass(), NULL
#define BitMapObject		NewObject(BITMAP_GetClass(), NULL
#define DrawListObject		NewObject(DRAWLIST_GetClass(), NULL
#define GlyphObject		NewObject(GLYPH_GetClass(), NULL
#define LabelObject		NewObject(LABEL_GetClass(), NULL
#define LEDObject		NewObject(LED_GetClass(), NULL
#define PenMapObject		NewObject(PENMAP_GetClass(), NULL

#define BevelEnd		TAG_END)
#define BitMapEnd		TAG_END)
#define DrawListEnd		TAG_END)
#define GlyphEnd		TAG_END)
#define LabelEnd		TAG_END)
#define LEDEnd			TAG_END)
#define PenMapEnd		TAG_END)
#define EndImage		TAG_END)

/* Groups: a layout laid out across or down */
#define HLayoutObject		LayoutObject, LAYOUT_Orientation, LAYOUT_ORIENT_HORIZ
#define VLayoutObject		LayoutObject, LAYOUT_Orientation, LAYOUT_ORIENT_VERT
#define HGroupObject		HLayoutObject
#define VGroupObject		VLayoutObject
#define EndGroup		TAG_END)

/* Children of a layout */
#define StartMember		LAYOUT_AddChild
#define StartImage		LAYOUT_AddImage
#define EndMember		TAG_END)
#define StartHGroup		LAYOUT_AddChild, HLayoutObject
#define StartVGroup		LAYOUT_AddChild, VLayoutObject
#define StartHLayout		StartHGroup
#define StartVLayout		StartVGroup
#define MemberLabel(text)	CHILD_Label, LabelObject, LABEL_Text, (text), LabelEnd
#define Label(text)		MemberLabel(text)

/* A few common gadgets in one go */
#define Button(text, id)	ButtonObject, GA_ID, (id), GA_Text, (text), GA_RelVerify, TRUE, ButtonEnd
#define PushButton(text, id)	ButtonObject, GA_ID, (id), GA_Text, (text), GA_RelVerify, TRUE, \
				BUTTON_PushButton, TRUE, ButtonEnd
#define TextLine(text)		ButtonObject, GA_Text, (text), GA_ReadOnly, TRUE, \
				BUTTON_BevelStyle, BVS_NONE, BUTTON_Transparent, TRUE, ButtonEnd

/* window.class's methods, through amiga.lib's DoMethod() */
#define RA_OpenWindow(win)	((struct Window *)DoMethod((Object *)(win), WM_OPEN, NULL))
#define RA_CloseWindow(win)	DoMethod((Object *)(win), WM_CLOSE, NULL)
#define RA_HandleInput(win, codeptr) DoMethod((Object *)(win), WM_HANDLEINPUT, (codeptr))
#define RA_Iconify(win)		DoMethod((Object *)(win), WM_ICONIFY, NULL)
#define RA_Uniconify(win)	RA_OpenWindow(win)

/* requester.class's method */
#define RA_OpenRequester(req, win) DoMethod((Object *)(req), RM_OPENREQ, NULL, (win), NULL)

/* Fill in a hook for a ReAction class */
#define RA_SetUpHook(hook, func, data) \
	((hook).h_Entry = (HOOKFUNC)(func), (hook).h_SubEntry = NULL, (hook).h_Data = (APTR)(data))

#endif /* REACTION_REACTION_MACROS_H */
