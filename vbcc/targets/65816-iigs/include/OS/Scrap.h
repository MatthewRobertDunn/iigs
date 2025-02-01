/********************************************
; File: Scrap.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __SCRAP__
#define __SCRAP__

#define badScrapType 0x1610 /*error - No scrap of this type. */
#define textScrap 0x0000 /*scrapType -  */
#define picScrap 0x0001 /*scrapType -  */
extern pascal void ScrapBootInit () inline(0x0116,dispatcher);
extern pascal void ScrapStartUp () inline(0x0216,dispatcher);
extern pascal void ScrapShutDown () inline(0x0316,dispatcher);
extern pascal Word ScrapVersion () inline(0x0416,dispatcher);
extern pascal void ScrapReset () inline(0x0516,dispatcher);
extern pascal Boolean ScrapStatus () inline(0x0616,dispatcher);
extern pascal void GetScrap () inline(0x0D16,dispatcher);
extern pascal Word GetScrapCount () inline(0x1216,dispatcher);
extern pascal handle GetScrapHandle () inline(0x0E16,dispatcher);
extern pascal  GetScrapPath () inline(0x1016,dispatcher);
extern pascal LongWord GetScrapSize () inline(0x0F16,dispatcher);
extern pascal Word GetScrapState () inline(0x1316,dispatcher);
extern pascal void LoadScrap () inline(0x0A16,dispatcher);
extern pascal void PutScrap () inline(0x0C16,dispatcher);
extern pascal void SetScrapPath () inline(0x1116,dispatcher);
extern pascal void UnloadScrap () inline(0x0916,dispatcher);
extern pascal void ZeroScrap () inline(0x0B16,dispatcher);
#endif
