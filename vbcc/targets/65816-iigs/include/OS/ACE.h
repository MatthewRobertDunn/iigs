/********************************************
; File: ACE.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __ACE__
#define __ACE__

#define aceNoError 0x0 /*Error -  */
#define aceIsActive 0x1D01 /*Error -  */
#define aceBadDP 0x1D02 /*Error -  */
#define aceNotActive 0x1D03 /*Error -   */
#define aceNoSuchParam 0x1D04 /*Error -  */
#define aceBadMethod 0x1D05 /*Error -  */
#define aceBadSrc 0x1D06 /*Error -  */
#define aceBadDest 0x1D07 /*Error -  */
#define aceDataOverlap 0x1D08 /* Error -  */
#define aceNotImplemented 0x1DFF /*Error -  */
extern pascal void ACEBootInit() inline(0x011D,dispatcher);
extern pascal void ACEStartUp () inline(0x021D,dispatcher);
extern pascal void ACEShutDown () inline(0x031D,dispatcher);
extern pascal Word ACEVersion () inline(0x041D,dispatcher);
extern pascal void ACEReset () inline(0x051D,dispatcher);
extern pascal Boolean ACEStatus () inline(0x061D,dispatcher);
extern pascal LongWord ACEInfo () inline(0x071D,dispatcher);
extern pascal void ACECompBegin () inline(0x0B1D,dispatcher);
extern pascal void ACECompress () inline(0x091D,dispatcher);
extern pascal void ACEExpand () inline(0x0A1D,dispatcher);
extern pascal void ACEExpBegin () inline(0x0C1D,dispatcher);
#endif
