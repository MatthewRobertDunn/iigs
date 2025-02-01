/********************************************
; File: Window.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif

#ifndef __EVENT__
#include <Event.h>
#endif

#ifndef __CONTROL__
#include <Control.h>
#endif

#ifndef __WINDOW__
#define __WINDOW__

#define paramLenErr 0x0E01 /*error - first word of parameter list is the wrong size */
#define allocateErr 0x0E02 /*error - unable to allocate window record */
#define taskMaskErr 0x0E03 /*error - bits 12-15 are not clear in WmTaskMask field of EventRecord */
#define wNoConstraint 0x0000 /*Axis parameter - No constraint on movement. */
#define wHAxisOnly 0x0001 /*Axis parameter - Horizontal axis only. */
#define wVAxisOnly 0x0002 /*Axis parameter - Vertical axis only. */
#define FromDesk 0x00 /*Desktop Command - Subtract region from desktop */
#define ToDesk 0x1 /*Desktop Command - Add region to desktop */
#define GetDesktop 0x2 /*Desktop Command - Get Handle of Desktop region */
#define SetDesktop 0x3 /*Desktop Command - Set Handle of Desktop region */
#define GetDeskPat 0x4 /*Desktop command - Address of  pattern or drawing routine */
#define SetDeskPat 0x5 /*Desktop command - Change Address of  pattern or drawing routine */
#define GetVisDesktop 0x6 /*Desktop command - Get destop region less visible windows. */
#define BackGroundRgn 0x7 /*Desktop command - For drawing directly on desktop. */
#define toBottom 0xFFFFFFFEL /*SendBehind value - To send window to bottom. */
#define topMost 0xFFFFFFFFL /*SendBehind value - To make window top. */
#define bottomMost 0x0000L /*SendBehind value - To make window bottom. */
#define tmMenuKey 0x0001 /*Task Mask -  */
#define tmUpdate 0x0002 /*Task Mask -  */
#define tmFindW 0x0004 /*Task Mask -  */
#define tmMenuSel 0x0008 /*Task Mask -  */
#define tmOpenNDA 0x0010 /*Task Mask -  */
#define tmSysClick 0x0020 /*Task Mask -  */
#define tmDragW 0x0040 /*Task Mask -  */
#define tmContent 0x0080 /*Task Mask -  */
#define tmClose 0x0100 /*Task Mask -  */
#define tmZoom 0x0200 /*Task Mask -  */
#define tmGrow 0x0400 /*Task Mask -  */
#define tmScroll 0x0800 /*Task Mask -  */
#define tmSpecial 0x1000 /*Task Mask -  */
#define tmCRedraw 0x2000 /*Task Mask -  */
#define tmInactive 0x4000 /*Task Mask -  */
#define tmInfo 0x8000 /*Task Mask -  */
#define wNoHit 0x0000 /*TaskMaster codes - retained for back compatibility.  */
#define inNull 0x0000 /*TaskMaster codes - retained for back compatibility */
#define inKey 0x0003 /*TaskMaster codes - retained for back compatibility */
#define inButtDwn 0x0001 /*TaskMaster codes - retained for back compatibility */
#define inUpdate 0x0006 /*TaskMaster codes - retained for back compatibility */
#define wInDesk 0x0010 /*TaskMaster codes - On Desktop */
#define wInMenuBar 0x0011 /*TaskMaster codes - On system menu bar */
#define wClickCalled 0x0012 /*TaskMaster codes - system click called */
#define wInContent 0x0013 /*TaskMaster codes - In content region */
#define wInDrag 0x0014 /*TaskMaster codes - In drag region */
#define wInGrow 0x0015 /*TaskMaster codes - In grow region, active window only */
#define wInGoAway 0x0016 /*TaskMaster codes - In go-away region, active window only */
#define wInZoom 0x0017 /*TaskMaster codes - In zoom region, active window only */
#define wInInfo 0x0018 /*TaskMaster codes - In information bar */
#define wInSpecial 0x0019 /*TaskMaster codes - Item ID selected was 250 - 255 */
#define wInDeskItem 0x001A /*TaskMaster codes - Item ID selected was 1 - 249 */
#define wInFrame 0x1B /*TaskMaster codes - in Frame, but not on anything else */
#define wInactMenu 0x1C /*TaskMaster codes - "selection" of inactive menu item */
#define wClosedNDA 0x001D /*TaskMaster codes - desk accessory closed */
#define wCalledSysEdit 0x001E /*TaskMaster codes - inactive menu item selected */
#define wInSysWindow 0x8000 /*TaskMaster codes - hi bit set for system windows */
#define wDraw 0x00 /*VarCode - Draw window frame command. */
#define wHit 0x01 /*VarCode - Hit test command. */
#define wCalcRgns 0x02 /*VarCode - Compute regions command. */
#define wNew 0x03 /*VarCode - Initialization command. */
#define wDispose 0x04 /*VarCode - Dispose command. */
#define fHilited 0x0001 /*WFrame - Window is highlighted. */
#define fZoomed 0x0002 /*WFrame - Window is zoomed. */
#define fAllocated 0x0004 /*WFrame - Window record was allocated. */
#define fCtlTie 0x0008 /*WFrame - Window state tied to controls. */
#define fInfo 0x0010 /*WFrame - Window has an information bar. */
#define fVis 0x0020 /*WFrame - Window is visible. */
#define fQContent 0x0040 /*WFrame -  */
#define fMove 0x0080 /*WFrame - Window is movable. */
#define fZoom 0x0100 /*WFrame - Window is zoomable. */
#define fFlex 0x0200 /*WFrame -  */
#define fGrow 0x0400 /*WFrame - Window has grow box. */
#define fBScroll 0x0800 /*WFrame - Window has horizontal scroll bar. */
#define fRScroll 0x1000 /*WFrame - Window has vertical scroll bar. */
#define fAlert 0x2000 /*WFrame -  */
#define fClose 0x4000 /*WFrame - Window has a close box. */
#define fTitle 0x8000 /*WFrame - Window has a title bar. */
#define windSize 0x145 /*WindRec - Size of WindRec. */
#define wmTaskRecSize 0x0046 /*WmTaskRec - Size of WmTaskRec. */
#define wTrackZoom 0x001F /* -  */
#define wHitFrame 0x0020 /* -  */
#define wInControl 0x0021 /* -  */
typedef EventRecord WmTaskRec;
typedef EventRecordPtr WmTaskRecPtr;
struct WindColor {
   Word frameColor; /* Color of window frame. */
   Word titleColor; /* Color of title and bar. */
   Word tBarColor; /* Color/pattern of title bar. */
   Word growColor; /* Color of grow box. */
   Word infoColor; /* Color of information bar. */
} ;
typedef struct WindColor WindColor, *WindColorPtr, **WindColorHndl;
struct WindRec {
   GrafPort port; /* Window's port */
   ProcPtr wDefProc; /*  */
   LongWord wRefCon; /*  */
   ProcPtr wContDraw; /*  */
   LongWord wReserved; /* Space for future expansion */
   RgnHandle wStrucRgn; /* Region of frame plus content. */
   RgnHandle wContRgn; /* Content region. */
   RgnHandle wUpdateRgn; /* Update region. */
   CtlRecHndl wControls; /* Window's control list. */
   CtlRecHndl wFrameCtrls; /* Window frame's control list. */
   Word wFrame; /*   */
} ;
typedef struct WindRec WindRec, *WindRecPtr;
struct WindowChain {
   struct WindowChain *wNext; /*   */
   WindRec theWindow; /*   */
} ;
typedef struct WindowChain WindowChain, *WindowChainPtr;
struct ParamList {
   Word paramLength; /* Parameter to NewWindow.  */
   Word wFrameBits; /* Parameter to NewWindow. */
   Pointer wTitle; /* Parameter to NewWindow. */
   LongWord wRefCon; /* Parameter to NewWindow. */
   Rect wZoom; /* Parameter to NewWindow. */
   WindColorPtr wColor; /* Parameter to NewWindow. */
   Word wYOrigin; /* Parameter to NewWindow. */
   Word wXOrigin; /* Parameter to NewWindow. */
   Word wDataH; /* Parameter to NewWindow. */
   Word wDataW; /* Parameter to NewWindow. */
   Word wMaxH; /* Parameter to NewWindow. */
   Word wMaxW; /* Parameter to NewWindow. */
   Word wScrollVer; /* Parameter to NewWindow. */
   Word wScrollHor; /* Parameter to NewWindow. */
   Word wPageVer; /* Parameter to NewWindow. */
   Word wPageHor; /* Parameter to NewWindow. */
   LongWord wInfoRefCon; /* Parameter to NewWindow. */
   Word wInfoHeight; /* height of information bar */
   LongProcPtr wFrameDefProc; /* Parameter to NewWindow. */
   VoidProcPtr wInfoDefProc; /* Parameter to NewWindow. */
   VoidProcPtr wContDefProc; /* Parameter to NewWindow. */
   Rect wPosition; /* Parameter to NewWindow. */
   WindowPtr wPlane; /* Parameter to NewWindow. */
   WindowChainPtr wStorage; /* Parameter to NewWindow. */
} ;
typedef struct ParamList ParamList, *ParamListPtr, **ParamListHndl;
struct DeskMessageRecord {
   LongWord reserved; /*   */
   Word messageType; /*   */
   Word drawType; /*   */
} ;
typedef struct DeskMessageRecord DeskMessageRecord, *DeskMessageRecordPtr;
extern pascal Word AlertWindow () inline(0x590E,dispatcher);
extern pascal void DrawInfoBar () inline(0x550E,dispatcher);
extern pascal void EndFrameDrawing () inline(0x5B0E,dispatcher);
extern pascal LongWord GetWindowMgrGlobals () inline(0x580E,dispatcher);
extern pascal void ResizeWindow () inline(0x5C0E,dispatcher);
extern pascal void StartFrameDrawing () inline(0x5A0E,dispatcher);
extern pascal void WindBootInit () inline(0x010E,dispatcher);
extern pascal void WindStartUp () inline(0x020E,dispatcher);
extern pascal void WindShutDown () inline(0x030E,dispatcher);
extern pascal Word WindVersion () inline(0x040E,dispatcher);
extern pascal void WindReset () inline(0x050E,dispatcher);
extern pascal Boolean WindStatus () inline(0x060E,dispatcher);
extern pascal void BeginUpdate () inline(0x1E0E,dispatcher);
extern pascal void BringToFront () inline(0x240E,dispatcher);
extern pascal Boolean CheckUpdate () inline(0x0A0E,dispatcher);
extern pascal void CloseWindow () inline(0x0B0E,dispatcher);
extern pascal Pointer Desktop () inline(0x0C0E,dispatcher);
extern pascal void DragWindow () inline(0x1A0E,dispatcher);
extern pascal void EndInfoDrawing () inline(0x510E,dispatcher);
extern pascal void EndUpdate () inline(0x1F0E,dispatcher);
extern pascal Word FindWindow () inline(0x170E,dispatcher);
extern pascal WindowPtr FrontWindow () inline(0x150E,dispatcher);
extern pascal VoidProcPtr GetContentDraw () inline(0x480E,dispatcher);
extern pascal Long GetContentOrigin () inline(0x3E0E,dispatcher);
extern pascal RgnHandle GetContentRgn () inline(0x2F0E,dispatcher);
extern pascal LongWord GetDataSize () inline(0x400E,dispatcher);
extern pascal LongProcPtr GetDefProc () inline(0x310E,dispatcher);
extern pascal WindowPtr GetFirstWindow () inline(0x520E,dispatcher);
extern pascal void GetFrameColor () inline(0x100E,dispatcher);
extern pascal VoidProcPtr GetInfoDraw () inline(0x4A0E,dispatcher);
extern pascal LongWord GetInfoRefCon () inline(0x350E,dispatcher);
extern pascal LongWord GetMaxGrow () inline(0x420E,dispatcher);
extern pascal WindowPtr GetNextWindow () inline(0x2A0E,dispatcher);
extern pascal LongWord GetPage () inline(0x460E,dispatcher);
extern pascal void GetRectInfo () inline(0x4F0E,dispatcher);
extern pascal LongWord GetScroll () inline(0x440E,dispatcher);
extern pascal RgnHandle GetStructRgn () inline(0x2E0E,dispatcher);
extern pascal Boolean GetSysWFlag () inline(0x4C0E,dispatcher);
extern pascal RgnHandle GetUpdateRgn () inline(0x300E,dispatcher);
extern pascal CtlRecHndl GetWControls () inline(0x330E,dispatcher);
extern pascal Word GetWFrame () inline(0x2C0E,dispatcher);
extern pascal Word GetWKind () inline(0x2B0E,dispatcher);
extern pascal WindowPtr GetWMgrPort () inline(0x200E,dispatcher);
extern pascal LongWord GetWRefCon () inline(0x290E,dispatcher);
extern pascal Pointer GetWTitle () inline(0x0E0E,dispatcher);
extern pascal Rect *GetZoomRect () inline(0x370E,dispatcher);
extern pascal LongWord GrowWindow () inline(0x1B0E,dispatcher);
extern pascal void HideWindow () inline(0x120E,dispatcher);
extern pascal void HiliteWindow () inline(0x220E,dispatcher);
extern pascal void InvalRect () inline(0x3A0E,dispatcher);
extern pascal void InvalRgn () inline(0x3B0E,dispatcher);
extern pascal void MoveWindow () inline(0x190E,dispatcher);
extern pascal WindowPtr NewWindow () inline(0x090E,dispatcher);
extern pascal Long PinRect () inline(0x210E,dispatcher);
extern pascal void RefreshDesktop () inline(0x390E,dispatcher);
extern pascal void SelectWindow () inline(0x110E,dispatcher);
extern pascal void SendBehind () inline(0x140E,dispatcher);
extern pascal void SetContentDraw () inline(0x490E,dispatcher);
extern pascal void SetContentOrigin () inline(0x3F0E,dispatcher);
extern pascal void SetContentOrigin2 () inline(0x570E,dispatcher);
extern pascal void SetDataSize () inline(0x410E,dispatcher);
extern pascal void SetDefProc () inline(0x320E,dispatcher);
extern pascal void SetFrameColor () inline(0x0F0E,dispatcher);
extern pascal void SetInfoDraw () inline(0x160E,dispatcher);
extern pascal void SetInfoRefCon () inline(0x360E,dispatcher);
extern pascal void SetMaxGrow () inline(0x430E,dispatcher);
extern pascal void SetOriginMask () inline(0x340E,dispatcher);
extern pascal void SetPage () inline(0x470E,dispatcher);
extern pascal void SetScroll () inline(0x450E,dispatcher);
extern pascal void SetSysWindow () inline(0x4B0E,dispatcher);
extern pascal void SetWFrame () inline(0x2D0E,dispatcher);
extern pascal FontHndl SetWindowIcons () inline(0x4E0E,dispatcher);
extern pascal void SetWRefCon () inline(0x280E,dispatcher);
extern pascal void SetWTitle () inline(0x0D0E,dispatcher);
extern pascal void SetZoomRect () inline(0x380E,dispatcher);
extern pascal void ShowHide () inline(0x230E,dispatcher);
extern pascal void ShowWindow () inline(0x130E,dispatcher);
extern pascal void SizeWindow () inline(0x1C0E,dispatcher);
extern pascal void StartDrawing () inline(0x4D0E,dispatcher);
extern pascal void StartInfoDrawing () inline(0x500E,dispatcher);
extern pascal Word TaskMaster () inline(0x1D0E,dispatcher);
extern pascal Boolean TrackGoAway () inline(0x180E,dispatcher);
extern pascal Boolean TrackZoom () inline(0x260E,dispatcher);
extern pascal void ValidRect () inline(0x3C0E,dispatcher);
extern pascal void ValidRgn () inline(0x3D0E,dispatcher);
extern pascal LongWord WindDragRect () inline(0x530E,dispatcher);
extern pascal void WindNewRes () inline(0x250E,dispatcher);
extern pascal Word WindowGlobal () inline(0x560E,dispatcher);
extern pascal void ZoomWindow () inline(0x270E,dispatcher);
extern pascal Word TaskMasterDA () inline(0x5F0E,dispatcher);
extern pascal Handle CompileText () inline(0x600E,dispatcher);
extern pascal WindowPtr NewWindow2 () inline(0x610E,dispatcher);
extern pascal Word ErrorWindow () inline(0x620E,dispatcher);
#endif
