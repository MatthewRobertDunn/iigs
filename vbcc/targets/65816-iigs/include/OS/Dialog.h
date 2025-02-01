/********************************************
; File: Dialog.h
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
#include <Window.h>
#endif

#ifndef __LINEEDIT__
#include <LineEdit.h>
#endif

#ifndef __DIALOG__
#define __Dialog__

#define badItemType 0x150A /*error -  */
#define newItemFailed 0x150B /*error -  */
#define itemNotFound 0x150C /*error -  */
#define notModalDialog 0x150D /*error -  */
#define getInitView 0x0001 /*Command -  */
#define getInitTotal 0x0002 /*Command -  */
#define getInitValue 0x0003 /*Command -  */
#define scrollLineUp 0x0004 /*Command -  */
#define scrollLineDown 0x0005 /*Command -  */
#define scrollPageUp 0x0006 /*Command -  */
#define scrollPageDown 0x0007 /*Command -  */
#define scrollThumb 0x0008 /*Command -  */
#define buttonItem 0x000A /*Item Type -  */
#define checkItem 0x000B /*Item Type -  */
#define radioItem 0x000C /*Item Type -  */
#define scrollBarItem 0x000D /*Item Type -  */
#define userCtlItem 0x000E /*Item Type -  */
#define statText 0x000F /*Item Type -  */
#define longStatText 0x0010 /*Item Type -  */
#define editLine 0x0011 /*Item Type -  */
#define iconItem 0x0012 /*Item Type -  */
#define picItem 0x0013 /*Item Type -  */
#define userItem 0x0014 /*Item Type -  */
#define userCtlItem2 0x0015 /*Item Type -  */
#define longStatText2 0x0016 /*Item Type -  */
#define itemDisable 0x8000 /*Item Type -  */
#define minItemType 0x000A /*Item Type Range -  */
#define maxItemType 0x0016 /*Item Type Range -  */
#define ok 0x0001 /*ItemID -  */
#define cancel 0x0002 /*ItemID -  */
#define inButton 0x0002 /*ModalDialog2 - Part code */
#define inCheckBox 0x0003 /*ModalDialog2 - Part code */
#define inRadioButton 0x0004 /*ModalDialog2 - Part code */
#define inUpArrow 0x0005 /*ModalDialog2 - Part code */
#define inDownArrow 0x0006 /*ModalDialog2 - Part code */
#define inPageUp 0x0007 /*ModalDialog2 - Part code */
#define inPageDown 0x0008 /*ModalDialog2 - Part code */
#define inStatText 0x0009 /*ModalDialog2 - Part code */
#define inGrow 0x000A /*ModalDialog2 - Part code */
#define inEditLine 0x000B /*ModalDialog2 - Part code */
#define inUserItem 0x000C /*ModalDialog2 - Part code */
#define inLongStatText 0x000D /*ModalDialog2 - Part code */
#define inIconItem 0x000E /*ModalDialog2 - Part code */
#define inLongStatText2 0x000F /*ModalDialog2 -  */
#define inThumb 0x0081 /*ModalDialog2 - Part code */
#define okDefault 0x0000 /*Stage Bit Vector -  */
#define cancelDefault 0x0040 /*Stage Bit Vector -  */
#define alertDrawn 0x0080 /*Stage Bit Vector -  */
typedef WindowPtr DialogPtr;
struct ItemTemplate {
   Word itemID; /*  */
   Rect itemRect; /*  */
   Word itemType; /*  */
   Pointer itemDescr; /*  */
   Word itemValue; /*  */
   Word itemFlag; /*  */
   Pointer itemColor; /* pointer to appropriate type of color table */
} ;
typedef struct ItemTemplate ItemTemplate, *ItemTempPtr, **ItemTempHndl;

#ifndef atItemListLength
#define  atItemListLength  0x5   /*AlertTemplate  - Default number of Item Templates */
#endif
struct AlertTemplate {
   Rect atBoundsRect; /*  */
   Word atAlertID; /*  */
   Byte atStage1; /*  */
   Byte atStage2; /*  */
   Byte atStage3; /*  */
   Byte atStage4; /*  */
   ItemTempPtr atItemList[atItemListLength]; /* Null terminated array */
} ;
typedef struct AlertTemplate AlertTemplate, *AlertTempPtr, **AlertTempHndl;

