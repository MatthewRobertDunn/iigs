/********************************************
; File: Menu.h
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

#ifndef __MENU__
#define __MENU__

#define mDrawMsg 0x0000 /*MenuDefProcCodes -  */
#define mChooseMsg 0x0001 /*MenuDefProcCodes -  */
#define mSizeMsg 0x0002 /*MenuDefProcCodes -  */
#define mDrawTitle 0x0003 /*MenuDefProcCodes -  */
#define mDrawMItem 0x0004 /*MenuDefProcCodes -  */
#define mGetMItemID 0x0005 /*MenuDefProcCodes -  */
#define mInvis 0x0004 /*MenuFlag -  */
#define mCustom 0x0010 /*MenuFlag -  */
#define mXor 0x0020 /*MenuFlag -  */
#define mSelected 0x0040 /*MenuFlag -  */
#define mDisabled 0x0080 /*MenuFlag -  */
#define customMenu 0x0010 /*MenuFlagMasks -  */
#define xorMItemHilite 0x0020 /*MenuFlagMasks -  */
#define xorTitleHilite 0x0020 /*MenuFlagMasks -  */
#define underMItem 0x0040 /*MenuFlagMasks -  */
#define disableItem 0x0080 /*MenuFlagMasks -  */
#define disableMenu 0x0080 /*MenuFlagMasks -  */
#define enableItem 0xFF7F /*MenuFlagMasks -  */
#define enableMenu 0xFF7F /*MenuFlagMasks -  */
#define noUnderMItem 0xFFBF /*MenuFlagMasks -  */
#define colorMItemHilite 0xFFDF /*MenuFlagMasks -  */
#define colorTitleHilite 0xFFDF /*MenuFlagMasks -  */
#define colorReplace 0xFFDF /*MenuFlagMasks -  */
#define standardMenu 0xFFEF /*MenuFlagMasks -  */
typedef CtlRec MenuBarRec, *MenuBarRecPtr, **MenuBarRecHndl;
struct MenuRec {
   Word menuID; /* Menu's ID number */
   Word menuWidth; /* Width of menu */
   Word menuHeight; /* Height of menu */
   WordProcPtr menuProc; /* Menu's definition procedure */
   Byte menuFlag; /* Bit flags */
   Byte menuRes; /*  */
   Byte firstItem; /*  */
   Byte numOfItems; /*  */
   Word titleWidth; /* Width of menu's title */
   Pointer titleName; /* Menu's title */
} ;
typedef struct MenuRec MenuRec, *MenuRecPtr, **MenuRecHndl;
extern pascal void MenuBootInit () inline(0x010F,dispatcher);
extern pascal void MenuStartUp () inline(0x020F,dispatcher);
extern pascal void MenuShutDown () inline(0x030F,dispatcher);
extern pascal Word MenuVersion () inline(0x040F,dispatcher);
extern pascal void MenuReset () inline(0x050F,dispatcher);
extern pascal Boolean MenuStatus () inline(0x060F,dispatcher);
extern pascal void CalcMenuSize () inline(0x1C0F,dispatcher);
extern pascal void CheckMItem () inline(0x320F,dispatcher);
extern pascal Word CountMItems () inline(0x140F,dispatcher);
extern pascal void DeleteMenu () inline(0x0E0F,dispatcher);
extern pascal void DeleteMItem () inline(0x100F,dispatcher);
extern pascal void DisableMItem () inline(0x310F,dispatcher);
extern pascal void DisposeMenu () inline(0x2E0F,dispatcher);
extern pascal void DrawMenuBar () inline(0x2A0F,dispatcher);
extern pascal void EnableMItem () inline(0x300F,dispatcher);
extern pascal Word FixMenuBar () inline(0x130F,dispatcher);
extern pascal void FlashMenuBar () inline(0x0C0F,dispatcher);
extern pascal LongWord GetBarColors () inline(0x180F,dispatcher);
extern pascal MenuBarRecHndl GetMenuBar () inline(0x0A0F,dispatcher);
extern pascal Word GetMenuFlag () inline(0x200F,dispatcher);
extern pascal GrafPortPtr GetMenuMgrPort () inline(0x1B0F,dispatcher);
extern pascal Pointer GetMenuTitle () inline(0x220F,dispatcher);
extern pascal MenuRecHndl GetMHandle () inline(0x160F,dispatcher);
extern pascal StringPtr GetMItem () inline(0x250F,dispatcher);
extern pascal Word GetMItemFlag () inline(0x270F,dispatcher);
extern pascal Word GetMItemMark () inline(0x340F,dispatcher);
extern pascal TextStyle GetMItemStyle () inline(0x360F,dispatcher);
extern pascal Word GetMTitleStart () inline(0x1A0F,dispatcher);
extern pascal Word GetMTitleWidth () inline(0x1E0F,dispatcher);
extern pascal MenuBarRecHndl GetSysBar () inline(0x110F,dispatcher);
extern pascal void HiliteMenu () inline(0x2C0F,dispatcher);
extern pascal void InitPalette () inline(0x2F0F,dispatcher);
extern pascal void InsertMenu () inline(0x0D0F,dispatcher);
extern pascal void InsertMItem () inline(0x0F0F,dispatcher);
extern pascal Word MenuGlobal () inline(0x230F,dispatcher);
extern pascal void MenuKey () inline(0x090F,dispatcher);
extern pascal void MenuNewRes () inline(0x290F,dispatcher);
extern pascal void MenuRefresh () inline(0x0B0F,dispatcher);
extern pascal void MenuSelect () inline(0x2B0F,dispatcher);
extern pascal MenuRecHndl NewMenu () inline(0x2D0F,dispatcher);
extern pascal MenuBarRecHndl NewMenuBar () inline(0x150F,dispatcher);
extern pascal void SetBarColors () inline(0x170F,dispatcher);
extern pascal void SetMenuBar () inline(0x390F,dispatcher);
extern pascal void SetMenuFlag () inline(0x1F0F,dispatcher);
extern pascal void SetMenuID () inline(0x370F,dispatcher);
extern pascal void SetMenuTitle () inline(0x210F,dispatcher);
extern pascal void SetMItem () inline(0x240F,dispatcher);
extern pascal void SetMItemBlink () inline(0x280F,dispatcher);
extern pascal void SetMItemFlag () inline(0x260F,dispatcher);
extern pascal void SetMItemID () inline(0x380F,dispatcher);
extern pascal void SetMItemMark () inline(0x330F,dispatcher);
extern pascal void SetMItemName () inline(0x3A0F,dispatcher);
extern pascal void SetMItemStyle () inline(0x350F,dispatcher);
extern pascal void SetMTitleStart () inline(0x190F,dispatcher);
extern pascal void SetMTitleWidth () inline(0x1D0F,dispatcher);
extern pascal void SetSysBar () inline(0x120F,dispatcher);
extern pascal Word PopUpMenuSelect () inline(0x3C0F,dispatcher);
extern pascal Pointer GetPopUpDefProc () inline(0x3B0F,dispatcher);
extern pascal void DrawPopUp () inline(0x3D0F,dispatcher);
extern pascal MenuBarRecHndl NewMenuBar2 () inline(0x430F,dispatcher);
extern pascal MenuRecHndl NewMenu2 () inline(0x3E0F,dispatcher);
extern pascal void InsertMItem2 () inline(0x3F0F,dispatcher);
extern pascal void SetMenuTitle2 () inline(0x400F,dispatcher);
extern pascal void SetMItem2 () inline(0x410F,dispatcher);
extern pascal void SetMItemName2 () inline(0x420F,dispatcher);
extern pascal void HideMenuBar () inline(0x450F,dispatcher);
extern pascal void ShowMenuBar () inline(0x460F,dispatcher);
#endif
