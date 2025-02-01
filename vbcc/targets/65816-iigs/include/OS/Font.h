/********************************************
; File: Font.h
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

#ifndef __FONT__
#define __FONT__

#define fmDupStartUpErr 0x1B01 /*error - duplicate FMStartUp call */
#define fmResetErr 0x1B02 /*error - can't reset the Font Manager */
#define fmNotActiveErr 0x1B03 /*error - Font Manager not active */
#define fmFamNotFndErr 0x1B04 /*error - family not found */
#define fmFontNtFndErr 0x1B05 /*error - font not found */
#define fmFontMemErr 0x1B06 /*error - font not in memory */
#define fmSysFontErr 0x1B07 /*error - system font cannot be purgeable */
#define fmBadFamNumErr 0x1B08 /*error - illegal family number */
#define fmBadSizeErr 0x1B09 /*error - illegal size */
#define fmBadNameErr 0x1B0A /*error - illegal name length */
#define fmMenuErr 0x1B0B /*error - fix font menu never called */
#define fmScaleSizeErr 0x1B0C /*error - scaled size of font exeeds limits */
#define newYork 0x0002 /*Family Number -  */
#define geneva 0x0003 /*Family Number -  */
#define monaco 0x0004 /*Family Number -  */
#define venice 0x0005 /*Family Number -  */
#define london 0x0006 /*Family Number -  */
#define athens 0x0007 /*Family Number -  */
#define sanFran 0x0008 /*Family Number -  */
#define toronto 0x0009 /*Family Number -  */
#define cairo 0x000B /*Family Number -  */
#define losAngeles 0x000C /*Family Number -  */
#define times 0x0014 /*Family Number -  */
#define helvetica 0x0015 /*Family Number -  */
#define courier 0x0016 /*Family Number -  */
#define symbol 0x0017 /*Family Number -  */
#define taliesin 0x0018 /*Family Number -  */
#define shaston 0xFFFE /*Family Number -  */
#define baseOnlyBit 0x0020 /*FamSpecBits -  */
#define notBaseBit 0x0020 /*FamStatBits -  */
#define memOnlyBit 0x0001 /*FontSpecBits -  */
#define realOnlyBit 0x0002 /*FontSpecBits -  */
#define anyFamBit 0x0004 /*FontSpecBits -  */
#define anyStyleBit 0x0008 /*FontSpecBits -  */
#define anySizeBit 0x0010 /*FontSpecBits -  */
#define memBit 0x0001 /*FontStatBits -  */
#define unrealBit 0x0002 /*FontStatBits -  */
#define apFamBit 0x0004 /*FontStatBits -  */
#define apVarBit 0x0008 /*FontStatBits -  */
#define purgeBit 0x0010 /*FontStatBits -  */
#define notDiskBit 0x0020 /*FontStatBits -  */
#define notFoundBit 0x8000 /*FontStatBits -  */
#define dontScaleBit 0x0001 /*Scale Word -  */
struct FontStatRec {
   FontID resultID; /*  */
   Word resultStats; /*  */
} ;
typedef struct FontStatRec FontStatRec, *FontStatRecPtr, **FontStatRecHndl;
extern pascal void FMBootInit () inline(0x011B,dispatcher);
extern pascal void FMStartUp () inline(0x021B,dispatcher);
extern pascal void FMShutDown () inline(0x031B,dispatcher);
extern pascal Word FMVersion () inline(0x041B,dispatcher);
extern pascal void FMReset () inline(0x051B,dispatcher);
extern pascal Boolean FMStatus () inline(0x061B,dispatcher);
extern pascal void AddFamily () inline(0x0D1B,dispatcher);
extern pascal void AddFontVar () inline(0x141B,dispatcher);
extern pascal LongWord ChooseFont () inline(0x161B,dispatcher);
extern pascal Word CountFamilies () inline(0x091B,dispatcher);
extern pascal Word CountFonts () inline(0x101B,dispatcher);
extern pascal Word FamNum2ItemID () inline(0x1B1B,dispatcher);
extern pascal Word FindFamily () inline(0x0A1B,dispatcher);
extern pascal void FindFontStats () inline(0x111B,dispatcher);
extern pascal void FixFontMenu () inline(0x151B,dispatcher);
extern pascal LongWord FMGetCurFID () inline(0x1A1B,dispatcher);
extern pascal LongWord FMGetSysFID () inline(0x191B,dispatcher);
extern pascal void FMSetSysFont () inline(0x181B,dispatcher);
extern pascal Word GetFamInfo () inline(0x0B1B,dispatcher);
extern pascal Word GetFamNum () inline(0x0C1B,dispatcher);
extern pascal void InstallFont () inline(0x0E1B,dispatcher);
extern pascal void InstallWithStats () inline(0x1C1B,dispatcher);
extern pascal Word ItemID2FamNum () inline(0x171B,dispatcher);
extern pascal void LoadFont () inline(0x121B,dispatcher);
extern pascal void LoadSysFont () inline(0x131B,dispatcher);
extern pascal void SetPurgeStat () inline(0x0F1B,dispatcher);
#endif
