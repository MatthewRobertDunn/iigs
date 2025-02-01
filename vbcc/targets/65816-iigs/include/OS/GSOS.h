/********************************************
; File: GSOS.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __GSOS__
#define __GSOS__

#define readEnable 0x0001 /*access - read enable bit: CreateRec, OpenRec access and requestAccess fields */
#define writeEnable 0x0002 /*access - write enable bit: CreateRec, OpenRec access and requestAccess fields */
#define fileInvisible 0x0004 /*access - Invisible bit */
#define backupNeeded 0x0020 /*access - backup needed bit: CreateRec, OpenRec access  field. (Must be 0 in requestAccess field ) */
#define renameEnable 0x0040 /*access - rename enable bit: CreateRec, OpenRec access and requestAccess fields */
#define destroyEnable 0x0080 /*access - destroy enable  bit: CreateRec, OpenRec access and requestAccess fields */
#define startPlus 0x0000 /*base - > setMark = displacement */
#define eofMinus 0x0001 /*base - > setMark = eof - displacement */
#define markPlus 0x0002 /*base - > setMark = mark + displacement */
#define markMinus 0x0003 /*base - > setMark = mark - displacement */
#define cacheOff 0x0000 /*cachePriority - do not cache blocks invloved in this read */
#define cacheOn 0x0001 /*cachePriority -  cache blocks invloved in this read if possible */
#define badSystemCall 0x0001 /*error - bad system call number */
#define invalidPcount 0x0004 /*error - invalid parameter count */
#define gsosActive 0x07 /*error - GS/OS already active */
#ifndef devNotFound /*error - device not found */
#define devNotFound 0x10
#endif
#define invalidDevNum 0x11 /*error - invalid device number */
#define drvrBadReq 0x20 /*error - bad request or command */
#define drvrBadCode 0x0021 /*error - bad control or status code */
#define drvrBadParm 0x0022 /*error - bad call parameter */
#define drvrNotOpen 0x0023 /*error - character device not open */
#define drvrPriorOpen 0x0024 /*error - character device already open */
#define irqTableFull 0x0025 /*error - interrupt table full */
#define drvrNoResrc 0x0026 /*error - resources not available */
#define drvrIOError 0x0027 /*error - I/O error */
#define drvrNoDevice 0x0028 /*error - device not connected */
#define drvrBusy 0x0029 /*error - call aborted, driver is busy */
#define drvrWrtProt 0x002B /*error - device is write protected */
#define drvrBadCount 0x002C /*error - invalid byte count */
#define drvrBadBlock 0x002D /*error - invalid block address */
#define drvrDiskSwitch 0x002E /*error - disk has been switched */
#define drvrOffLine 0x002F /*error - device off line/ no media present */
#define badPathSyntax 0x0040 /*error - invalid pathname syntax */
#define invalidRefNum 0x0043 /*error - invalid reference number */
#ifndef pathNotFound /*error - subdirectory does not exist */
#define pathNotFound 0x44
#endif
#define volNotFound 0x0045 /*error - volume not found */
#ifndef fileNotFound /*error - file not found */
#define fileNotFound 0x0046
#endif
#define dupPathname 0x0047 /*error - create or rename with existing name */
#define volumeFull 0x0048 /*error - volume full error */
#define volDirFull 0x0049 /*error - volume directory full */
#define badFileFormat 0x004A /*error - version error (incompatible file format) */
#ifndef badStoreType /*error - unsupported (or incorrect) storage type */
#define badStoreType 0x004B
#endif
#ifndef eofEncountered /*error - end-of-file encountered */
#define eofEncountered 0x004C
#endif
#define outOfRange 0x004D /*error - position out of range */
#define invalidAccess 0x004E /*error - access not allowed */
#define buffTooSmall 0x004F /*error - buffer too small */
#define fileBusy 0x0050 /*error - file is already open */
#define dirError 0x0051 /*error - directory error */
#define unknownVol 0x0052 /*error - unknown volume type */
#ifndef paramRangeErr /*error - parameter out of range */
#define paramRangeErr 0x0053
#endif
#define outOfMem 0x0054 /*error - out of memory */
#define dupVolume 0x0057 /*error - duplicate volume name */
#define notBlockDev 0x0058 /*error - not a block device */
#ifndef invalidLevel /*error - specifield level outside legal range */
#define invalidLevel 0x0059
#endif
#define damagedBitMap 0x005A /*error - block number too large */
#define badPathNames 0x005B /*error - invalid pathnames for ChangePath */
#define notSystemFile 0x005C /*error - not an executable file */
#define osUnsupported 0x005D /*error - Operating System not supported */
#ifndef stackOverflow /*error - too many applications on stack */
#define stackOverflow 0x005F
#endif
#define dataUnavail 0x0060 /*error - Data unavailable */
#define endOfDir 0x0061 /*error - end of directory has been reached */
#define invalidClass 0x0062 /*error - invalid FST call class */
#define resForkNotFound 0x0063 /*error - file does not contain required resource */
#define invalidFSTID 0x0064 /*error - error - FST ID is invalid */
#define proDOSFSID 0x0001 /* fileSysID - ProDOS/SOS  */
#define dos33FSID 0x0002 /*fileSysID - DOS 3.3 */
#define dos32FSID 0x0003 /*fileSysID - DOS 3.2 */
#define dos31FSID 0x0003 /*fileSysID - DOS 3.1 */
#define appleIIPascalFSID 0x0004 /*fileSysID - Apple II Pascal */
#define mfsFSID 0x0005 /*fileSysID - Macintosh (flat file system) */
#define hfsFSID 0x0006 /*fileSysID - Macintosh (hierarchical file system) */
#define lisaFSID 0x0007 /*fileSysID - Lisa file system */
#define appleCPMFSID 0x0008 /*fileSysID - Apple CP/M */
#define charFSTFSID 0x0009 /*fileSysID - Character FST */
#define msDOSFSID 0x000A /*fileSysID - MS/DOS */
#define highSierraFSID 0x000B /*fileSysID - High Sierra */
#define iso9660FSID 0x000C /* fileSysID - ISO 9660 */
#define appleShareFSID 0x000D /* fileSysID - ISO 9660 */
#define characterFST 0x4000 /*FSTInfo.attributes - character FST */
#define ucFST 0x8000 /*FSTInfo.attributes - SCM should upper case pathnames before passing them to the FST */
#define onStack 0x8000 /*QuitRec.flags - place state information about quitting program on the quit return stack */
#define restartable 0x4000 /*QuitRec.flags - the quitting program is capable of being restarted from its dormant memory */
#define seedling 0x0001 /*storageType - standard file with seedling structure */
#define standardFile 0x0001 /*storageType - standard file type (no resource fork) */
#define sapling 0x0002 /*storageType - standard file with sapling structure */
#define tree 0x0003 /*storageType - standard file with tree structure */
#define pascalRegion 0x0004 /*storageType - UCSD Pascal region on a partitioned disk */
#define extendedFile 0x0005 /*storageType - extended file type (with resource fork) */
#define directoryFile 0x000D /*storageType - volume directory or subdirectory file */
#define minorRelNumMask 0x00FF /*version - minor release number */
#define majorRelNumMask 0x7F00 /*version - major release number */
#define finalRelNumMask 0x8000 /*version - final release number */
#define isFileExtended 0x8000 /*GetDirEntryGS -  */
struct GSString255 {
   Word length; /* Number of Chars in text field  */
   char text[255]; /*  */
} ;
typedef struct GSString255 GSString255, *GSString255Ptr, **GSString255Hndl;
typedef GSString255Hndl *GSString255HndlPtr;
struct GSString32 {
   Word length; /* Number of characters in text field */
   char text[32]; /*  */
} ;
typedef struct GSString32 GSString32, *GSString32Ptr, **GSString32Hndl;
struct ResultBuf255 {
   Word bufSize; /*  */
   GSString255 bufString; /*  */
} ;
typedef struct ResultBuf255 ResultBuf255, *ResultBuf255Ptr, **ResultBuf255Hndl;
typedef ResultBuf255Hndl *ResultBuf255HndlPtr ;



