/********************************************
; File: Resources.h
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
#include <Memory.h>
#endif

#ifndef __GSOS__
#include <GSOS.h>
#endif

#ifndef __RESOURCES__
#define __RESOURCES__

#define resLogOut 0x0 /*ResourceConverter -  */
#define resLogIn 0x1 /*ResourceConverter -  */
#define resLogApp 0x0 /*ResourceConverter -  */
#define resLogSys 0x2 /*ResourceConverter -  */
#define resForkUsed 0x1E01 /*Error - Resource fork not empty */
#define resBadFormat 0x1E02 /*Error - Format of resource fork is unknown */
#define resForkEmpty 0x1E03 /*Error - Resource fork is empty */
#define resNoCurFile 0x1E04 /*Error - there are no current open resource files */
#define resDupID 0x1E05 /*Error - ID is already used */
#define resNotFound 0x1E06 /*Error - resource was not found */
#define resFileNotFound 0x1E07 /*Error - resource file not found */
#define resBadAppID 0x1E08 /*Error - User ID not found, please call ResourceStartup */
#define resNoUniqueID 0x1E09 /*Error - a unique ID was not found */
#define resBadAttr 0x1E0A /*Error - reseved bits in attributes word are not zero */
#define resHashGone 0x1E0B /*Error - the hash count table is no longer valid */
#define resIndexRange 0x1E0D /*Error - index is out of range */
#define resNoCurApp 0x1E0E /*Error - no current application, please call ResourceStartup */
#define resChanged 0x0020 /*Resources -  */
#define resPreLoad 0x0040 /*Resources -  */
#define resProtected 0x0080 /*Resources -  */
#define resAbsLoad 0x0400 /*Resources -  */
#define resConverter 0x0800 /*Resources -  */
#define resMemAttr 0xC3F1 /*Resources -  */
#define systemMap 0x0001 /*Resources -  */
#define mapChanged 0x0002 /*Resources -  */
#define romMap 0x0004 /*Resources -  */
#define resNameOffset 0x10000 /*Resources - type holding names */
#define resNameVersion 0x0001 /*Resources -  */
#define rIcon 0x8001 /*Resources - resource type holding names */
#define rPicture 0x8002 /*Resources - resource type holding names */
#define rControlList 0x8003 /*Resources - resource type holding names */
#define rControlTemplate 0x8004 /*Resources - resource type holding names */
#define rWindow 0x8005 /*Resources - resource type holding names */
#define rString 0x8006 /*Resources - resource type holding names */
#define rStringList 0x8007 /*Resources - resource type holding names */
#define rMenuBar 0x8008 /*Resources - resource type holding names */
#define rMenu 0x8009 /*Resources - resource type holding names */
#define rMenuItem 0x800A /*Resources - resource type holding names */
#define rTextForLETextBox2 0x800B /*Resources - resource type holding names */
#define rCtlDefProc 0x800C /*Resources - resource type holding names */
#define rCtlColorTbl 0x800D /*Resources - resource type holding names */
#define rWindParam1 0x800E /*Resources - resource type holding names */
#define rWindParam2 0x800F /*Resources - resource type holding names */
#define rWindColor 0x8010 /*Resources - resource type holding names */
#define rResName 0x8014 /*Resources - resource type holding names */
typedef long ResID;
typedef word ResType;
typedef word ResAttr;
struct ResHeaderRec {
   LongWord rFileVersion; /* Format version of resource fork */
   LongWord rFileToMap; /* Offset from start to resource map record */
   LongWord rFileMapSize; /* Number of bytes map occupies in file */
   Byte rFileMemo[128]; /* Reserved space for application */
   LongWord rFileRecSize; /* Size of ResHeaderRec Record */
} ;
typedef struct ResHeaderRec ResHeaderRec;
struct FreeBlockRec {
   LongWord blkOffset; /*  */
   LongWord blkSize; /*  */
} ;
typedef struct FreeBlockRec FreeBlockRec;
struct ResMap {
   struct ResMap **mapNext; /* Handle to next resource map */
   Word mapFlag; /* Bit Flags */
   LongWord mapOffset; /* Map's file position */
   LongWord mapSize; /* Number of bytes map occupies in file */
   Word mapToIndex; /*  */
   Word mapFileNum; /*  */
   Word mapID; /*  */
   LongWord mapIndexSize; /*  */
   LongWord mapIndexUsed; /*  */
   Word mapFreeListSize; /*  */
   Word mapFreeListUsed; /*  */
   FreeBlockRec mapFreeList[1]; /* n bytes (array of free block records) */
} ;
typedef struct ResMap ResMap, *ResMapPtr, **ResMapHandle;
struct ResRefRec {
   ResType resType; /*  */
   ResID resID; /*  */
   LongWord resOffset; /*  */
   ResAttr resAttr; /*  */
   LongWord resSize; /*  */
   Handle resHandle; /*  */
} ;
typedef struct ResRefRec ResRefRec, *ResRefRecPtr;
struct ResourceSpec {
   ResType resourceType; /*   */
   ResID resourceID; /*   */
} ;
typedef struct ResourceSpec ResourceSpec;
struct ResNameEntry {
   ResID namedResID; /*   */
   Str255 resName; /*   */
} ;
typedef struct ResNameEntry ResNameEntry, *ResNameEntryPtr;
struct ResNameRecord {
   Word version; /*   */
   LongWord nameCount; /*   */
   ResNameEntry resNameEntries[1]; /*   */
} ;
typedef struct ResNameRecord ResNameRecord, *ResNameRecordPtr, **ResNameRecordHandle;
extern pascal void ResourceBootInit () inline(0x011E,dispatcher);
extern pascal void ResourceStartup () inline(0x021E,dispatcher);
extern pascal void ResourceShutdown () inline(0x031E,dispatcher);
extern pascal Word ResourceVersion () inline(0x041E,dispatcher);
extern pascal void ResourceReset () inline(0x051E,dispatcher);
extern pascal Boolean ResourceStatus () inline(0x061E,dispatcher);
extern pascal void AddResource () inline(0x0C1E,dispatcher);
extern pascal void CloseResourceFile () inline(0x0B1E,dispatcher);
extern pascal LongWord CountResources () inline(0x221E,dispatcher);
extern pascal Word CountTypes () inline(0x201E,dispatcher);
extern pascal void CreateResourceFile () inline(0x091E,dispatcher);
extern pascal void DetachResource () inline(0x181E,dispatcher);
extern pascal Word GetCurResourceApp () inline(0x141E,dispatcher);
extern pascal Word GetCurResourceFile () inline(0x121E,dispatcher);
extern pascal ResID GetIndResource () inline(0x231E,dispatcher);
extern pascal ResType GetIndType () inline(0x211E,dispatcher);
extern pascal ResMapHandle GetMapHandle () inline(0x261E,dispatcher);
extern pascal Word GetOpenFileRefNum () inline(0x1F1E,dispatcher);
extern pascal ResAttr GetResourceAttr () inline(0x1B1E,dispatcher);
extern pascal LongWord GetResourceSize () inline(0x1D1E,dispatcher);
extern pascal Word HomeResourceFile () inline(0x151E,dispatcher);
extern pascal Handle LoadAbsResource () inline(0x271E,dispatcher);
extern pascal Handle LoadResource () inline(0x0E1E,dispatcher);
extern pascal void MarkResourceChange () inline(0x101E,dispatcher);
extern pascal void MatchResourceHandle () inline(0x1E1E,dispatcher);
extern pascal Word OpenResourceFile () inline(0x0A1E,dispatcher);
extern pascal void ReleaseResource () inline(0x171E,dispatcher);
extern pascal void RemoveResource () inline(0x0F1E,dispatcher);
extern pascal void ResourceConverter () inline(0x281E,dispatcher);
extern pascal void SetCurResourceApp () inline(0x131E,dispatcher);
extern pascal void SetCurResourceFile () inline(0x111E,dispatcher);
extern pascal void SetResourceAttr () inline(0x1C1E,dispatcher);
extern pascal Word SetResourceFileDepth () inline(0x251E,dispatcher);
extern pascal void SetResourceID () inline(0x1A1E,dispatcher);
extern pascal Word SetResourceLoad () inline(0x241E,dispatcher);
extern pascal ResID UniqueResourceID () inline(0x191E,dispatcher);
extern pascal void UpdateResourceFile () inline(0x0D1E,dispatcher);
extern pascal void WriteResource () inline(0x161E,dispatcher);
#endif
