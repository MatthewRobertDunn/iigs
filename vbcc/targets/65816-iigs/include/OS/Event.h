/********************************************
; File: Event.h
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
#define __EVENT__

#define emDupStrtUpErr 0x0601 /*error - duplicate EMStartup Call */
#define emResetErr 0x0602 /*error - can't reset error the Event Manager */
#define emNotActErr 0x0603 /*error - event manager not active */
#define emBadEvtCodeErr 0x0604 /*error - illegal event code */
#define emBadBttnNoErr 0x0605 /*error - illegal button number */
#define emQSiz2LrgErr 0x0606 /*error - queue size too large */
#define emNoMemQueueErr 0x0607 /*error - not enough memory for queue */
#define emBadEvtQErr 0x0681 /*error - fatal sys error - event queue damaged */
#define emBadQHndlErr 0x0682 /*error - fatal sys error - queue handle damaged */
#define nullEvt 0x0000 /*Event Code -  */
#define mouseDownEvt 0x0001 /*Event Code -  */
#define mouseUpEvt 0x0002 /*Event Code -  */
#define keyDownEvt 0x0003 /*Event Code -  */
#define autoKeyEvt 0x0005 /*Event Code -  */
#define updateEvt 0x0006 /*Event Code -  */
#define activateEvt 0x0008 /*Event Code -  */
#define switchEvt 0x0009 /*Event Code -  */
#define deskAccEvt 0x000A /*Event Code -  */
#define driverEvt 0x000B /*Event Code -  */
#define app1Evt 0x000C /*Event Code -  */
#define app2Evt 0x000D /*Event Code -  */
#define app3Evt 0x000E /*Event Code -  */
#define app4Evt 0x000F /*Event Code -  */
#define mDownMask 0x0002 /*Event Masks -  */
#define mUpMask 0x0004 /*Event Masks -  */
#define keyDownMask 0x0008 /*Event Masks -  */
#define autoKeyMask 0x0020 /*Event Masks -  */
#define updateMask 0x0040 /*Event Masks -  */
#define activeMask 0x0100 /*Event Masks -  */
#define switchMask 0x0200 /*Event Masks -  */
#define deskAccMask 0x0400 /*Event Masks -  */
#define driverMask 0x0800 /*Event Masks -  */
#define app1Mask 0x1000 /*Event Masks -  */
#define app2Mask 0x2000 /*Event Masks -  */
#define app3Mask 0x4000 /*Event Masks -  */
#define app4Mask 0x8000 /*Event Masks -  */
#define everyEvent 0xFFFF /*Event Masks -  */
#define jcTickCount 0x00 /*Journal Code - TickCount call */
#define jcGetMouse 0x01 /*Journal Code - GetMouse call */
#define jcButton 0x02 /*Journal Code - Button call */
#define jcEvent 0x04 /*Journal Code - GetNextEvent and EventAvail calls */
#define activeFlag 0x0001 /*Modifier Flags - set if window being activated */
#define changeFlag 0x0002 /*Modifier Flags - set if active wind. changed state */
#define btn1State 0x0040 /*Modifier Flags - set if button 1 up */
#define btn0State 0x0080 /*Modifier Flags - set if button 0 up */
#define appleKey 0x0100 /*Modifier Flags - set if Apple key down */
#define shiftKey 0x0200 /*Modifier Flags - set if shift key down */
#define capsLock 0x0400 /*Modifier Flags - set if caps lock key down */
#define optionKey 0x0800 /*Modifier Flags - set if option key down */
#define controlKey 0x1000 /*Modifier Flags - set if Control key down */
#define keyPad 0x2000 /*Modifier Flags - set if keypress from key pad */
struct EventRecord {
   Word what; /* event code */
   LongWord message; /* event message */
   LongWord when; /* ticks since startup */
   Point where; /* mouse location */
   Word modifiers; /* modifier flags */
   LongWord wmTaskData; /*  */
   LongWord wmTaskMask; /*  */
   LongWord wmLastClickTick; /*  */
   Word wmClickCount; /*  */
   LongWord wmTaskData2; /*  */
   LongWord wmTaskData3; /*   */
   LongWord wmTaskData4; /*   */
   Point wmLastClickPt; /*   */
} ;
typedef struct EventRecord EventRecord, *EventRecordPtr, **EventRecordHndl;
extern pascal void EMBootInit () inline(0x0106,dispatcher);
extern pascal void EMStartUp () inline(0x0206,dispatcher);
extern pascal void EMShutDown () inline(0x0306,dispatcher);
extern pascal Word EMVersion () inline(0x0406,dispatcher);
extern pascal void EMReset () inline(0x0506,dispatcher);
extern pascal Boolean EMStatus () inline(0x0606,dispatcher);
extern pascal Boolean Button () inline(0x0D06,dispatcher);
extern pascal Word DoWindows () inline(0x0906,dispatcher);
extern pascal Boolean EventAvail () inline(0x0B06,dispatcher);
extern pascal void FakeMouse () inline(0x1906,dispatcher);
extern pascal Word FlushEvents () inline(0x1506,dispatcher);
extern pascal LongWord GetCaretTime () inline(0x1206,dispatcher);
extern pascal LongWord GetDblTime () inline(0x1106,dispatcher);
extern pascal void GetMouse () inline(0x0C06,dispatcher);
extern pascal Boolean GetNextEvent () inline(0x0A06,dispatcher);
extern pascal Boolean GetOSEvent () inline(0x1606,dispatcher);
extern pascal Boolean OSEventAvail () inline(0x1706,dispatcher);
extern pascal Word PostEvent () inline(0x1406,dispatcher);
extern pascal void SetEventMask () inline(0x1806,dispatcher);
extern pascal void SetSwitch () inline(0x1306,dispatcher);
extern pascal Boolean StillDown () inline(0x0E06,dispatcher);
extern pascal Boolean WaitMouseUp () inline(0x0F06,dispatcher);
extern pascal LongWord TickCount () inline(0x1006,dispatcher);
extern pascal Word GetKeyTranslation () inline(0x1B06,dispatcher);
extern pascal void SetKeyTranslation () inline(0x1C06,dispatcher);
extern pascal void SetAutoKeyLimit () inline(0x1A06,dispatcher);
#endif