struct ResultBuf32 {
   Word bufSize; /*  */
   GSString32 bufString; /*  */
} ;
typedef struct ResultBuf32 ResultBuf32, *ResultBuf32Ptr, **ResultBuf32Hndl;
struct ChangePathRecGS {
   Word pCount; /*  */
   GSString255Ptr pathname; /*  */
   GSString255Ptr newPathname; /*  */
} ;
typedef struct ChangePathRecGS ChangePathRecGS, *ChangePathRecPtrGS;
struct CreateRecGS {
   Word pCount; /*  */
   GSString255Ptr pathname; /*  */
   Word access; /*  */
   Word fileType; /*  */
   LongWord auxType; /*  */
   Word storageType; /*  */
   LongWord eof; /*  */
   LongWord resourceEOF; /*  */
} ;
typedef struct CreateRecGS CreateRecGS, *CreateRecPtrGS;
struct DAccessRecGS {
   Word pCount; /*  */
   Word devNum; /*  */
   Word code; /*  */
   Pointer list; /*  */
   LongWord requestCount; /*  */
   LongWord transferCount; /*  */
} ;
typedef struct DAccessRecGS DAccessRecGS, *DAccessRecPtrGS;
struct DevNumRecGS {
   Word pCount; /*  */
   GSString255Ptr devName; /*  */
   Word devNum; /*  */
} ;
typedef struct DevNumRecGS DevNumRecGS, *DevNumRecPtrGS;
struct DInfoRecGS {
   Word pCount; /* minimum = 2 */
   Word devNum; /*  */
   GSString32Ptr devName; /*  */
   Word characteristics; /*  */
   LongWord totalBlocks; /*  */
   Word slotNum; /*  */
   Word unitNum; /*  */
   Word version; /*  */
   Word deviceID; /*  */
   Word headLink; /*  */
   Word forwardLink; /*  */
   LongWord extendedDIBptr; /*  */
} ;
typedef struct DInfoRecGS DInfoRecGS, *DInfoRecPtrGS;
struct DIORecGS {
   Word pCount; /*  */
   Word devNum; /*  */
   Pointer buffer; /*  */
   LongWord requestCount; /*  */
   LongWord startingBlock; /*  */
   Word blockSize; /*  */
   LongWord transferCount; /*  */
} ;
typedef struct DIORecGS DIORecGS, *DIORecPtrGS;
struct DirEntryRecGS {
   Word pCount; /*  */
   Word refNum; /*  */
   Word flags; /*  */
   Word base; /*  */
   Word displacement; /*  */
   Pointer name; /*  */
   Word entryNum; /*  */
   Word fileType; /*  */
   Longint eof; /*  */
   LongWord blockCount; /*  */
   TimeRec createDateTime; /*  */
   TimeRec modDateTime; /*  */
   Word access; /*  */
   LongWord auxType; /*  */
   Word fileSysID; /*  */
   ResultBuf255Ptr optionList; /*  */
   LongWord resourceEOF; /*  */
   LongWord resourceBlocks; /*  */
} ;
typedef struct DirEntryRecGS DirEntryRecGS, *DirEntryRecPtrGS;
struct ExpandPathRecGS {
   Word pCount; /*  */
   GSString255Ptr inputPath; /*  */
   ResultBuf255Ptr outputPath; /*  */
   Word flags; /*  */
} ;
typedef struct ExpandPathRecGS ExpandPathRecGS, *ExpandPathRecPtrGS;
struct FileInfoRecGS {
   Word pCount; /*  */
   GSString255Ptr pathname; /*  */
   Word access; /*  */
   Word fileType; /*  */
   LongWord auxType; /*  */
   Word storageType; /* must be 0 for SetFileInfo */
   TimeRec createDateTime; /*  */
   TimeRec modDateTime; /*  */
   LongWord optionList; /*  */
   LongWord eof; /*  */
   LongWord blocksUsed; /* must be 0 for SetFileInfo */
   LongWord resourceEOF; /* must be 0 for SetFileInfo */
   LongWord resourceBlocks; /* must be 0 for SetFileInfo */
} ;
typedef struct FileInfoRecGS FileInfoRecGS, *FileInfoRecPtrGS;
struct FormatRecGS {
   Word pCount; /*  */
   GSString32Ptr devName; /* device name pointer */
   GSString32Ptr volName; /* volume name pointer */
   Word fileSysID; /* file system ID */
   Word reqFileSysID; /* in;  */
} ;
typedef struct FormatRecGS FormatRecGS, *FormatRecPtrGS;
struct FSTInfoRecGS {
   Word pCount; /*  */
   Word fstNum; /*  */
   Word fileSysID; /*  */
   ResultBuf255Ptr fstName; /*  */
   Word version; /*  */
   Word attributes; /*  */
   Word blockSize; /*  */
   LongWord maxVolSize; /*  */
   LongWord maxFileSize; /*  */
} ;
typedef struct FSTInfoRecGS FSTInfoRecGS, *FSTInfoRecPtrGS;
struct InterruptRecGS {
   Word pCount; /*  */
   Word intNum; /*  */
   Word vrn; /* used only by BindInt */
   LongWord intCode; /* used only by BindInt */
} ;
typedef struct InterruptRecGS InterruptRecGS, *InterruptRecPtrGS;
struct IORecGS {
   Word pCount; /*  */
   Word refNum; /*  */
   Pointer dataBuffer; /*  */
   LongWord requestCount; /*  */
   LongWord transferCount; /*  */
   Word cachePriority; /*  */
} ;
typedef struct IORecGS IORecGS, *IORecPtrGS;
struct LevelRecGS {
   Word pCount; /*  */
   Word level; /*  */
} ;
typedef struct LevelRecGS LevelRecGS, *LevelRecPtrGS;
struct NameRecGS {
   Word pCount; /*  */
   GSString255Ptr pathname; /* full pathname or a filename depending on call */
} ;
typedef struct NameRecGS NameRecGS, *NameRecPtrGS;
struct GetNameRecGS {
   Word pCount; /*  */
   ResultBuf255Ptr dataBuffer; /* full pathname or a filename depending on call */
} ;
typedef struct GetNameRecGS GetNameRecGS, *GetNameRecPtrGS;
struct NewlineRecGS {
   Word pCount; /*  */
   Word refNum; /*  */
   Word enableMask; /*  */
   Word numChars; /*  */
   Pointer newlineTable; /*  */
} ;
typedef struct NewlineRecGS NewlineRecGS, *NewlineRecPtrGS;
struct OpenRecGS {
   Word pCount; /*  */
   Word refNum; /*  */
   GSString255Ptr pathname; /*  */
   Word requestAccess; /*  */
   Word resourceNumber; /* For extended files: dataFork/resourceFork */
   Word access; /* Value of file's access attribute */
   Word fileType; /* Value of file's fileType attribute */
   LongWord auxType; /*  */
   Word storageType; /*  */
   TimeRec createDateTime; /*  */
   TimeRec modDateTime; /*  */
   Word *optionList; /*  */
   LongWord eof; /*  */
   LongWord blocksUsed; /*  */
   LongWord resourceEOF; /*  */
   LongWord resourceBlocks; /*  */
} ;
typedef struct OpenRecGS OpenRecGS, *OpenRecPtrGS;
struct OSShutdownRecGS {
   Word pCount; /* in */
   Word shutdownFlag; /* in */
} ;
typedef struct OSShutdownRecGS OSShutdownRecGS, *OSShutdownRecPtrGS;
struct PositionRecGS {
   Word pCount; /*  */
   Word refNum; /*  */
   LongWord position; /*  */
} ;
typedef struct PositionRecGS PositionRecGS, *PositionRecPtrGS;
struct EOFRecGS {
   Word pCount; /*  */
   Word refNum; /*  */
   LongWord eof; /*  */
} ;
typedef struct EOFRecGS EOFRecGS, *EOFRecPtrGS;

