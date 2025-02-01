/********************************************
; File: Locator.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __LOCATOR__
#define __LOCATOR__

#define toolNotFoundErr 0x0001 /*error -  */
#define funcNotFoundErr 0x0002 /*error -  */
#define toolVersionErr 0x0110 /*error -  */
#define sysStrtMtErr 0x0100 /*error - can't mount system startup volume */
#define messNotFoundErr 0x0111 /*error -  */
#define fileInfoType 0x0001 /*MessageCenter - Message type parameter */
#define addMessage 0x0001 /*MessageCenter - action parameter */
#define getMessage 0x0002 /*MessageCenter - action parameter */
#define deleteMessage 0x0003 /*MessageCenter - action parameter */
#define mvReturn 0x0001 /*TLMountVolume - like ok for dialogs */
#define mvEscape 0x0002 /*TLMountVolume - like cancel for dialogs */
#define sysTool 0x0000 /*Tool Set Spec -  */
#define userTool 0x8000 /*Tool Set Spec -  */
struct MessageRec {
   struct MessageRec **messageNext; /*   */
   Word messageType; /*   */
   Word messageData; /*   */
   Str255 fileNames[1]; /*   */
} ;
typedef struct MessageRec MessageRec, *MessageRecPtr, **MessageRecHndl;
struct ToolSpec {
   Word toolNumber; /*   */
   Word minVersion; /*   */
} ;
typedef struct ToolSpec ToolSpec;
struct StartStopRecord {
   Word flags; /*   */
   Word videoMode; /*   */
   Word resFileID; /*   */
   Handle dPageHandle; /*   */
   Word numTools; /*   */
} ;
typedef struct StartStopRecord StartStopRecord, *StartStopRecordPtr;
extern pascal void TLBootInit () inline(0x0101,dispatcher);
extern pascal void TLStartUp () inline(0x0201,dispatcher);
extern pascal void TLShutDown () inline(0x0301,dispatcher);
extern pascal Word TLVersion () inline(0x0401,dispatcher);
extern pascal void TLReset () inline(0x0501,dispatcher);
extern pascal Boolean TLStatus () inline(0x0601,dispatcher);
extern pascal Pointer GetFuncPtr () inline(0x0B01,dispatcher);
extern pascal Pointer GetTSPtr () inline(0x0901,dispatcher);
extern pascal Pointer GetWAP () inline(0x0C01,dispatcher);
extern pascal void LoadOneTool () inline(0x0F01,dispatcher);
extern pascal void LoadTools () inline(0x0E01,dispatcher);
extern pascal void MessageCenter () inline(0x1501,dispatcher);
extern pascal void RestoreTextState () inline(0x1401,dispatcher);
extern pascal Handle SaveTextState () inline(0x1301,dispatcher);
extern pascal void SetDefaultTPT () inline(0x1601,dispatcher);
extern pascal void SetTSPtr () inline(0x0A01,dispatcher);
extern pascal void SetWAP () inline(0x0D01,dispatcher);
extern pascal Word TLMountVolume () inline(0x1101,dispatcher);
extern pascal Word TLTextMountVolume () inline(0x1201,dispatcher);
extern pascal void UnloadOneTool () inline(0x1001,dispatcher);
extern pascal Ref StartUpTools () inline(0x1801,dispatcher);
extern pascal void ShutDownTools () inline(0x1901,dispatcher);
extern pascal LongWord MessageByName () inline(0x1701,dispatcher);
#endif
