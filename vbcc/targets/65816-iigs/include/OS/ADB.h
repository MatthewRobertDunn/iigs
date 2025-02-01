/********************************************
; File: ADB.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __ADB__
#define __ADB__

#define cmndIncomplete 0x0910 /*error - Command not completed. */
#define cantSync 0x0911 /*error - Can't synchronize */
#define adbBusy 0x0982 /*error - Busy  (command pending) */
#define devNotAtAddr 0x0983 /*error - Device not present at address */
#define srqListFull 0x0984 /*error - List full */
#define readModes 0x000A /*ReadKeyMicroData -  */
#define readConfig 0x000B /*ReadKeyMicroData -  */
#define readADBError 0x000C /*ReadKeyMicroData -  */
#define readVersionNum 0x000D /*ReadKeyMicroData -  */
#define readAvailCharSet 0x000E /*ReadKeyMicroData -  */
#define readAvailLayout 0x000F /*ReadKeyMicroData -  */
#define readMicroMem 0x0009 /*ReadKeyMicroMem -  */
#define abort 0x0001 /*SendInfo - command */
#define resetKbd 0x0002 /*SendInfo - command */
#define flushKbd 0x0003 /*SendInfo - command */
#define setModes 0x0004 /*SendInfo - 2nd param is pointer to mode byte */
#define clearModes 0x0005 /*SendInfo - 2nd param is pointer to mode Byte */
#define setConfig 0x0006 /*SendInfo - 2nd param is pointer to SetConfigRec */
#define synch 0x0007 /*SendInfo - 2nd param is pointer to SynchRec */
#define writeMicroMem 0x0008 /*SendInfo - 2nd param is pointer to MicroControlMemRec */
#define resetSys 0x0010 /*SendInfo - command */
#define keyCode 0x0011 /*SendInfo - 2nd param is pointer to key code byte. */
#define resetADB 0x0040 /*SendInfo - command */
#define transmitADBBytes 0x0047 /*SendInfo - add number of bytes to this  */
#define enableSRQ 0x0050 /*SendInfo - command - ADB address in low nibble */
#define flushADBDevBuf 0x0060 /*SendInfo - command - ADB address in low nibble */
#define disableSRQ 0x0070 /*SendInfo - command - ADB address in low nibble */
#define transmit2ADBBytes 0x0080 /*SendInfo - add ADB address to this */
#define listen 0x0080 /*SendInfo - adbCommand = listen + ( 16 * reg) + (adb address) */
#define talk 0x00C0 /*SendInfo - adbCommand = talk + ( 16 * reg) + (adb address) */
struct ReadConfigRec {
   Byte rcRepeatDelay; /* Output Byte: Repeat / Delay */
   Byte rcLayoutOrLang; /* Output Byte: Layout / Language */
   Byte rcADBAddr; /* Output Byte: ADB address - keyboard and mouse */
} ;
typedef struct ReadConfigRec ReadConfigRec, *ReadConfigRecPtr;
struct SetConfigRec {
   Byte scADBAddr; /* keyboard and mouse */
   Byte scLayoutOrLang; /*  */
   Byte scRepeatDelay; /*  */
} ;
typedef struct SetConfigRec SetConfigRec, *SetConfigRecPtr;
struct SynchRec {
   Byte synchMode; /*  */
   Byte synchKybdMouseAddr; /*  */
   Byte synchLayoutOrLang; /*  */
   Byte synchRepeatDelay; /*  */
} ;
typedef struct SynchRec SynchRec, *SynchRecPtr;
struct ScaleRec {
   Word xDivide; /*  */
   Word yDivide; /*  */
   Word xOffset; /*  */
   Word yOffset; /*  */
   Word xMultiply; /*  */
   Word yMultiply; /*  */
} ;
typedef struct ScaleRec ScaleRec, *ScaleRecPtr;
extern pascal void ADBBootInit() inline(0x0109,dispatcher);
extern pascal void ADBStartUp() inline(0x0209,dispatcher);
extern pascal void ADBShutDown() inline(0x0309,dispatcher);
extern pascal Word ADBVersion() inline(0x0409,dispatcher);
extern pascal void ADBReset() inline(0x0509,dispatcher);
extern pascal Boolean ADBStatus() inline(0x0609,dispatcher);
extern pascal void AbsOff() inline(0x1009,dispatcher);
extern pascal void AbsOn() inline(0x0F09,dispatcher);
extern pascal void AsyncADBReceive() inline(0x0D09,dispatcher);
extern pascal void ClearSRQTable() inline(0x1609,dispatcher);
extern pascal void GetAbsScale() inline(0x1309,dispatcher);
extern pascal Word ReadAbs() inline(0x1109,dispatcher);
extern pascal void ReadKeyMicroData() inline(0x0A09,dispatcher);
extern pascal void ReadKeyMicroMem() inline(0x0B09,dispatcher);
extern pascal void SendInfo() inline(0x0909,dispatcher);
extern pascal void SetAbsScale() inline(0x1209,dispatcher);
extern pascal void SRQPoll() inline(0x1409,dispatcher);
extern pascal void SRQRemove() inline(0x1509,dispatcher);
extern pascal void SyncADBReceive() inline(0x0E09,dispatcher);
#endif