typedef struct PrefixRecGS {
   Word pCount; /*  */
   Word prefixNum; /*  */
   union {
     ResultBuf255Ptr getPrefix; /*  */
     GSString255Ptr setPrefix; /*  */
   } buffer;
   } PrefixRecGS, *PrefixRecPtrGS;
struct QuitRecGS {
   Word pCount; /*  */
   GSString255Ptr pathname; /* pathname of next app to run */
   Word flags; /*  */
} ;
typedef struct QuitRecGS QuitRecGS, *QuitRecPtrGS;
struct RefNumRecGS {
   Word pCount; /*  */
   Word refNum; /*  */
} ;
typedef struct RefNumRecGS RefNumRecGS, *RefnumRecPtrGS;
struct SessionStatusRecGS {
   Word pCount; /* in: min = 1 */
   Word status; /* out: */
} ;
typedef struct SessionStatusRecGS SessionStatusRecGS, *SessionStatusRecPtrGS;
struct SetPositionRecGS {
   Word pCount; /*  */
   Word refNum; /*  */
   Word base; /*  */
   LongWord displacement; /*  */
} ;
typedef struct SetPositionRecGS SetPositionRecGS, *SetPositionRecPtrGS;
struct SysPrefsRecGS {
   Word pCount; /*  */
   Word preferences; /*  */
} ;
typedef struct SysPrefsRecGS SysPrefsRecGS, *SysPrefsRecPtrGS;
struct VersionRecGS {
   Word pCount; /*  */
   Word version; /*  */
} ;
typedef struct VersionRecGS VersionRecGS, *VersionRecPtrGS;
struct VolumeRecGS {
   Word pCount; /*  */
   GSString32Ptr devName; /*  */
   ResultBuf255Ptr volName; /*  */
   LongWord totalBlocks; /*  */
   LongWord freeBlocks; /*  */
   Word fileSysID; /*  */
   Word blockSize; /*  */
} ;
typedef struct VolumeRecGS VolumeRecGS, *VolumeRecPtrGS;
#ifndef stackEntry
#define stackEntry 0xE100B0
#endif
#ifndef sysCall
extern pascal void sysCall() inline(0x0000,stackEntry); 
#endif

