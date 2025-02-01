/********************************************
; File: Memory.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __MEMORY__
#define __MEMORY__

#ifndef attrNoSpec /* -  */
#define attrNoSpec 0x0008
#endif
#define memErr 0x0201 /*error - unable to allocate block */
#define emptyErr 0x0202 /*error - illegal operation, empty handle */
#define notEmptyErr 0x0203 /*error - an empty handle was expected for this operation */
#define lockErr 0x0204 /*error - illegal operation on a locked block */
#define purgeErr 0x0205 /*error - attempt to purge an unpurgable block */
#define handleErr 0x0206 /*error - an invalid handle was given */
#define idErr 0x0207 /*error - an invalid owner ID was given */
#define attrErr 0x0208 /*error - operation illegal on block with given attributes */
#define attrNoPurge 0x0000 /*Handle Attribute Bits - Not purgeable */
#define attrBank 0x0001 /*Handle Attribute Bits - fixed bank */
#define attrAddr 0x0002 /*Handle Attribute Bits - fixed address */
#ifndef attrPage /*Handle Attribute Bits - page aligned */
#define attrPage 0x0004
#endif
#ifndef attrNoSpec /*Handle Attribute Bits - may not use special memory */
#define attrNoSpec 0x0008
#endif
#ifndef attrNoCross /*Handle Attribute Bits - may not cross banks */
#define attrNoCross 0x0010
#endif
#define attrPurge1 0x0100 /*Handle Attribute Bits - Purge level 1 */
#define attrPurge2 0x0200 /*Handle Attribute Bits - Purge level 2 */
#define attrPurge3 0x0300 /*Handle Attribute Bits - Purge level 3 */
#ifndef attrPurge /*Handle Attribute Bits - test or set both purge bits */
#define attrPurge 0x0300
#endif
#define attrHandle 0x1000 /*Handle Attribute Bits - block of master pointers */
#define attrSystem 0x2000 /*Handle Attribute Bits - system handle */
#define attrFixed 0x4000 /*Handle Attribute Bits - not movable */
#define attrLocked 0x8000 /*Handle Attribute Bits - locked */
extern pascal void MMBootInit () inline(0x0102,dispatcher);
extern pascal Word __MMStartUp () inline(0x0202,dispatcher);
#define MMStartUp() __MMStartUp(0)
extern pascal void MMShutDown () inline(0x0302,dispatcher);
extern pascal Word MMVersion () inline(0x0402,dispatcher);
extern pascal void MMReset () inline(0x0502,dispatcher);
extern pascal Boolean MMStatus () inline(0x0602,dispatcher);
extern pascal void BlockMove () inline(0x2B02,dispatcher);
extern pascal void CheckHandle () inline(0x1E02,dispatcher);
extern pascal void CompactMem () inline(0x1F02,dispatcher);
extern pascal void DisposeAll () inline(0x1102,dispatcher);
extern pascal void DisposeHandle () inline(0x1002,dispatcher);
extern pascal Handle __FindHandle () inline(0x1A02,dispatcher);
#define FindHandle(a) __FindHandle((a),0l)
extern pascal LongWord FreeMem () inline(0x1B02,dispatcher);
extern pascal LongWord GetHandleSize () inline(0x1802,dispatcher);
extern pascal void HandToHand () inline(0x2A02,dispatcher);
extern pascal void HandToPtr () inline(0x2902,dispatcher);
extern pascal void HLock () inline(0x2002,dispatcher);
extern pascal void HLockAll () inline(0x2102,dispatcher);
extern pascal void HUnlock () inline(0x2202,dispatcher);
extern pascal void HUnlockAll () inline(0x2302,dispatcher);
extern pascal LongWord MaxBlock () inline(0x1C02,dispatcher);
extern pascal Handle __NewHandle () inline(0x0902,dispatcher);
#define NewHandle(a,b,c,d) __NewHandle((d),(c),(b),(a),0l)
extern pascal void PtrToHand () inline(0x2802,dispatcher);
extern pascal void PurgeAll () inline(0x1302,dispatcher);
extern pascal void PurgeHandle () inline(0x1202,dispatcher);
extern pascal LongWord RealFreeMem () inline(0x2F02,dispatcher);
extern pascal void ReallocHandle () inline(0x0A02,dispatcher);
extern pascal void RestoreHandle () inline(0x0B02,dispatcher);
extern pascal void SetHandleSize () inline(0x1902,dispatcher);
extern pascal void SetPurge () inline(0x2402,dispatcher);
extern pascal void SetPurgeAll () inline(0x2502,dispatcher);
extern pascal LongWord TotalMem () inline(0x1D02,dispatcher);
extern pascal void AddToOOMQueue () inline(0x0C02,dispatcher);
extern pascal void DeleteFromOOMQueue () inline(0x0D02,dispatcher);
#endif
