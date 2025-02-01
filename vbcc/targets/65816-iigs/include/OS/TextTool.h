/********************************************
; File: TextTool.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __TEXTTOOL__
#define __TEXTTOOL__

#define badDevType 0x0C01 /*error - not implemented */
#define badDevNum 0x0C02 /*error - Illegal device number. */
#define badMode 0x0C03 /*error - Bad mode: illegal operation. */
#define unDefHW 0x0C04 /*error - Undefined hardware error */
#define lostDev 0x0C05 /*error - Lost device: Device no longer on line */
#define lostFile 0x0C06 /*error - File no longer in diskette directory */
#define badTitle 0x0C07 /*error - Illegal Filename */
#define noRoom 0x0C08 /*error - Insufficient space on specified diskette */
#define noDevice 0x0C09 /*error - Volume not online */
#define noFile 0x0C0A /*error - File not in specifiled directory */
#define dupFile 0x0C0B /*error - Filename already exists */
#define notClosed 0x0C0C /*error - Attempt to open an open file */
#define notOpen 0x0C0D /*error - Attempt to close closed file */
#define badFormat 0x0C0E /*error - error reading real or integer */
#define ringBuffOFlo 0x0C0F /*error - Chars arriving too fast */
#define writeProtected 0x0C10 /*error -  */
#define devErr 0x0C40 /*error - Read or Write failed */
#define input 0x0000 /*deviceNum -  */
#define output 0x0001 /*deviceNum -  */
#define errorOutput 0x0002 /*deviceNum -  */
#define basicType 0x0000 /*deviceType -  */
#define pascalType 0x0001 /*deviceType -  */
#define ramBased 0x0002 /*deviceType -  */
#define noEcho 0x0000 /*echoFlag -  */
#define echo 0x0001 /*echoFlag -  */
struct DeviceRec {
   LongWord ptrOrSlot; /* slot number or jump table ptr */
   Word deviceType; /* type of input device */
} ;
typedef struct DeviceRec DeviceRec, *DeviceRecPtr, **DeviceRecHndl;
struct TxtMaskRec {
   Word orMask; /*  */
   Word andMask; /*  */
} ;
typedef struct TxtMaskRec TxtMaskRec, *TxtMaskRecPtr, **TxtMaskRecHndl;
extern pascal void TextBootInit () inline(0x010C,dispatcher);
extern pascal void TextStartUp () inline(0x020C,dispatcher);
extern pascal void TextShutDown () inline(0x030C,dispatcher);
extern pascal Word TextVersion () inline(0x040C,dispatcher);
extern pascal void TextReset () inline(0x050C,dispatcher);
extern pascal Boolean TextStatus () inline(0x060C,dispatcher);
extern pascal void CtlTextDev () inline(0x160C,dispatcher);
extern pascal void ErrWriteBlock () inline(0x1F0C,dispatcher);
extern pascal void ErrWriteChar () inline(0x190C,dispatcher);
extern pascal void ErrWriteCString () inline(0x210C,dispatcher);
extern pascal void ErrWriteLine () inline(0x1B0C,dispatcher);
extern pascal void ErrWriteString () inline(0x1D0C,dispatcher);
extern pascal TxtMaskRec GetErrGlobals () inline(0x0E0C,dispatcher);
extern pascal DeviceRec GetErrorDevice () inline(0x140C,dispatcher);
extern pascal TxtMaskRec GetInGlobals () inline(0x0C0C,dispatcher);
extern pascal DeviceRec GetInputDevice () inline(0x120C,dispatcher);
extern pascal TxtMaskRec GetOutGlobals () inline(0x0D0C,dispatcher);
extern pascal DeviceRec GetOutputDevice () inline(0x130C,dispatcher);
extern pascal void InitTextDev () inline(0x150C,dispatcher);
extern pascal Word ReadChar () inline(0x220C,dispatcher);
extern pascal Word __ReadLine () inline(0x240C,dispatcher);
#define ReadLine(a,b,c,d) __ReadLine((d),(c),(b),(a),0)
extern pascal void SetErrGlobals () inline(0x0B0C,dispatcher);
extern pascal void SetErrorDevice () inline(0x110C,dispatcher);
extern pascal void SetInGlobals () inline(0x090C,dispatcher);
extern pascal void SetInputDevice () inline(0x0F0C,dispatcher);
extern pascal void SetOutGlobals () inline(0x0A0C,dispatcher);
extern pascal void SetOutputDevice () inline(0x100C,dispatcher);
extern pascal void StatusTextDev () inline(0x170C,dispatcher);
extern pascal void TextReadBlock () inline(0x230C,dispatcher);
extern pascal void TextWriteBlock () inline(0x1E0C,dispatcher);
extern pascal void WriteChar () inline(0x180C,dispatcher);
extern pascal void WriteCString () inline(0x200C,dispatcher);
extern pascal void WriteLine () inline(0x1A0C,dispatcher);
extern pascal void WriteString () inline(0x1C0C,dispatcher);
#endif
