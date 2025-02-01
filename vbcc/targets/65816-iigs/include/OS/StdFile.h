/********************************************
; File: StdFile.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __STDFILE__
#define __STDFILE__

#define noDisplay 0x0000 /*filterProc result - file not to be displayed */
#define noSelect 0x0001 /*filterProc result - file displayed, but not selectable */
#define displaySelect 0x0002 /*filterProc result - file displayed and selectable */
#define sfMatchFileType 0x8000 /* -  */
#define sfMatchAuxType 0x4000 /* -  */
#define sfDisplayGrey 0x2000 /* -  */

typedef struct SFReplyRec {
   Boolean good; /*  */
   Word fileType; /*  */
   Word auxFileType; /*  */
   char filename[16]; /*  */
   char fullPathname[129]; /*  */
   } SFReplyRec, *SFReplyRecPtr;
struct SFReplyRec2 {
   Boolean good; /*   */
   Word filetype; /*   */
   LongWord auxType; /*   */
   RefDescriptor nameDesc; /*   */
   Ref nameRef; /*   */
   RefDescriptor pathDesc; /*   */
   Ref pathRef; /*   */
} ;
typedef struct SFReplyRec2 SFReplyRec2, *SFReplyRec2Ptr, **SFReplyRec2Hndl;
struct multiReplyRecord {
   Word good; /*   */
   Handle namesHandle; /*   */
} ;
typedef struct multiReplyRecord multiReplyRecord;
struct SFTypeList {
   Byte numEntries; /*   */
   Byte fileTypeEntries[5]; /*   */
} ;
typedef struct SFTypeList SFTypeList, *SFTypeListPtr, **SFTypeListHandle;
struct TypeSelector2 {
   Word flags; /*   */
   Word fileType; /*   */
   LongWord auxType; /*   */
} ;
typedef struct TypeSelector2 TypeSelector2;
struct SFTypeList2 {
   Word numEntries; /*   */
   TypeSelector2 fileTypeEntries[5]; /*   */
} ;
typedef struct SFTypeList2 SFTypeList2, *SFTypeList2Ptr;
extern pascal void SFBootInit () inline(0x0117,dispatcher);
extern pascal void SFStartUp () inline(0x0217,dispatcher);
extern pascal void SFShutDown () inline(0x0317,dispatcher);
extern pascal Word SFVersion () inline(0x0417,dispatcher);
extern pascal void SFReset () inline(0x0517,dispatcher);
extern pascal Boolean SFStatus () inline(0x0617,dispatcher);
extern pascal void SFAllCaps () inline(0x0D17,dispatcher);
extern pascal void SFGetFile () inline(0x0917,dispatcher);
extern pascal void SFGetFile2 () inline(0x0E17,dispatcher);
extern pascal void SFMultiGet2 () inline(0x1417,dispatcher);
extern pascal void SFPGetFile () inline(0x0B17,dispatcher);
extern pascal void SFPGetFile2 () inline(0x1017,dispatcher);
extern pascal void SFPMultiGet2 () inline(0x1517,dispatcher);
extern pascal void SFPPutFile () inline(0x0C17,dispatcher);
extern pascal void SFPPutFile2 () inline(0x1117,dispatcher);
extern pascal void SFPutFile () inline(0x0A17,dispatcher);
extern pascal void SFPutFile2 () inline(0x0F17,dispatcher);
extern pascal Boolean SFShowInvisible () inline(0x1217,dispatcher);
extern pascal void SFReScan () inline(0x1317,dispatcher);
#endif