#ifndef dtItemListLength
#define  dtItemListLength  0x8   /*DialogTemplate  - Default number of Item Templates */
#endif
struct DialogTemplate {
   Rect dtBoundsRect; /*  */
   Boolean dtVisible; /*  */
   Longint dtRefCon; /*  */
   ItemTempPtr dtItemList[dtItemListLength]; /* Null terminated array */
} ;
typedef struct DialogTemplate DialogTemplate, *DlgTempPtr;
struct IconRecord {
   Rect iconRect; /*  */
   Byte iconImage[1]; /*  */
} ;
typedef struct IconRecord IconRecord, *IconRecordPtr, **IconRecordHndl;
struct UserCtlItemPB {
   Longint defProcParm; /* ? should this be a LongProcPtr? */
   Pointer titleParm; /*  */
   Word param2; /*  */
   Word param1; /*  */
} ;
typedef struct UserCtlItemPB UserCtlItemPB, *UserCtlItemPBPtr, **UserCtlItemPBHndl;
extern pascal void DialogBootInit () inline(0x0115,dispatcher);
extern pascal void DialogStartUp () inline(0x0215,dispatcher);
extern pascal void DialogShutDown () inline(0x0315,dispatcher);
extern pascal Word DialogVersion () inline(0x0415,dispatcher);
extern pascal void DialogReset () inline(0x0515,dispatcher);
extern pascal Boolean DialogStatus () inline(0x0615,dispatcher);
extern pascal Word Alert () inline(0x1715,dispatcher);
extern pascal Word CautionAlert () inline(0x1A15,dispatcher);
extern pascal void CloseDialog () inline(0x0C15,dispatcher);
extern pascal Boolean DefaultFilter () inline(0x3615,dispatcher);
extern pascal Boolean DialogSelect () inline(0x1115,dispatcher);
extern pascal void DisableDItem () inline(0x3915,dispatcher);
extern pascal void DlgCopy () inline(0x1315,dispatcher);
extern pascal void DlgCut () inline(0x1215,dispatcher);
extern pascal void DlgDelete () inline(0x1515,dispatcher);
extern pascal void DlgPaste () inline(0x1415,dispatcher);
extern pascal void DrawDialog () inline(0x1615,dispatcher);
extern pascal void EnableDItem () inline(0x3A15,dispatcher);
extern pascal void ErrorSound () inline(0x0915,dispatcher);
extern pascal Word FindDItem () inline(0x2415,dispatcher);
extern pascal Word GetAlertStage () inline(0x3415,dispatcher);
extern pascal CtlRecHndl GetControlDItem () inline(0x1E15,dispatcher);
extern pascal Word GetDefButton () inline(0x3715,dispatcher);
extern pascal void GetDItemBox () inline(0x2815,dispatcher);
extern pascal Word GetDItemType () inline(0x2615,dispatcher);
extern pascal Word GetDItemValue () inline(0x2E15,dispatcher);
extern pascal Word GetFirstDItem () inline(0x2A15,dispatcher);
extern pascal void GetIText () inline(0x1F15,dispatcher);
extern pascal void GetNewDItem () inline(0x3315,dispatcher);
extern pascal DialogPtr GetNewModalDialog () inline(0x3215,dispatcher);
extern pascal Word GetNextDItem () inline(0x2B15,dispatcher);
extern pascal void HideDItem () inline(0x2215,dispatcher);
extern pascal Boolean IsDialogEvent () inline(0x1015,dispatcher);
extern pascal Word ModalDialog () inline(0x0F15,dispatcher);
extern pascal LongWord ModalDialog2 () inline(0x2C15,dispatcher);
extern pascal void NewDItem () inline(0x0D15,dispatcher);
extern pascal DialogPtr NewModalDialog () inline(0x0A15,dispatcher);
extern pascal DialogPtr NewModelessDialog () inline(0x0B15,dispatcher);
extern pascal Word NoteAlert () inline(0x1915,dispatcher);
extern pascal void ParamText () inline(0x1B15,dispatcher);
extern pascal void RemoveDItem () inline(0x0E15,dispatcher);
extern pascal void ResetAlertStage () inline(0x3515,dispatcher);
extern pascal void SelIText () inline(0x2115,dispatcher);
extern pascal void SelectIText () inline(0x2115,dispatcher);
extern pascal void SetDAFont () inline(0x1C15,dispatcher);
extern pascal void SetDefButton () inline(0x3815,dispatcher);
extern pascal void SetDItemBox () inline(0x2915,dispatcher);
extern pascal void SetDItemType () inline(0x2715,dispatcher);
extern pascal void SetDItemValue () inline(0x2F15,dispatcher);
extern pascal void SetIText () inline(0x2015,dispatcher);
extern pascal void ShowDItem () inline(0x2315,dispatcher);
extern pascal Word StopAlert () inline(0x1815,dispatcher);
extern pascal void UpdateDialog () inline(0x2515,dispatcher);
#endif
