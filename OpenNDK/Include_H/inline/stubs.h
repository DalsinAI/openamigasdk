#ifndef __INLINE_STUB_H
#define __INLINE_STUB_H
/*
 * OpenNDK: what inline headers written on inline/macros.h take for granted:
 * the common OS headers, and a declaration of every structure a call takes
 * a pointer to, so a prototype never declares one inside its parameter list.
 * Copyright (c) 2026 AmigaChrome Team. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef GRAPHICS_DISPLAYINFO_H
#include <graphics/displayinfo.h>
#endif
#ifndef LIBRARIES_COMMODITIES_H
#include <libraries/commodities.h>
#endif

struct AnchorPath;
struct AnimOb;
struct AreaInfo;
struct BitMap;
struct BitScaleArgs;
struct bltnode;
struct Bob;
struct Border;
struct CardHandle;
struct Catalog;
struct ClipboardHandle;
struct ClipRect;
struct ClockData;
struct ColorMap;
struct ColorWheelHSB;
struct ColorWheelRGB;
struct ConfigDev;
struct CopList;
struct cprlist;
struct CSource;
struct CurrentBinding;
struct DataBase;
struct DateStamp;
struct DateTime;
struct Device;
struct DeviceNode;
struct DeviceTData;
struct DevProc;
struct DiskObject;
struct DosLibrary;
struct DosList;
struct DosPacket;
struct DrawInfo;
struct dtPrint;
struct EasyStruct;
struct EClockVal;
struct ExAllControl;
struct ExAllData;
struct ExecBase;
struct ExpansionBase;
struct FileInfoBlock;
struct FileLock;
struct FileRequester;
struct FontContentsHeader;
struct FreeList;
struct Gadget;
struct GadgetInfo;
struct GelsInfo;
struct GfxBase;
struct GlyphEngine;
struct GlyphMap;
struct gpLayout;
struct HelpNode;
struct Hook;
struct IClass;
struct Image;
struct InfoData;
struct InputEvent;
struct Interrupt;
struct IntuiText;
struct IntuitionBase;
struct IORequest;
struct KeyMap;
struct KeyQuery;
struct Layer;
struct Layer_Info;
struct Library;
struct List;
struct Locale;
struct LocaleBase;
struct MathIEEEBase;
struct MemHeader;
struct MemList;
struct Menu;
struct MenuItem;
struct Message;
struct MiscResource;
struct MsgPort;
struct NamedObject;
struct NewAmigaGuide;
struct NewGadget;
struct NewMenu;
struct NewScreen;
struct NewWindow;
struct Node;
struct NotifyRequest;
struct Preferences;
struct RastPort;
struct RDArgs;
struct RealTimeBase;
struct RecordLock;
struct Rectangle;
struct Region;
struct Remember;
struct ReqToolsBase;
struct Requester;
struct Resident;
struct RexxMsg;
struct RomBootBase;
struct RxsLib;
struct Screen;
struct Semaphore;
struct SignalSemaphore;
struct SimpleSprite;
struct TagItem;
struct Task;
struct TextAttr;
struct TextExtent;
struct TextFont;
struct timeval;
struct UCopList;
struct View;
struct ViewPort;
struct VSprite;
struct WBObject;
struct Window;

#endif /* __INLINE_STUB_H */