#define BeginSessionGS(pBlockPtr)  sysCall(pBlockPtr,0x201D)
#define BindIntGS(pBlockPtr)  sysCall(pBlockPtr,0x2031)
#define ChangePathGS(pBlockPtr)  sysCall(pBlockPtr,0x2004)
#define ClearBackupBitGS(pBlockPtr)  sysCall(pBlockPtr,0x200B)
#define CloseGS(pBlockPtr)  sysCall(pBlockPtr,0x2014)
#define CreateGS(pBlockPtr)  sysCall(pBlockPtr,0x2001)
#define DControlGS(pBlockPtr)  sysCall(pBlockPtr,0x202E)
#define DestroyGS(pBlockPtr)  sysCall(pBlockPtr,0x2002)
#define DInfoGS(pBlockPtr)  sysCall(pBlockPtr,0x202C)
#define DReadGS(pBlockPtr)  sysCall(pBlockPtr,0x202F)
#define DStatusGS(pBlockPtr)  sysCall(pBlockPtr,0x202D)
#define DWriteGS(pBlockPtr)  sysCall(pBlockPtr,0x2030)
#define EndSessionGS(pBlockPtr)  sysCall(pBlockPtr,0x201E)
#define EraseDiskGS(pBlockPtr)  sysCall(pBlockPtr,0x2025)
#define ExpandPathGS(pBlockPtr)  sysCall(pBlockPtr,0x200E)
#define FlushGS(pBlockPtr)  sysCall(pBlockPtr,0x2015)
#define FormatGS(pBlockPtr)  sysCall(pBlockPtr,0x2024)
#define GetBootVolGS(pBlockPtr)  sysCall(pBlockPtr,0x2028)
#define GetDevNumberGS(pBlockPtr)  sysCall(pBlockPtr,0x2020)
#define GetDirEntryGS(pBlockPtr)  sysCall(pBlockPtr,0x201C)
#define GetEOFGS(pBlockPtr)  sysCall(pBlockPtr,0x2019)
#define GetFileInfoGS(pBlockPtr)  sysCall(pBlockPtr,0x2006)
#define GetFSTInfoGS(pBlockPtr)  sysCall(pBlockPtr,0x202B)
#define GetLevelGS(pBlockPtr)  sysCall(pBlockPtr,0x201B)
#define GetMarkGS(pBlockPtr)  sysCall(pBlockPtr,0x2017)
#define GetNameGS(pBlockPtr)  sysCall(pBlockPtr,0x2027)
#define GetPrefixGS(pBlockPtr)  sysCall(pBlockPtr,0x200A)
#define GetVersionGS(pBlockPtr)  sysCall(pBlockPtr,0x202A)
#define GetSysPrefsGS(pBlockPtr)  sysCall(pBlockPtr,0x200F)
#define NewlineGS(pBlockPtr)  sysCall(pBlockPtr,0x2011)
#define NullGS(pBlockPtr)  sysCall(pBlockPtr,0x200D)
#define OpenGS(pBlockPtr)  sysCall(pBlockPtr,0x2010)
#define QuitGS(pBlockPtr)  sysCall(pBlockPtr,0x2029)
#define ReadGS(pBlockPtr)  sysCall(pBlockPtr,0x2012)
#define ResetCacheGS(pBlockPtr)  sysCall(pBlockPtr,0x2026)
#define SessionStatusGS(pBlockPtr)  sysCall(pBlockPtr,0x201F)
#define SetEOFGS(pBlockPtr)  sysCall(pBlockPtr,0x2018)
#define SetFileInfoGS(pBlockPtr)  sysCall(pBlockPtr,0x2005)
#define SetLevelGS(pBlockPtr)  sysCall(pBlockPtr,0x201A)
#define SetMarkGS(pBlockPtr)  sysCall(pBlockPtr,0x2016)
#define SetPrefixGS(pBlockPtr)  sysCall(pBlockPtr,0x2009)
#define SetSysPrefsGS(pBlockPtr)  sysCall(pBlockPtr,0x200C)
#define UnbindIntGS(pBlockPtr)  sysCall(pBlockPtr,0x2032)
#define VolumeGS(pBlockPtr)  sysCall(pBlockPtr,0x2008)
#define WriteGS(pBlockPtr)  sysCall(pBlockPtr,0x2013)
#define OSShutdownGS(pBlockPtr)  sysCall(pBlockPtr,0x2003)
#ifndef __PRODOS__ 
 
