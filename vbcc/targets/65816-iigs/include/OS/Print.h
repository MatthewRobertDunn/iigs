/********************************************
; File: Print.h
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

#ifndef __DIALOG__
#include <Dialog.h>
#endif

#ifndef __PRINT__
#define __PRINT__

#define pntrConFailed 0x1308 /*error - connection to the printer failed */
#define memFullErr 0xFF80 /*errors -  */
#define ioAbort 0xFFE5 /*errors -  */
#define prAbort 0x0080 /*errors -  */
#define missingDriver 0x1301 /*errors - specified driver not in system/drivers */
#define portNotOn 0x1302 /*errors - specified port not selected in ctl panel */
#define noPrintRecord 0x1303 /*errors - no print record was given */
#define badLaserPrep 0x1304 /*errors - laser prep in laser writer incompatible */
#define badLPFile 0x1305 /*errors - laser prep in system/drivers incompatible */
#define papConnNotOpen 0x1306 /*errors - cannot connect to laser writer */
#define papReadWriteErr 0x1307 /*errors - apple talk PAPRead or PAPWrite error */
#define startUpAlreadyMade 0x1321 /*errors - low level startup already made */
#define invalidCtlVal 0x1322 /*errors - invalid control value had been spec'd */
#define reset 0x0001 /*LLDControl - Printer control value - reset printer */
#define formFeed 0x0002 /*LLDControl - Printer control value - form feed */
#define lineFeed 0x0003 /*LLDControl - Printer control value - line feed */
#define bothDrivers 0x0 /*whichDriver - input to PMLoadDriver and PMUnloadDriver */
#define printerDriver 0x0001 /*whichDriver - input to PMLoadDriver and PMUnloadDriver */
#define portDriver 0x0002 /*whichDriver - input to PMLoadDriver and PMUnloadDriver */
#define PrPortrait 0x0000 /* -  */
#define prLandscape 0x0001 /* -  */
#define prImageWriter 0x0001 /* -  */
#define prImageWriterLQ 0x0002 /* -  */
#define prLaserWriter 0x0003 /* -  */
#define prEpson 0x0004 /* -  */
#define prBlackWhite 0x0001 /* -  */
#define prColor 0x0002 /* -  */
#define bDraftLoop 0x0000 /* -  */
#define bSpoolLoop 0x0080 /* -  */
struct PrPrinterSpecRec {
   Word prPrinterType; /*   */
   Word prCharacteristics; /*   */
} ;
typedef struct PrPrinterSpecRec PrPrinterSpecRec;
struct PrInfoRec {
   Word iDev; /* reserved for internal use */
   Word iVRes; /* vertical resolution of printer */
   Word iHRes; /* horizontal resolution of printer */
   Rect rPage; /* defining page rectangle */
} ;
typedef struct PrInfoRec PrInfoRec, *PrInfoRecPtr, **PrInfoRecHndl;
struct PrJobRec {
   Word iFstPage; /* first page to print */
   Word iLstPage; /* last page to print */
   Word iCopies; /* number of copies */
   Byte bJDocLoop; /* printing method */
   Byte fFromUser; /* used internally */
   WordProcPtr pIdleProc; /* background procedure */
   Pointer pFileName; /* spool file name */
   Word iFileVol; /* spool file volume reference number */
   Byte bFileVers; /* spool file version number */
   Byte bJobX; /* used internally */
} ;
typedef struct PrJobRec PrJobRec, *PrJobRecPtr;
struct PrStyleRec {
   Word wDev; /* output quality information */
   Word internA[3]; /* for internal use */
   Word feed; /* paper feed type */
   Word paperType; /* paper type */
   Word crWidth; /* carriage Width for image writer or vertical sizing for lazer writer */
   Word reduction; /* % reduction, laser writer only */
   Word internB; /* for internal use */
} ;
typedef struct PrStyleRec PrStyleRec, *PrStyleRecPtr, **PrStyleRecHndl;
struct PrRec {
   Word prVersion; /* print manager version */
   PrInfoRec prInfo; /* printer infomation subrecord */
   Rect rPaper; /* Defining paper rectangle */
   PrStyleRec prStl; /* style subrecord */
   Byte prInfoPT[14]; /* reserved for internal use */
   Byte prXInfo[24]; /* reserved for internal use */
   PrJobRec prJob; /* job subrecord */
   Byte printX[38]; /* reserved for future use */
   Word iReserved; /* reserved for internal use */
} ;
typedef struct PrRec PrRec, *PrRecPtr, **PrRecHndl;
struct PrStatusRec {
   Word iTotPages; /* number of pages in spool file */
   Word iCurPage; /* page being printed */
   Word iTotCopies; /* number of copies requested */
   Word iCurCopy; /* copy being printed */
   Word iTotBands; /* reserved for internal use */
   Word iCurBand; /* reserved for internal use */
   Word fPgDirty; /* TRUE if started printing page */
   Word fImaging; /* reserved for internal use */
   PrRecHndl hPrint; /* handle of print record */
   GrafPortPtr pPrPort; /* pointer to grafport being use for printing */
   LongWord hPic; /* reserved for internal use */
} ;
typedef struct PrStatusRec PrStatusRec, *PrStatusRecPtr, **PrStatusRecHndl;
extern pascal void PMBootInit () inline(0x0113,dispatcher);
extern pascal void PMStartUp () inline(0x0213,dispatcher);
extern pascal void PMShutDown () inline(0x0313,dispatcher);
extern pascal Word PMVersion () inline(0x0413,dispatcher);
extern pascal void PMReset () inline(0x0513,dispatcher);
extern pascal Boolean PMStatus () inline(0x0613,dispatcher);
extern pascal void LLDBitMap () inline(0x1C13,dispatcher);
extern pascal void LLDControl () inline(0x1B13,dispatcher);
extern pascal void LLDShutDown () inline(0x1A13,dispatcher);
extern pascal void LLDStartUp () inline(0x1913,dispatcher);
extern pascal void LLDText () inline(0x1D13,dispatcher);
extern pascal void PMLoadDriver () inline(0x3513,dispatcher);
extern pascal void PMUnloadDriver () inline(0x3413,dispatcher);
extern pascal Boolean PrChoosePrinter () inline(0x1613,dispatcher);
extern pascal Boolean PrChooser () inline(0x1613,dispatcher);
extern pascal void PrCloseDoc () inline(0x0F13,dispatcher);
extern pascal void PrClosePage () inline(0x1113,dispatcher);
extern pascal void PrDefault () inline(0x0913,dispatcher);
extern pascal Word PrDriverVer () inline(0x2313,dispatcher);
extern pascal Word PrError () inline(0x1413,dispatcher);
extern pascal Boolean PrJobDialog () inline(0x0C13,dispatcher);
extern pascal GrafPortPtr PrOpenDoc () inline(0x0E13,dispatcher);
extern pascal void PrOpenPage () inline(0x1013,dispatcher);
extern pascal void PrPicFile () inline(0x1213,dispatcher);
extern pascal void PrPixelMap () inline(0x0D13,dispatcher);
extern pascal Word PrPortVer () inline(0x2413,dispatcher);
extern pascal void PrSetError () inline(0x1513,dispatcher);
extern pascal Boolean PrStlDialog () inline(0x0B13,dispatcher);
extern pascal Boolean PrValidate () inline(0x0A13,dispatcher);
extern pascal void PrSetDocName () inline(0x3713,dispatcher);
extern pascal StringPtr PrGetDocName () inline(0x3613,dispatcher);
extern pascal Word PrGetPgOrientation () inline(0x3813,dispatcher);
extern pascal long PrGetPrinterSpecs () inline(0x1813,dispatcher);
extern pascal void PrGetZoneName () inline(0x2513,dispatcher);
extern pascal void PrGetPrinterDvrName () inline(0x2813,dispatcher);
extern pascal void PrGetPortDvrName () inline(0x2913,dispatcher);
extern pascal void PrGetUserName () inline(0x2A13,dispatcher);
extern pascal void PrGetNetworkName () inline(0x2B13,dispatcher);
#endif
