/********************************************
; File: QDAux.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __QDAUX__
#define __QDAUX__

struct QDIconRecord {
   Word iconType; /*   */
   Word iconSize; /*   */
   Word iconHeight; /*   */
   Word iconWidth; /*   */
   Byte iconImage[1]; /*   */
   Byte iconMask[1]; /*   */
} ;
typedef struct QDIconRecord QDIconRecord, *QDIconRecordPtr, **QDIconRecordHndl;
extern pascal void QDAuxBootInit () inline(0x0112,dispatcher);
extern pascal void QDAuxStartUp () inline(0x0212,dispatcher);
extern pascal void QDAuxShutDown () inline(0x0312,dispatcher);
extern pascal Word QDAuxVersion () inline(0x0412,dispatcher);
extern pascal void QDAuxReset () inline(0x0512,dispatcher);
extern pascal Boolean QDAuxStatus () inline(0x0612,dispatcher);
extern pascal void CopyPixels () inline(0x0912,dispatcher);
extern pascal void DrawIcon () inline(0x0B12,dispatcher);
extern pascal void SpecialRect () inline(0x0C12,dispatcher);
extern pascal void WaitCursor () inline(0x0A12,dispatcher);
extern pascal void SeedFill () inline(0x0D12,dispatcher);
extern pascal void CalcMask () inline(0x0E12,dispatcher);
extern pascal void PicComment () inline(0xB804,dispatcher);
extern pascal void ClosePicture () inline(0xB904,dispatcher);
extern pascal void DrawPicture () inline(0xBA04,dispatcher);
extern pascal void KillPicture () inline(0xBB04,dispatcher);
extern pascal handle OpenPicture () inline(0xB704,dispatcher);
#endif