#define GetSysPrefs(arg)  GetSysPrefsGS(arg)
#define BeginSession(arg)  BeginSessionGS(arg)
#define EndSession(arg)  EndSessionGS(arg)
#define SessionStatus(arg)  SessionStatusGS(arg)
#define ResetCache(arg)  ResetCacheGS(arg)
#define ChangePath(arg)  ChangePathGS(arg)
#define ClearBackupBit(arg)  ClearBackupBitGS(arg)
#define Close(arg)  CloseGS(arg)
#define Create(arg)  CreateGS(arg)
#define DControl(arg)  DControlGS(arg)
#define Destroy(arg)  DestroyGS(arg)
#define DInfo(arg)  DInfoGS(arg)
#define DRead(arg)  DReadGS(arg)
#define DStatus(arg)  DStatusGS(arg)
#define DWrite(arg)  DWriteGS(arg)
#define EraseDisk(arg)  EraseDiskGS(arg)
#define ExpandPath(arg)  ExpandPathGS(arg)
#define Flush(arg)  FlushGS(arg)
#define Format(arg)  FormatGS(arg)
#define GetBootVol(arg)  GetBootVolGS(arg)
#define GetDevNumber(arg)  GetDevNumberGS(arg)
#define GetDirEntry(arg)  GetDirEntryGS(arg)
#define GetEOF(arg)  GetEOFGS(arg)
#define GetFileInfo(arg)  GetFileInfoGS(arg) 
#define GetFSTInfo(arg)  GetFSTInfoGS(arg)
#define GetLevel(arg)  GetLevelGS(arg)
#define GetMark(arg)  GetMarkGS(arg)
#define GetName(arg)  GetNameGS(arg)
#define GetPrefix(arg)  GetPrefixGS(arg)
#define GetVersion(arg)  GetVersionGS(arg)
#define Newline(arg)  NewlineGS(arg)
#define Null(arg)  NullGS(arg)
#define Open(arg)  OpenGS(arg)
#define Quit(arg)  QuitGS(arg)
#define Read(arg)  ReadGS(arg)
#define SetEOF(arg)  SetEOFGS(arg)
#define SetFileInfo(arg)  SetFileInfoGS(arg)
#define SetLevel(arg)  SetLevelGS(arg)
#define SetMark(arg)  SetMarkGS(arg)
#define SetPrefix(arg)  SetPrefixGS(arg)
#define UnbindInt(arg)  UnbindIntGS(arg)
#define Volume(arg)  VolumeGS(arg)
#define Write(arg)  WriteGS(arg)
#define BindInt(arg)  BindIntGS(arg)
 
