/********************************************
; File: Quickdraw.h
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
#define __Quickdraw__

#define alreadyInitialized 0x0401 /*error - Quickdraw already initialized */
#define cannotReset 0x0402 /*error - never used */
#define notInitialized 0x0403 /*error - Quickdraw not initialized */
#define screenReserved 0x0410 /*error - screen reserved */
#define badRect 0x0411 /*error - bad rectangle */
#define notEqualChunkiness 0x0420 /*error - Chunkiness is not equal */
#define rgnAlreadyOpen 0x0430 /*error - region is already open */
#define rgnNotOpen 0x0431 /*error - region is not open */
#define rgnScanOverflow 0x0432 /*error - region scan overflow */
#define rgnFull 0x0433 /*error - region is full */
#define polyAlreadyOpen 0x0440 /*error - poly is already open */
#define polyNotOpen 0x0441 /*error - poly is not open */
#define polyTooBig 0x0442 /*error - poly is too big */
#define badTableNum 0x0450 /*error - bad table number */
#define badColorNum 0x0451 /*error - bad color number */
#define badScanLine 0x0452 /*error - bad scan line */
#define notImplemented 0x04FF /*error - not implemented */
#define tsNumber 0x04 /* -  */
#define _colorTable 0x0F /*AnSCBByte - Mask for SCB color table */
#define scbReserved 0x10 /*AnSCBByte - Mask for SCB reserved bit */
#define scbFill 0x20 /*AnSCBByte - Mask for SCB fill bit */
#define scbInterrupt 0x40 /*AnSCBByte - Mask for SCB interrupt bit */
#define scbColorMode 0x80 /*AnSCBByte - Mask for SCB color mode bit */
#define table320 0x32 /*ColorData -  (val=size) */
#define table640 0x32 /*ColorData -  (val=size) */
#define blueMask 0x000F /*ColorValue - Mask for Blue nibble */
#define greenMask 0x00F0 /*ColorValue - Mask for green nibble */
#define redMask 0x0F00 /*ColorValue - Mask for red nibble */
#define widMaxSize 0x0001 /*FontFlags -  */
#define zeroSize 0x0002 /*FontFlags -  */
#define maskSize 0x08 /*GrafPort - Mask Size (val=size) */
#define locSize 0x10 /*GrafPort - Loc Size (val=size) */
#define patsize 0x20 /*GrafPort - Pattern Size (val=size) */
#define pnStateSize 0x32 /*GrafPort - Pen State Size (Val=size) */
#define portSize 0xAA /*GrafPort - Size of GrafPort */
#define black 0x000 /*MasterColors - These work in 320 and 640 mode */
#define blue 0x00F /*MasterColors - These work in 320 and 640 mode */
#define darkGreen320 0x080 /*MasterColors - These work in 320 mode */
#define green320 0x0E0 /*MasterColors - These work in 320 mode */
#define green640 0x0F0 /*MasterColors - These work in 640 mode */
#define lightBlue320 0x4DF /*MasterColors - These work in 320 mode */
#define purple320 0x72C /*MasterColors - These work in 320 mode */
#define darkGray320 0x777 /*MasterColors - These work in 320 mode */
#define periwinkleBlue320 0x78F /*MasterColors - These work in 320 mode */
#define brown320 0x841 /*MasterColors - These work in 320 mode */
#define lightGray320 0x0CCC /*MasterColors - These work in 320 mode */
#define red320 0x0D00 /*MasterColors - These work in 320 mode */
#define lilac320 0x0DAF /*MasterColors - These work in 320 mode */
#define red640 0x0F00 /*MasterColors - These work in 640 mode */
#define orange320 0x0F70 /*MasterColors - These work in 320 mode */
#define flesh320 0x0FA9 /*MasterColors - These work in 320 mode */
#define yellow 0x0FF0 /*MasterColors - These work in 320 and 640 mode */
#define white 0x0FFF /*MasterColors - These work in 320 and 640 mode */
#define modeCopy 0x0000 /*PenModeDATA -  */
#define modeOR 0x0001 /*PenModeDATA -  */
#define modeXOR 0x0002 /*PenModeDATA -  */
#define modeBIC 0x0003 /*PenModeDATA -  */
#define modeForeCopy 0x0004 /*PenModeDATA -  */
#define modeForeOR 0x0005 /*PenModeDATA -  */
#define modeForeXOR 0x0006 /*PenModeDATA -  */
#define modeForeBIC 0x0007 /*PenModeDATA -  */
#define modeNOT 0x8000 /*PenModeDATA -  */
#define notCopy 0x8000 /*PenModeDATA -  */
#define notOR 0x8001 /*PenModeDATA -  */
#define notXOR 0x8002 /*PenModeDATA -  */
#define notBIC 0x8003 /*PenModeDATA -  */
#define notForeCOPY 0x8004 /*PenModeDATA -  */
#define notForeOR 0x8005 /*PenModeDATA -  */
#define notForeXOR 0x8006 /*PenModeDATA -  */
#define notForeBIC 0x8007 /*PenModeDATA -  */
#define frameVerb 0x00 /*PicInfo - PRIVATE - for reference only */
#define picNop 0x00 /*PicInfo - PRIVATE - for reference only */
#define drawCharVerb 0x00 /*PicInfo - PRIVATE - for reference only */
#define paintVerb 0x01 /*PicInfo - PRIVATE - for reference only */
#define picClipRgn 0x01 /*PicInfo - PRIVATE - for reference only */
#define drawTextVerb  0x01 /*PicInfo - PRIVATE - for reference only */
#define eraseVerb 0x02 /*PicInfo - PRIVATE - for reference only */
#define picBkPat 0x02 /*PicInfo - PRIVATE - for reference only */
#define drawCStrVerb 0x02 /*PicInfo - PRIVATE - for reference only */
#define invertVerb 0x03 /*PicInfo - PRIVATE - for reference only */
#define picTxFont 0x03 /*PicInfo - PRIVATE - for reference only */
#define fillVerb 0x04 /*PicInfo - PRIVATE - for reference only */
#define picTxFace 0x04 /*PicInfo - PRIVATE - for reference only */
#define picTxMode 0x05 /*PicInfo - PRIVATE - for reference only */
#define picSpExtra 0x06 /*PicInfo - PRIVATE - for reference only */
#define picPnSize 0x07 /*PicInfo - PRIVATE - for reference only */
#define picPnMode 0x08 /*PicInfo - PRIVATE - for reference only */
#define picPnPat 0x09 /*PicInfo - PRIVATE - for reference only */
#define picThePat 0x0A /*PicInfo - PRIVATE - for reference only */
#define picOvSize 0x0B /*PicInfo - PRIVATE - for reference only */
#define picOrigin 0x0C /*PicInfo - PRIVATE - for reference only */
#define picTxSize 0x0D /*PicInfo - PRIVATE - for reference only */
#define picFGColor 0x0E /*PicInfo - PRIVATE - for reference only */
#define picBGColor 0x0F /*PicInfo - PRIVATE - for reference only */
#define picTxRatio 0x10 /*PicInfo - PRIVATE - for reference only */
#define picVersion 0x11 /*PicInfo - PRIVATE - for reference only */
#define lineNoun 0x20 /*PicInfo - PRIVATE - for reference only */
#define picLine 0x20 /*PicInfo - PRIVATE - for reference only */
#define picLineFrom 0x21 /*PicInfo - PRIVATE - for reference only */
#define picShortL 0x22 /*PicInfo - PRIVATE - for reference only */
#define picShortLFrom 0x23 /*PicInfo - PRIVATE - for reference only */
#define picLongText 0x28 /*PicInfo - PRIVATE - for reference only */
#define picDHText 0x29 /*PicInfo - PRIVATE - for reference only */
#define picDVText 0x2A /*PicInfo - PRIVATE - for reference only */
#define picDVDHText 0x2B /*PicInfo - PRIVATE - for reference only */
#define rectNoun 0x30 /*PicInfo - PRIVATE - for reference only */
#define rRectNoun 0x40 /*PicInfo - PRIVATE - for reference only */
#define ovalNoun 0x50 /*PicInfo - PRIVATE - for reference only */
#define arcNoun 0x60 /*PicInfo - PRIVATE - for reference only */
#define polyNoun 0x70 /*PicInfo - PRIVATE - for reference only */
#define rgnNoun 0x80 /*PicInfo - PRIVATE - for reference only */
#define mapNoun 0x90 /*PicInfo - PRIVATE - for reference only */
#define picBitsRect 0x90 /*PicInfo - PRIVATE - for reference only */
#define picBitsRgn 0x91 /*PicInfo - PRIVATE - for reference only */
#define picPBitsRect 0x98 /*PicInfo - PRIVATE - for reference only */
#define picPBitsRgn 0x99 /*PicInfo - PRIVATE - for reference only */
#define picShortComment 0xA0 /*PicInfo - PRIVATE - for reference only */
#define picLongComment 0xA1 /*PicInfo - PRIVATE - for reference only */
#define picEnd 0xFF /*PicInfo - PRIVATE - for reference only */
#define mode320 0x0000 /*QDStartup - Argument to QDStartup */
#define mode640 0x0080 /*QDStartup - Argument to QDStartup */
#define boldMask 0x0001 /*TextStyle - Mask for bold bit */
#define italicMask 0x0002 /*TextStyle - Mask for italic bit */
#define underlineMask 0x0004 /*TextStyle - Mask for underline bit */
#define outlineMask 0x0008 /*TextStyle - Mask for outline bit */
#define shadowMask 0x0010 /*TextStyle - Mask for shadow bit */
typedef Integer TextStyle;
typedef Integer ColorValue;
typedef Byte AnSCBByte;
typedef unsigned char Pattern[32];
typedef unsigned char Mask[8];
struct Cursor {
   Word cursorHeight; /* size in bytes */
   Word cursorWidth; /* enclosing rectangle */
   Word cursorData[1]; /*   */
   Word cursorMask[1]; /*   */
   Point cursorHotSpot; /*   */
} ;
typedef struct Cursor Cursor, *CursorPtr, **CursorHndl;
struct Region {
   Word rgnSize; /* size in bytes */
   Rect rgnBBox; /* enclosing rectangle */
} ;
typedef struct Region Region, *RgnPtr, **RgnHandle;
struct BufDimRec {
   Word maxWidth; /*  */
   Word textBufHeight; /*  */
   Word textBufferWords; /*  */
   Word fontWidth; /*  */
} ;
typedef struct BufDimRec BufDimRec, *BufDimRecPtr, **BufDimRecHndl;
struct Font {
   Word offseToMF; /* fully defined front of the Font record. */
   Word family; /*  */
   TextStyle style; /*  */
   Word size; /*  */
   Word version; /*  */
   Word fbrExtent; /*  */
} ;
typedef struct Font Font, *FontPtr, **FontHndl;
struct FontGlobalsRecord {
   Word fgFontID; /* currently 12 bytes long, but may be expanded */
   TextStyle fgStyle; /*  */
   Word fgSize; /*  */
   Word fgVersion; /*  */
   Word fgWidMax; /*  */
   Word fgFBRExtent; /*  */
} ;
typedef struct FontGlobalsRecord FontGlobalsRecord, *FontGlobalsRecPtr, **FontGlobalsRecHndl;
struct FontID  {
      Word     famNum;     /* FontID -   */
      Byte     fontStyle;     /* FontID -   */
      Byte     fontSize;     /* FontID -   */
      } ;
