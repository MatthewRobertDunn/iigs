/********************************************
; File: Desk.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __EVENT__
#include <Event.h>
#endif

#ifndef __DESK__
#define __DESK__

#define daNotFound 0x0510 /*error - desk accessory not found */
#define notSysWindow 0x0511 /*error - not the system window */
#define eventAction 0x0001 /*NDA action code -  */
#define runAction 0x0002 /*NDA action code -  */
#define undoAction 0x0005 /*NDA action code -  */
#define cutAction 0x0006 /*NDA action code -  */
#define copyAction 0x0007 /*NDA action code -  */
#define pasteAction 0x0008 /*NDA action code -  */
#define clearAction 0x0009 /*NDA action code -  */
#define cursorAction 0x0003 /*NDAaction code -  */
#define undo 0x0001 /*System Edit - edit type */
#define cut 0x0002 /*System Edit - edit type */
#define copy 0x0003 /*System Edit - edit type */
#define paste 0x0004 /*System Edit - edit type */
#define clear 0x0005 /*System Edit - edit type */
extern pascal void DeskBootInit () inline(0x0105,dispatcher);
extern pascal void DeskStartUp () inline(0x0205,dispatcher);
extern pascal void DeskShutDown () inline(0x0305,dispatcher);
extern pascal Word DeskVersion () inline(0x0405,dispatcher);
extern pascal void DeskReset () inline(0x0505,dispatcher);
extern pascal Boolean DeskStatus () inline(0x0605,dispatcher);
extern pascal void ChooseCDA () inline(0x1105,dispatcher);
extern pascal void CloseAllNDAs () inline(0x1D05,dispatcher);
extern pascal void CloseNDA () inline(0x1605,dispatcher);
extern pascal void CloseNDAByWinPtr () inline(0x1C05,dispatcher);
extern pascal void FixAppleMenu () inline(0x1E05,dispatcher);
extern pascal Pointer GetDAStrPtr () inline(0x1405,dispatcher);
extern pascal Word GetNumNDAs () inline(0x1B05,dispatcher);
extern pascal void InstallCDA () inline(0x0F05,dispatcher);
extern pascal void InstallNDA () inline(0x0E05,dispatcher);
extern pascal Word OpenNDA () inline(0x1505,dispatcher);
extern pascal void RestAll () inline(0x0C05,dispatcher);
extern pascal void RestScrn () inline(0x0A05,dispatcher);
extern pascal void SaveAll () inline(0x0B05,dispatcher);
extern pascal void SaveScrn () inline(0x0905,dispatcher);
extern pascal void SetDAStrPtr () inline(0x1305,dispatcher);
extern pascal void SystemClick () inline(0x1705,dispatcher);
extern pascal Boolean SystemEdit () inline(0x1805,dispatcher);
extern pascal Boolean SystemEvent () inline(0x1A05,dispatcher);
extern pascal void SystemTask () inline(0x1905,dispatcher);
extern pascal void AddToRunQ () inline(0x1F05,dispatcher);
extern pascal void RemoveFromRunQ () inline(0x2005,dispatcher);
extern pascal void RemoveCDA () inline(0x2105,dispatcher);
extern pascal void RemoveNDA () inline(0x2205,dispatcher);
#endif