#define ChangePathRec ChangePathRecGS 
#define CreateRec CreateRecGS 
#define DAccessRec DAccessRecGS 
#define DevNumRec DevNumRecGS 
#define DInfoRec DInfoRecGS 
#define DIORec DIORecGS 
#define DirEntryRec DirEntryRecGS 
#define EOFRec EOFRecGS
#define ExpandPathRec ExpandPathRecGS 
#define FileInfoRec FileInfoRecGS 
#define FormatRec FormatRecGS 
#define FSTInfoRec FSTInfoRecGS 
#define InterruptRec InterruptRecGS 
#define IORec IORecGS 
#define LevelRec LevelRecGS 
#define NameRec NameRecGS
#define GetNameRec GetNameRecGS 
#define NewlineRec NewlineRecGS 
#define OpenRec OpenRecGS 
#define PositionRec PositionRecGS 
#define PrefixRec PrefixRecGS 
#define QuitRec QuitRecGS 
#define RefNumRec RefNumRecGS 
#define SetPositionRec SetPositionRecGS 
#define SysPrefRec SysPrefRecGS 
#define VersionRec VersionRecGS 
#define VolumeRec VolumeRecGS 
 
#endif 


#define FSTSpecific(pBlockPtr)  sysCall(pBlockPtr,0x2033)
#endif
