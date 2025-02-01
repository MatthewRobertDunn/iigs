/********************************************
; File: AppleShareFST.h
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
#include <GSOS.h>
#endif

#ifndef __APPLESHAREFST__
#define __APPLESHAREFST__

#define ASBufferControl 0x0001 /* Command Number -  */
#define ASByteRangeLock 0x0002 /* Command Number -  */
#define ASSpecialOpenFork 0x0003 /* Command Number -  */
#define ASGetPrivileges 0x0004 /* Command Number -  */
#define ASSetPrivileges 0x0005 /* Command Number -  */
#define ASUserInfo 0x0006 /* Command Number -  */
#define ASCopyFile 0x0007 /* Command Number -  */
#define ASGetUserPath 0x0008 /* Command Number -  */
#define ASOpenDesktop 0x0009 /* Command Number -  */
#define ASCloseDesktop 0x000A /* Command Number -  */
#define ASGetComment 0x000B /* Command Number -  */
#define ASSetComment 0x000C /* Command Number -  */
#define ASGetServerName 0x000D /* Command Number -  */
#define appleShareNetError 0x0088 /* Error - AppleShare Network Error */
#define unknownUser 0x007E /* Error - specified user name not registered */
#define unknownGroup 0x007F /* Error - specified group name not the name of a group */
#define lockRange 0x8000 /* Mask -  */
#define relativeToEOF 0x4000 /* Mask -  */
#define seeFolders 0x00 /* Mask -  */
#define seeFiles 0x02 /* Mask -  */
#define makeChanges 0x0004 /* Mask -  */
#define folderOwner 0x80 /* Mask -  */
#define onDesktop 0x0001 /* File Info Mask -  */
#define bFOwnAppl 0x0002 /* File Info Mask - used internally */
#define bFNever 0x0010 /* File Info Mask - never SwitchLaunch */
#define bFAlways 0x0020 /* File Info Mask - always SwitchLaunch */
#define shareApplication 0x0040 /* File Info Mask - set if file is a shareable application */
#define fileIsInited 0x0100 /* File Info Mask - seen by Finder */
#define fileHasChanged 0x0200 /* File Info Mask - used internally by Finder */
#define fileIsBusy 0x0400 /* File Info Mask - copied from File System busy bit */
#define fileNoCopy 0x0800 /* File Info Mask - not used in 5.0 and later, formally BOZO */
#define fileIsSystem 0x1000 /* File Info Mask - set if file is a system file */
#define fileHasBundle 0x2000 /* File Info Mask -  */
#define fileIsInvisible 0x4000 /* File Info Mask -  */
#define fileIsLocked 0x8000 /* File Info Mask -  */
#define inTrashWindow 0xFFFD /* Window Info Mask -  */
#define inDesktopWindow 0xFFFE /* Window Info Mask -  */
#define inDiskWindow 0x0000 /* Window Info Mask -  */
#define requestReadAccess 0x0000 /* accessWord Mask -  */
#define requestWriteAccess 0x0002 /* accessWord Mask -  */
#define denyReadAccess 0x0010 /* accessWord Mask -  */
#define denyWriteAccess 0x0020 /* accessWord Mask -  */
#define dataForkNum 0x0000 /* forkNum Mask -  */
#define resourceForkNum 0x0001 /* forkNum Mask -  */
struct CommandBlock {
   Word pCount; /*   */
   Word fstNum; /*   */
   Word commandNum; /*   */
} ;
typedef struct CommandBlock CommandBlock;
struct BufferControlRec {
   CommandBlock pBlock; /*   */
   Word refNum; /*   */
   Word flags; /*   */
} ;
typedef struct BufferControlRec BufferControlRec, *BufferControlRecPtr;
struct SpecialOpenForkRec {
   CommandBlock pBlock; /*   */
   GSString255Ptr pathname; /*   */
   Word accessMode; /*   */
   Word forkNum; /*   */
} ;
typedef struct SpecialOpenForkRec SpecialOpenForkRec, *SpecialOpenForkRecPtr;
struct ByteRangeLockRec {
   CommandBlock pBlock; /*   */
   Word referenceNum; /*   */
   Word lockFlag; /*   */
   LongWord fileOffset; /*   */
   LongWord rangeLength; /*   */
   LongWord rangeStart; /*   */
} ;
typedef struct ByteRangeLockRec ByteRangeLockRec, *ByteRangeLockRecPtr;
struct GetAccessRightsRec {
   Byte reserved; /*   */
   Byte world; /*   */
   Byte group; /*   */
   Byte owner; /*   */
} ;
typedef struct GetAccessRightsRec GetAccessRightsRec, *GetAccessRightsRecPtr;
struct GetPrivilegesRec {
   CommandBlock pBlock; /*   */
   GSString255Ptr pathname; /*   */
   GetAccessRightsRec accessRights; /*   */
   ResultBuf255Ptr ownerName; /*   */
   ResultBuf255Ptr groupName; /*   */
} ;
typedef struct GetPrivilegesRec GetPrivilegesRec, *GetPrivilegesRecPtr;
struct SetAccessRightsRec {
   Byte userSummary; /*   */
   Byte world; /*   */
   Byte group; /*   */
   Byte owner; /*   */
} ;
typedef struct SetAccessRightsRec SetAccessRightsRec, *SetAccessRightsRecPtr;
struct SetPrivilegesRec {
   CommandBlock pBlock; /*   */
   GSString255Ptr pathname; /*   */
   SetAccessRightsRec accessRights; /*   */
   ResultBuf255Ptr ownerName; /*   */
   ResultBuf255Ptr groupName; /*   */
} ;
typedef struct SetPrivilegesRec SetPrivilegesRec, *SetPrivilegesRecPtr;
struct UserInfoRec {
   CommandBlock pBlock; /*   */
   Word deviceNum; /*   */
   ResultBuf255Ptr userName; /*   */
   ResultBuf255Ptr primaryGroupName; /*   */
} ;
typedef struct UserInfoRec UserInfoRec, *UserInfoRecPtr;
struct CopyFileRec {
   CommandBlock pBlock; /*   */
   GSString255Ptr sourcePathname; /*   */
   GSString255Ptr destPathname; /*   */
} ;
typedef struct CopyFileRec CopyFileRec, *CopyFileRecPtr;
struct GetUserPathRec {
   CommandBlock pBlock; /*   */
   ResultBuf255Ptr prefix; /*   */
} ;
typedef struct GetUserPathRec GetUserPathRec, *GetUserPathRecPtr;
struct DesktopRec {
   CommandBlock pBlock; /*   */
   Word desktopRefNum; /*   */
   GSString255Ptr pathname; /*   */
} ;
typedef struct DesktopRec DesktopRec, *DesktopRecPtr;
struct GetCommentRec {
   CommandBlock pBlock; /*   */
   Word desktopRefNum; /*   */
   GSString255Ptr pathname; /*   */
   ResultBuf255Ptr comment; /*   */
} ;
typedef struct GetCommentRec GetCommentRec, *GetCommentRecPtr;
struct SetCommentRec {
   CommandBlock pBlock; /*   */
   Word desktopRefNum; /*   */
   GSString255Ptr pathname; /*   */
   GSString255Ptr comment; /*   */
} ;
typedef struct SetCommentRec SetCommentRec, *SetCommentRecPtr;
struct GetServerNameRec {
   CommandBlock pBlock; /*   */
   GSString255Ptr pathname; /*   */
   ResultBuf255Ptr serverName; /*   */
   ResultBuf255Ptr zoneName; /*   */
} ;
typedef struct GetServerNameRec GetServerNameRec, *GetServerNameRecPtr;
#endif
