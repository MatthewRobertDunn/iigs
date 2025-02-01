/********************************************
; File: Control.h
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
#define __CONTROL__

#define wmNotStartedUp 0x1001 /*error - Window manager was not started first. */
#define noConstraint 0x0000 /*Axis Parameter - No constraint on movement. */
#define hAxisOnly 0x0001 /*Axis Parameter - Horizontal axis only. */
#define vAxisOnly 0x0002 /*Axis Parameter - Vertical axis only. */
#define simpRound 0x0000 /*CtlFlag - Simple button flag */
#define upFlag 0x0001 /*CtlFlag - Scroll bar flag.  */
#define boldButton 0x0001 /*CtlFlag - Bold round cornered outlined button. */
#define simpBRound 0x0001 /*CtlFlag - Simple button flag */
#define downFlag 0x0002 /*CtlFlag - Scroll bar flag. */
#define simpSquare 0x0002 /*CtlFlag - Simple button flag */
#define simpDropSquare 0x0003 /*CtlFlag - Simple button flag */
#define leftFlag 0x0004 /*CtlFlag - Scroll bar flag. */
#define rightFlag 0x0008 /*CtlFlag - Scroll bar flag. */
#define dirScroll 0x0010 /*CtlFlag - Scroll bar flag. */
#define horScroll 0x0010 /*CtlFlag - Scroll bar flag. */
#define family 0x007F /*CtlFlag - Mask for radio button family number */
#define ctlInVis 0x0080 /*CtlFlag - invisible mask for any type of control  */
#define inListBox 0x88 /*CtlFlag -  */
#define simpleProc 0x00000000L /*CtlProc -  */
#define checkProc 0x02000000L /*CtlProc -  */
#define radioProc 0x04000000L /*CtlProc -  */
#define scrollProc 0x06000000L /*CtlProc -  */
#define growProc 0x08000000L /*CtlProc -  */
#define drawCtl 0x0000 /*DefProc - Draw control command. */
#define calcCRect 0x0001 /*DefProc - Compute drag RECT command. */
#define testCtl 0x0002 /*DefProc - Hit test command. */
#define initCtl 0x0003 /*DefProc - Initialize command. */
#define dispCtl 0x0004 /*DefProc - Dispose command. */
#define posCtl 0x0005 /*DefProc - Move indicator command. */
#define thumbCtl 0x0006 /*DefProc - Compute drag parameters command. */
#define dragCtl 0x0007 /*DefProc - Drag command. */
#define autoTrack 0x0008 /*DefProc - Action command. */
#define newValue 0x0009 /*DefProc - Set new value command. */
#define setParams 0x000A /*DefProc - Set new parameters command. */
#define moveCtl 0x000B /*DefProc - Move command. */
#define recSize 0x000C /*DefProc - Return record size command. */
#define noHilite 0x0000 /*hiliteState - Param to HiliteControl */
#define inactiveHilite 0x00FF /*hiliteState - Param to HiliteControl */
#define noPart 0x0000 /*PartCode -  */
#define simpleButton 0x0002 /*PartCode -  */
#define checkBox 0x0003 /*PartCode -  */
#define radioButton 0x0004 /*PartCode -  */
#define upArrow 0x0005 /*PartCode -  */
#define downArrow 0x0006 /*PartCode -  */
#define pageUp 0x0007 /*PartCode -  */
#define pageDown 0x0008 /*PartCode -  */
#define growBox 0x000A /*PartCode -  */
#define thumb 0x0081 /*PartCode -  */
#define fCtlTarget 0x8000 /*CtlRec.ctlMoreFlags - is current target of typing commands */
#define fCtlCanBeTarget 0x4000 /*CtlRec.ctlMoreFlags - can be made the target control */
#define fCtlWantEvents 0x2000 /*CtlRec.ctlMoreFlags - control can be called view SendEventToCtl */
#define fCtlProcRefNotPtr 0x1000 /*CtlRec.ctlMoreFlags - set = ID of defproc, clear = pointer to defproc */
#define fCtlTellAboutSize 0x0800 /*CtlRec.ctlMoreFlags - set if ctl needs notification when size of owning window changes */
#define fCtlIsMultiPar 0x0400 /*CtlRec.ctlMoreFlags - set if ctl needs notification to be hidden */
#define titleIsPtr 0x00 /*Ctl Verb -  */
#define titleIsHandle 0x01 /*Ctl Verb -  */
#define titleIsResource 0x02 /*Ctl Verb -  */
#define colorTableIsPtr 0x00 /*Ctl Verb -  */
#define colorTableIsHandle 0x04 /*Ctl Verb -  */
#define colorTableIsResource 0x08 /*Ctl Verb -  */
#define ctlHandleEvent 0x0D /*DefProc message -  */
#define ctlChangeTarget 0x0E /*DefProc message -  */
#define ctlChangeBounds 0x0F /*DefProc message -  */
#define ctlWindChangeSize 0x10 /*DefProc message -  */
#define ctlHandleTab 0x11 /*DefProc message -  */
#define ctlHideCtl 0x12 /*DefProc message -  */
#define singlePtr 0x0000 /*InputVerb -  */
#define singleHandle 0x0001 /*InputVerb -  */
#define singleResource 0x0002 /*InputVerb -  */
#define ptrToPtr 0x0003 /*InputVerb -  */
#define ptrToHandle 0x0004 /*InputVerb -  */
#define ptrToResource 0x0005 /*InputVerb -  */
#define handleToPtr 0x0006 /*InputVerb -  */
#define handleToHandle 0x0007 /*InputVerb -  */
#define handleToResource 0x0008 /*InputVerb -  */
#define resourceToResource 0x0009 /*InputVerb -  */
#define simpleButtonControl 0x80000000L /*ProcRefs -  */
#define checkControl 0x82000000L /*ProcRefs -  */
#define radioControl 0x84000000L /*ProcRefs -  */
#define scrollBarControl 0x86000000L /*ProcRefs -  */
#define growControl 0x88000000L /*ProcRefs -  */
#define statTextControl 0x81000000L /*ProcRefs -  */
#define editLineControl 0x83000000L /*ProcRefs -  */
#define editTextControl 0x85000000L /*ProcRefs -  */
#define popUpControl 0x87000000L /*ProcRefs -  */
#define listControl 0x89000000L /*ProcRefs -  */
#define iconButtonControl 0x07FF0001L /*ProcRefs -  */
#define pictureControl 0x8D000000L /*ProcRefs -  */
#define noCtlError 0x1004 /*Error - no controls in window */
#define noSuperCtlError 0x1005 /*Error - no super controls in window */
#define noCtlTargetError 0x1006 /*Error - no target super control */
#define notSuperCtlError 0x1007 /*Error - action can only be done on super control */
#define canNotBeTargetError 0x1008 /*Error - conrol cannot be made target */
#define noSuchIDError 0x1009 /*Error - specified ID cannot be found */
#define tooFewParmsError 0x100A /*Error - not enough params specified */
#define noCtlToBeTargetError 0x100B /*Error - NextCtl call, no ctl could be target */
#define noWind_Err 0x100C /*Error - there is no front window */
#ifndef WindowPtr
typedef GrafPortPtr WindowPtr;
#endif