typedef struct FontID FontID,  *FontIDPtr,  **FontIDHndl ;

union FontIDUnion {
  FontID fidStruct;
  Long fidLong;
} ;
typedef union FontIDUnion FontIDUnion,  *FontIDUnionPtr, **FontIDUnionHndl;

struct FontInfoRecord {
   Word ascent; /*  */
   Word descent; /*  */
   Word widMax; /*  */
   Word leading; /*  */
} ;
typedef struct FontInfoRecord FontInfoRecord, *FontInfoRecPtr, **FontInfoRecHndl;
struct LocInfo {
   Word portSCB; /* SCBByte in low byte */
   Pointer ptrToPixImage; /* ImageRef */
   Word width; /* Width */
   Rect boundsRect; /* BoundsRect */
} ;
typedef struct LocInfo LocInfo, *LocInfoPtr, **LocInfoHndl;
struct QDProcs {
   VoidProcPtr stdText; /*  */
   VoidProcPtr stdLine; /*  */
   VoidProcPtr stdRect; /*  */
   VoidProcPtr stdRRect; /*  */
   VoidProcPtr stdOval; /*  */
   VoidProcPtr stdArc; /*  */
   VoidProcPtr stdPoly; /*  */
   VoidProcPtr stdRgn; /*  */
   VoidProcPtr stdPixels; /*  */
   VoidProcPtr stdComment; /*  */
   VoidProcPtr stdTxMeas; /*  */
   VoidProcPtr stdTxBnds; /*  */
   VoidProcPtr stdGetPic; /*  */
   VoidProcPtr stdPutPic; /*  */
} ;
typedef struct QDProcs QDProcs, *QDProcsPtr, **QDProcsHndl;
struct GrafPort {
   LocInfo portInfo; /*  */
   Rect portRect; /* PortRect */
   RgnHandle clipRgn; /* Clip Rgn. Pointer */
   RgnHandle visRgn; /* Vis. Rgn. Pointer */
   Pattern bkPat; /* BackGround Pattern */
   Point pnLoc; /* Pen Location */
   Point pnSize; /* Pen Size */
   Word pnMode; /* Pen Mode */
   Pattern pnPat; /* Pen Pattern */
   Mask pnMask; /* Pen Mask */
   Word pnVis; /* Pen Visable */
   FontHndl fontHandle; /*  */
   FontID fontID; /* Font ID */
   Word fontFlags; /* FontFlags */
   Word txSize; /* Text Size */
   TextStyle txFace; /* Text Face */
   Word txMode; /* Text Mode */
   Fixed spExtra; /* Fixed Point Value */
   Fixed chExtra; /* Fixed Point Value */
   Word fgColor; /* ForeGround Color */
   Word bgColor; /* BackGround Color */
   Handle picSave; /* PicSave */
   Handle rgnSave; /* RgnSave */
   Handle polySave; /* PolySave */
   QDProcsPtr grafProcs; /*  */
   Word arcRot; /* ArcRot */
   Longint userField; /* UserField */
   Longint sysField; /* SysField */
} ;
typedef struct GrafPort GrafPort, *GrafPortPtr, **GrafPortHndl;
struct PaintParam {
   LocInfoPtr ptrToSourceLocInfo; /*  */
   LocInfoPtr ptrToDestLocInfo; /*  */
   Rect *ptrToSourceRect; /*  */
   Point *ptrToDestPoint; /*  */
   Word mode; /*  */
   Handle maskHandle; /* clip region */
} ;
typedef struct PaintParam PaintParam, *PaintParamPtr, **PaintParamHndl;
struct PenState {
   Point psPnSize; /*  */
   Word psPnMode; /*  */
   Pattern psPnPat; /*  */
   Mask psPnMask; /*  */
} ;
typedef struct PenState PenState, *PenStatePtr, **PenStateHndl;
struct RomFontRec {
   Word rfFamNum; /*  */
   Word rfFamStyle; /*  */
   Word rfSize; /*  */
   FontHndl rfFontHandle; /*  */
   Pointer rfNamePtr; /*  */
   Word rfFBRExtent; /*  */
} ;
typedef struct RomFontRec RomFontRec, *RomFontRecPtr, **RomFontRecHndl;
struct ColorTable {
   Word entries[16]; /*   */
} ;
typedef struct ColorTable ColorTable, *ColorTablePtr, **ColorTableHndl;
extern pascal void QDBootInit () inline(0x0104,dispatcher);
extern pascal void QDStartUp () inline(0x0204,dispatcher);
extern pascal void QDShutDown () inline(0x0304,dispatcher);
extern pascal Word QDVersion () inline(0x0404,dispatcher);
extern pascal void QDReset () inline(0x0504,dispatcher);
extern pascal Boolean QDStatus () inline(0x0604,dispatcher);
extern pascal void AddPt () inline(0x8004,dispatcher);
extern pascal void CharBounds () inline(0xAC04,dispatcher);
extern pascal Word CharWidth () inline(0xA804,dispatcher);
extern pascal void ClearScreen () inline(0x1504,dispatcher);
extern pascal void ClipRect () inline(0x2604,dispatcher);
extern pascal void ClosePoly () inline(0xC204,dispatcher);
extern pascal void ClosePort () inline(0x1A04,dispatcher);
extern pascal void CloseRgn () inline(0x6E04,dispatcher);
extern pascal void CopyRgn () inline(0x6904,dispatcher);
extern pascal void CStringBounds () inline(0xAE04,dispatcher);
extern pascal Word CStringWidth () inline(0xAA04,dispatcher);
extern pascal void DiffRgn () inline(0x7304,dispatcher);
extern pascal void DisposeRgn () inline(0x6804,dispatcher);
extern pascal void DrawChar () inline(0xA404,dispatcher);
extern pascal void DrawCString () inline(0xA604,dispatcher);
extern pascal void DrawString () inline(0xA504,dispatcher);
extern pascal void DrawText () inline(0xA704,dispatcher);
extern pascal Boolean NotEmptyRect () inline(0x5204,dispatcher);
extern pascal Boolean EmptyRgn () inline(0x7804,dispatcher);
extern pascal Boolean EqualPt () inline(0x8304,dispatcher);
extern pascal Boolean EqualRect () inline(0x5104,dispatcher);
extern pascal Boolean EqualRgn () inline(0x7704,dispatcher);
extern pascal void EraseArc () inline(0x6404,dispatcher);
extern pascal void EraseOval () inline(0x5A04,dispatcher);
extern pascal void ErasePoly () inline(0xBE04,dispatcher);
extern pascal void EraseRect () inline(0x5504,dispatcher);
extern pascal void EraseRgn () inline(0x7B04,dispatcher);
extern pascal void EraseRRect () inline(0x5F04,dispatcher);
extern pascal void FillArc () inline(0x6604,dispatcher);
extern pascal void FillOval () inline(0x5C04,dispatcher);
extern pascal void FillPoly () inline(0xC004,dispatcher);
extern pascal void FillRect () inline(0x5704,dispatcher);
extern pascal void FillRgn () inline(0x7D04,dispatcher);
extern pascal void FillRRect () inline(0x6104,dispatcher);
extern pascal void ForceBufDims () inline(0xCC04,dispatcher);
extern pascal void FrameArc () inline(0x6204,dispatcher);
extern pascal void FrameOval () inline(0x5804,dispatcher);
extern pascal void FramePoly () inline(0xBC04,dispatcher);
extern pascal void FrameRect () inline(0x5304,dispatcher);
extern pascal void FrameRgn () inline(0x7904,dispatcher);
extern pascal void FrameRRect () inline(0x5D04,dispatcher);
extern pascal Pointer GetAddress () inline(0x0904,dispatcher);
extern pascal Word GetArcRot () inline(0xB104,dispatcher);
extern pascal Word GetBackColor () inline(0xA304,dispatcher);
extern pascal void GetBackPat () inline(0x3504,dispatcher);
extern pascal Fixed GetCharExtra () inline(0xD504,dispatcher);
extern pascal void GetClip () inline(0x2504,dispatcher);
extern pascal RgnHandle GetClipHandle () inline(0xC704,dispatcher);
extern pascal Word GetColorEntry () inline(0x1104,dispatcher);
extern pascal void GetColorTable () inline(0x0F04,dispatcher);
extern pascal CursorPtr GetCursorAdr () inline(0x8F04,dispatcher);
extern pascal Word GetFGSize () inline(0xCF04,dispatcher);
extern pascal FontHndl GetFont () inline(0x9504,dispatcher);
extern pascal Word GetFontFlags () inline(0x9904,dispatcher);
extern pascal void GetFontGlobals () inline(0x9704,dispatcher);
extern pascal FontID GetFontID () inline(0xD104,dispatcher);
extern pascal void GetFontInfo () inline(0x9604,dispatcher);
extern pascal Word GetFontLore () inline(0xD904,dispatcher);
extern pascal Word GetForeColor () inline(0xA104,dispatcher);
extern pascal QDProcsPtr GetGrafProcs () inline(0x4504,dispatcher);
extern pascal Word GetMasterSCB () inline(0x1704,dispatcher);
extern pascal void GetPen () inline(0x2904,dispatcher);
extern pascal void GetPenMask () inline(0x3304,dispatcher);
extern pascal Word GetPenMode () inline(0x2F04,dispatcher);
extern pascal void GetPenPat () inline(0x3104,dispatcher);
extern pascal void GetPenSize () inline(0x2D04,dispatcher);
extern pascal void GetPenState () inline(0x2B04,dispatcher);
extern pascal Longint GetPicSave () inline(0x3F04,dispatcher);
extern pascal Word GetPixel () inline(0x8804,dispatcher);
extern pascal LongWord GetPolySave () inline(0x4304,dispatcher);
extern pascal GrafPortPtr GetPort () inline(0x1C04,dispatcher);
extern pascal void GetPortLoc () inline(0x1E04,dispatcher);
extern pascal void GetPortRect () inline(0x2004,dispatcher);
extern pascal LongWord GetRgnSave () inline(0x4104,dispatcher);
extern pascal void GetROMFont () inline(0xD804,dispatcher);
extern pascal Word GetSCB () inline(0x1304,dispatcher);
extern pascal Fixed GetSpaceExtra () inline(0x9F04,dispatcher);
extern pascal Word GetStandardSCB () inline(0x0C04,dispatcher);
extern pascal Longint GetSysField () inline(0x4904,dispatcher);
extern pascal FontHndl GetSysFont () inline(0xB304,dispatcher);
extern pascal TextStyle GetTextFace () inline(0x9B04,dispatcher);
extern pascal Word GetTextMode () inline(0x9D04,dispatcher);
extern pascal Word GetTextSize () inline(0xD304,dispatcher);
extern pascal Longint GetUserField () inline(0x4704,dispatcher);
extern pascal RgnHandle GetVisHandle () inline(0xC904,dispatcher);
extern pascal void GetVisRgn () inline(0xB504,dispatcher);
extern pascal void GlobalToLocal () inline(0x8504,dispatcher);
extern pascal void GrafOff () inline(0x0B04,dispatcher);
extern pascal void GrafOn () inline(0x0A04,dispatcher);
extern pascal void HideCursor () inline(0x9004,dispatcher);
extern pascal void HidePen () inline(0x2704,dispatcher);
extern pascal void InflateTextBuffer () inline(0xD704,dispatcher);
extern pascal void InitColorTable () inline(0x0D04,dispatcher);
extern pascal void InitCursor () inline(0xCA04,dispatcher);
extern pascal void InitPort () inline(0x1904,dispatcher);
extern pascal void InsetRect () inline(0x4C04,dispatcher);
extern pascal void InsetRgn () inline(0x7004,dispatcher);
extern pascal void InvertArc () inline(0x6504,dispatcher);
extern pascal void InvertOval () inline(0x5B04,dispatcher);
extern pascal void InvertPoly () inline(0xBF04,dispatcher);
extern pascal void InvertRect () inline(0x5604,dispatcher);
extern pascal void InvertRgn () inline(0x7C04,dispatcher);
extern pascal void InvertRRect () inline(0x6004,dispatcher);
extern pascal void KillPoly () inline(0xC304,dispatcher);
extern pascal void Line () inline(0x3D04,dispatcher);
extern pascal void LineTo () inline(0x3C04,dispatcher);
extern pascal void LocalToGlobal () inline(0x8404,dispatcher);
extern pascal void MapPoly () inline(0xC504,dispatcher);
extern pascal void MapPt () inline(0x8A04,dispatcher);
extern pascal void MapRect () inline(0x8B04,dispatcher);
extern pascal void MapRgn () inline(0x8C04,dispatcher);
extern pascal void Move () inline(0x3B04,dispatcher);
extern pascal void MovePortTo () inline(0x2204,dispatcher);
extern pascal void MoveTo () inline(0x3A04,dispatcher);
extern pascal RgnHandle NewRgn () inline(0x6704,dispatcher);
extern pascal void ObscureCursor () inline(0x9204,dispatcher);
extern pascal void OffsetPoly () inline(0xC404,dispatcher);
extern pascal void OffsetRect () inline(0x4B04,dispatcher);
extern pascal void OffsetRgn () inline(0x6F04,dispatcher);
extern pascal handle OpenPoly () inline(0xC104,dispatcher);
extern pascal void OpenPort () inline(0x1804,dispatcher);
extern pascal void OpenRgn () inline(0x6D04,dispatcher);
extern pascal void PaintArc () inline(0x6304,dispatcher);
extern pascal void PaintOval () inline(0x5904,dispatcher);
extern pascal void PaintPixels () inline(0x7F04,dispatcher);
extern pascal void PaintPoly () inline(0xBD04,dispatcher);
extern pascal void PaintRect () inline(0x5404,dispatcher);
extern pascal void PaintRgn () inline(0x7A04,dispatcher);
extern pascal void PaintRRect () inline(0x5E04,dispatcher);
extern pascal void PenNormal () inline(0x3604,dispatcher);
extern pascal void PPToPort () inline(0xD604,dispatcher);
extern pascal void Pt2Rect () inline(0x5004,dispatcher);
extern pascal Boolean PtInRect () inline(0x4F04,dispatcher);
extern pascal Boolean PtInRgn () inline(0x7504,dispatcher);
extern pascal Word Random () inline(0x8604,dispatcher);
extern pascal Boolean RectInRgn () inline(0x7604,dispatcher);
extern pascal void RectRgn () inline(0x6C04,dispatcher);
extern pascal void RestoreBufDims () inline(0xCE04,dispatcher);
extern pascal void SaveBufDims () inline(0xCD04,dispatcher);
extern pascal void ScalePt () inline(0x8904,dispatcher);
extern pascal void ScrollRect () inline(0x7E04,dispatcher);
extern pascal Boolean SectRect () inline(0x4D04,dispatcher);
extern pascal void SectRgn () inline(0x7104,dispatcher);
extern pascal void SetAllSCBs () inline(0x1404,dispatcher);
extern pascal void SetArcRot () inline(0xB004,dispatcher);
extern pascal void SetBackColor () inline(0xA204,dispatcher);
extern pascal void SetBackPat () inline(0x3404,dispatcher);
extern pascal void SetBufDims () inline(0xCB04,dispatcher);
extern pascal void SetCharExtra () inline(0xD404,dispatcher);
extern pascal void SetClip () inline(0x2404,dispatcher);
extern pascal void SetClipHandle () inline(0xC604,dispatcher);
extern pascal void SetColorEntry () inline(0x1004,dispatcher);
extern pascal void SetColorTable () inline(0x0E04,dispatcher);
extern pascal void SetCursor () inline(0x8E04,dispatcher);
extern pascal void SetEmptyRgn () inline(0x6A04,dispatcher);
extern pascal void SetFont () inline(0x9404,dispatcher);
extern pascal void SetFontFlags () inline(0x9804,dispatcher);
extern pascal void SetFontID () inline(0xD004,dispatcher);
extern pascal void SetForeColor () inline(0xA004,dispatcher);
extern pascal void SetGrafProcs () inline(0x4404,dispatcher);
extern pascal void SetIntUse () inline(0xB604,dispatcher);
extern pascal void SetMasterSCB () inline(0x1604,dispatcher);
extern pascal void SetOrigin () inline(0x2304,dispatcher);
extern pascal void SetPenMask () inline(0x3204,dispatcher);
extern pascal void SetPenMode () inline(0x2E04,dispatcher);
extern pascal void SetPenPat () inline(0x3004,dispatcher);
extern pascal void SetPenSize () inline(0x2C04,dispatcher);
extern pascal void SetPenState () inline(0x2A04,dispatcher);
extern pascal void SetPicSave () inline(0x3E04,dispatcher);
extern pascal void SetPolySave () inline(0x4204,dispatcher);
extern pascal void SetPort () inline(0x1B04,dispatcher);
extern pascal void SetPortLoc () inline(0x1D04,dispatcher);
extern pascal void SetPortRect () inline(0x1F04,dispatcher);
extern pascal void SetPortSize () inline(0x2104,dispatcher);
extern pascal void SetPt () inline(0x8204,dispatcher);
extern pascal void SetRandSeed () inline(0x8704,dispatcher);
extern pascal void SetRect () inline(0x4A04,dispatcher);
extern pascal void SetRectRgn () inline(0x6B04,dispatcher);
extern pascal void SetRgnSave () inline(0x4004,dispatcher);
extern pascal void SetSCB () inline(0x1204,dispatcher);
extern pascal void SetSolidBackPat () inline(0x3804,dispatcher);
extern pascal void SetSolidPenPat () inline(0x3704,dispatcher);
extern pascal void SetSpaceExtra () inline(0x9E04,dispatcher);
extern pascal void SetStdProcs () inline(0x8D04,dispatcher);
extern pascal void SetSysField () inline(0x4804,dispatcher);
extern pascal void SetSysFont () inline(0xB204,dispatcher);
extern pascal void SetTextFace () inline(0x9A04,dispatcher);
extern pascal void SetTextMode () inline(0x9C04,dispatcher);
extern pascal void SetTextSize () inline(0xD204,dispatcher);
extern pascal void SetUserField () inline(0x4604,dispatcher);
extern pascal void SetVisHandle () inline(0xC804,dispatcher);
extern pascal void SetVisRgn () inline(0xB404,dispatcher);
extern pascal void ShowCursor () inline(0x9104,dispatcher);
extern pascal void ShowPen () inline(0x2804,dispatcher);
extern pascal void SolidPattern () inline(0x3904,dispatcher);
extern pascal void StringBounds () inline(0xAD04,dispatcher);
extern pascal Word StringWidth () inline(0xA904,dispatcher);
extern pascal void SubPt () inline(0x8104,dispatcher);
extern pascal void TextBounds () inline(0xAF04,dispatcher);
extern pascal Word TextWidth () inline(0xAB04,dispatcher);
extern pascal void UnionRect () inline(0x4E04,dispatcher);
extern pascal void UnionRgn () inline(0x7204,dispatcher);
extern pascal void XorRgn () inline(0x7404,dispatcher);
#endif