struct BarColors {
   Word barOutline; /* color for outlining bar, arrows, and thumb */
   Word barNorArrow; /* color of arrows when not highlighted */
   Word barSelArrow; /* color of arrows when highlighted */
   Word barArrowBack; /* color of arrow box's background */
   Word barNorThumb; /* color of thumb's background when not highlighted */
   Word barSelThumb; /* color of thumb's background when highlighted */
   Word barPageRgn; /* color and pattern page region: high byte - 1= dither, 0 = solid */
   Word barInactive; /* color of scroll bar's interior when inactive */
} ;
typedef struct BarColors BarColors, *BarColorsPtr, **BarColorsHndl;
struct BoxColors {
   Word boxReserved; /* reserved */
   Word boxNor; /* color of box when not checked */
   Word boxSel; /* color of box when checked */
   Word boxTitle; /* color of check box's title */
} ;
typedef struct BoxColors BoxColors, *BoxColorsPtr, **BoxColorsHndl;
struct BttnColors {
   Word bttnOutline; /* color of outline */
   Word bttnNorBack; /* color of background when not selected */
   Word bttnSelBack; /* color of background when selected */
   Word bttnNorText; /* color of title's text when not selected */
   Word bttnSelText; /* color of title's text when selected */
} ;
typedef struct BttnColors BttnColors, *BttnColorsPtr, **BttnColorsHndl;
struct CtlRec {
   struct CtlRec **ctlNext; /* Handle of next control. */
   WindowPtr ctlOwner; /* Pointer to control's window. */
   Rect ctlRect; /* Enclosing rectangle. */
   Byte ctlFlag; /* Bit flags. */
   Byte ctlHilite; /* Highlighted part. */
   Word ctlValue; /* Control's value. */
   LongProcPtr ctlProc; /* Control's definition procedure. */
   LongProcPtr ctlAction; /* Control's action procedure. */
   Longint ctlData; /* Reserved for CtrlProc's use. */
   Longint ctlRefCon; /* Reserved for application's use. */
   Pointer ctlColor; /* Pointer to appropriate color table. */
   Byte ctlReserved[16]; /* Reserved for future expansion */
   LongWord ctlID; /*  */
   Word ctlMoreFlags; /*  */
   Word ctlVersion; /*  */
} ;
typedef struct CtlRec CtlRec, *CtlRecPtr, **CtlRecHndl, ***CtlRecHndlPtr;
struct LimitBlk {
   Rect boundRect; /* Drag bounds. */
   Rect slopRect; /* Cursor bounds. */
   Word axisParam; /* Movement constrains. */
   Pointer dragPatt; /* Pointer to 32 byte Pattern for drag outline. */
} ;
typedef struct LimitBlk LimitBlk, *LimitBlkPtr, **LimitBlkHndl;
struct RadioColors {
   Word radReserved; /* reserved */
   Word radNor; /* color of radio button when off */
   Word radSel; /* color of radio button when on */
   Word radTitle; /* color of radio button's title text */
} ;
typedef struct RadioColors RadioColors, *RadioColorsPtr, **RadioColorsHndl;
extern pascal void CtlBootInit () inline(0x0110,dispatcher);
extern pascal void CtlStartUp () inline(0x0210,dispatcher);
extern pascal void CtlShutDown () inline(0x0310,dispatcher);
extern pascal Word CtlVersion () inline(0x0410,dispatcher);
extern pascal void CtlReset () inline(0x0510,dispatcher);
extern pascal Boolean CtlStatus () inline(0x0610,dispatcher);
extern pascal void CtlNewRes () inline(0x1210,dispatcher);
extern pascal void DisposeControl () inline(0x0A10,dispatcher);
extern pascal void DragControl () inline(0x1710,dispatcher);
extern pascal LongWord DragRect () inline(0x1D10,dispatcher);
extern pascal void DrawControls () inline(0x1010,dispatcher);
extern pascal void DrawOneCtl () inline(0x2510,dispatcher);
extern pascal void EraseControl () inline(0x2410,dispatcher);
extern pascal Word FindControl () inline(0x1310,dispatcher);
extern pascal LongProcPtr GetCtlAction () inline(0x2110,dispatcher);
extern pascal Word GetCtlDPage () inline(0x1F10,dispatcher);
extern pascal LongWord GetCtlParams () inline(0x1C10,dispatcher);
extern pascal LongWord GetCtlRefCon () inline(0x2310,dispatcher);
extern pascal Pointer GetCtlTitle () inline(0x0D10,dispatcher);
extern pascal Word GetCtlValue () inline(0x1A10,dispatcher);
extern pascal LongWord GrowSize () inline(0x1E10,dispatcher);
extern pascal void HideControl () inline(0x0E10,dispatcher);
extern pascal void HiliteControl () inline(0x1110,dispatcher);
extern pascal void KillControls () inline(0x0B10,dispatcher);
extern pascal void MoveControl () inline(0x1610,dispatcher);
extern pascal CtlRecHndl NewControl () inline(0x0910,dispatcher);
extern pascal void SetCtlAction () inline(0x2010,dispatcher);
extern pascal FontHndl SetCtlIcons () inline(0x1810,dispatcher);
extern pascal void SetCtlParams () inline(0x1B10,dispatcher);
extern pascal void SetCtlRefCon () inline(0x2210,dispatcher);
extern pascal void SetCtlTitle () inline(0x0C10,dispatcher);
extern pascal void SetCtlValue () inline(0x1910,dispatcher);
extern pascal void ShowControl () inline(0x0F10,dispatcher);
extern pascal Word TestControl () inline(0x1410,dispatcher);
extern pascal Word TrackControl () inline(0x1510,dispatcher);
extern pascal CtlRecHndl NewControl2 () inline(0x3110,dispatcher);
extern pascal CtlRecHndl FindTargetCtl () inline(0x2610,dispatcher);
extern pascal CtlRecHndl MakeNextCtlTarget () inline(0x2710,dispatcher);
extern pascal void MakeThisCtlTarget () inline(0x2810,dispatcher);
extern pascal void CallCtlDefProc () inline(0x2C10,dispatcher);
extern pascal void NotifyControls () inline(0x2D10,dispatcher);
extern pascal Boolean SendEventToCtl () inline(0x2910,dispatcher);
extern pascal LongWord GetCtlID () inline(0x2A10,dispatcher);
extern pascal void SetCtlID () inline(0x2B10,dispatcher);
extern pascal LongWord GetCtlMoreFlags () inline(0x2E10,dispatcher);
extern pascal LongWord SetCtlMoreFlags () inline(0x2F10,dispatcher);
extern pascal CtlRecHndl GetCtlHandleFromID () inline(0x3010,dispatcher);
extern pascal void SetCtlParamPtr () inline(0x3410,dispatcher);
extern pascal Pointer GetCtlParamPtr () inline(0x3510,dispatcher);
extern pascal Handle CMLoadResource () inline(0x3210,dispatcher);
extern pascal void CMReleaseResource () inline(0x3310,dispatcher);
extern pascal void InvalCtls () inline(0x3710,dispatcher);
extern pascal void NotifyCtls() inline(0x2D10,dispatcher);
#endif
