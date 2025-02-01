/********************************************
; File: TextEdit.h
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
#include <Font.h>
#endif

#ifndef __GSOS__
#include <GSOS.h>
#endif

#ifndef __RESOURCES__
#include <Resources.h>
#endif

#ifndef __CONTROL__
#include <Control.h>
#endif

#ifndef __TEXTEDIT__
#define __TEXTEDIT__

#define teAlreadyStarted 0x2201 /*error -  */
#define teNotStarted 0x2202 /*error -  */
#define teInvalidHandle 0x2203 /*error -  */
#define teInvalidVerb 0x2204 /*error -  */
#define teInvalidFlag 0x2205 /*error -  */
#define teInvalidPCount 0x2206 /*error -  */
#define teInvalidRect 0x2207 /*error -  */
#define teBufferOverflow 0x2208 /*error -  */
#define teInvalidLine 0x2209 /* -  */
#define teInvalidCall 0x220A /* -  */
#define NullVerb 0x0 /*TE -  */
#define PStringVerb 0x0001 /*TE -  */
#define CStringVerb 0x0002 /*TE -  */
#define C1InputVerb 0x0003 /*TE -  */
#define C1OutputVerb 0x0004 /*TE -  */
#define HandleVerb 0x0005 /*TE -  */
#define PointerVerb 0x0006 /*TE -  */
#define NewPStringVerb 0x0007 /*TE -  */
#define fEqualLineSpacing 0x8000 /*TE -  */
#define fShowInvisibles 0x4000 /*TE -  */
#define teInvalidDescriptor 0x2204 /* -  */
#define teInvalidParameter 0x220B /* -  */
#define teInvalidTextBox2 0x220C /* -  */
#define teEqualLineSpacing 0x8000 /* -  */
#define teShowInvisibles 0x4000 /* -  */
#define teJustLeft 0x0 /* -  */
#define teJustRight 0x1 /* -  */
#define teJustCenter 0x2 /* -  */
#define teJustFull 0x3 /* -  */
#define teNoTabs 0x0 /* -  */
#define teColumnTabs 0x1 /* -  */
#define teAbsoluteTabs 0x2 /* -  */
#define teLeftTab 0x0 /* -  */
#define teCenterTab 0x1 /* -  */
#define teRightTab 0x2 /* -  */
#define teDecimalTab 0x3 /* -  */
#define teInvis 0x4000 /* -  */
#define teCtlColorIsPtr 0x0000 /* -  */
#define teCtlColorIsHandle 0x0004 /* -  */
#define teCtlColorIsResource 0x0008 /* -  */
#define teCtlStyleIsPtr 0x0000 /* -  */
#define teCtlStyleIsHandle 0x0001 /* -  */
#define teCtlStyleIsResource 0x0002 /* -  */
#define teNotControl 0x80000000L /* -  */
#define teSingleFormat 0x40000000L /* -  */
#define teSingleStyle 0x20000000L /* -  */
#define teNoWordWrap 0x10000000L /* -  */
#define teNoScroll 0x08000000L /* -  */
#define teReadOnly 0x04000000L /* -  */
#define teSmartCutPaste 0x02000000L /* -  */
#define teTabSwitch 0x01000000L /* -  */
#define teDrawBounds 0x00800000L /* -  */
#define teColorHilite 0x00400000L /* -  */
#define teRefIsPtr 0x0000 /* -  */
#define teRefIsHandle 0x0001 /* -  */
#define teRefIsResource 0x0002 /* -  */
#define teRefIsNewHandle 0x0003 /* -  */
#define teDataIsPString 0x0000 /* -  */
#define teDataIsCString 0x0001 /* -  */
#define teDataIsC1Input 0x0002 /* -  */
#define teDataIsC1Output 0x0003 /* -  */
#define teDataIsTextBox2 0x0004 /* -  */
#define teDataIsTextBlock 0x0005 /* -  */
#define teTextIsPtr 0x0000 /* -  */
#define teTextIsHandle 0x0008 /* -  */
#define teTextIsResource 0x0010 /* -  */
#define teTextIsNewHandle 0x0018 /* -  */
#define tePartialLines 0x8000L /* -  */
#define teDontDraw 0x4000 /* -  */
#define teUseFont 0x0020 /* -  */
#define teUseSize 0x0010 /* -  */
#define teUseForeColor 0x0008 /* -  */
#define teUseBackColor 0x0004 /* -  */
#define teUseUserData 0x0002 /* -  */
#define teUseAttributes 0x0001 /* -  */
#define teReplaceFont 0x0040 /* -  */
#define teReplaceSize 0x0020 /* -  */
#define teReplaceForeColor 0x0010 /* -  */
#define teReplaceBackColor 0x0008 /* -  */
#define teReplaceUserField 0x0004 /* -  */
#define teReplaceAttributes 0x0002 /* -  */
#define teSwitchAttributes 0x0001 /* -  */
#define teEraseRect 0x0001 /* -  */
#define teEraseBuffer 0x0002 /* -  */
#define teRectChanged 0x0003 /* -  */
#define doEraseRect 0x0001 /*  -  */
#define doEraseBuffer 0x0002 /*  -  */
#define doRectChanged 0x0003 /*  -  */
#define doKeyStroke 0x0004 /*  -  */
struct TEColorTable {
   Word contentColor; /*   */
   Word outlineColor; /*   */
   Word pageBoundaryColor; /*   */
   Word hiliteForeColor; /*   */
   Word hiliteBackColor; /*   */
   Word vertColorDescriptor; /*   */
   LongWord vertColorRef; /*   */
   Word horzColorDescriptor; /*   */
   LongWord horzColorRef; /*  */
   Word growColorDescriptor; /*   */
   LongWord growColorRef; /*   */
} ;
typedef struct TEColorTable TEColorTable, *TEColorTablePtr;
struct TEBlockEntry {
   Handle text; /*   */
   Handle length; /*   */
   Word flags; /*   */
} ;
typedef struct TEBlockEntry TEBlockEntry;
struct TEBlocksRecord {
   LongWord start; /*   */
   Word index; /*   */
   TEBlockEntry blocks[1]; /*   */
} ;
typedef struct TEBlocksRecord TEBlocksRecord, *TEBlocksPtr, **TEBlocksHndl;
struct TERecord {
   CtlRecHndl ctlNext; /*   */
   WindowPtr ctlOwner; /*   */
   Rect ctlRect; /*   */
   Byte ctlFlag; /*   */
   Byte ctlHilite; /*   */
   Word ctlValue; /*   */
   ProcPtr ctlProc; /*   */
   ProcPtr ctlAction; /*   */
   LongWord ctlData; /*   */
   LongWord ctlRefCon; /*   */
   TEColorTablePtr ctlColorRef; /*   */
   LongWord textLength; /*   */
   TEBlocksHndl blockList; /*   */
   ProcPtr filterProc; /*   */
   LongWord reserved1; /*   */
   LongWord ctlID; /*   */
   Word ctlMoreFlags; /*   */
   Word ctlVersion; /*   */
   Word theChar; /*   */
   Word theModifiers; /*   */
   Word extendFlag; /*   */
   Word moveByWord; /*   */
   Ptr inputPtr; /*   */
   LongWord inputLength; /*   */
   Rect theRect; /*   */
} ;
typedef struct TERecord TERecord, *TERecordPtr, **TEHandle;
struct TETabItem {
   Word tabKind; /*   */
   Word tabData; /*   */
} ;
typedef struct TETabItem TETabItem;
struct TERuler {
   Word leftMargin; /*   */
   Word leftIndent; /*   */
   Word rightMargin; /*   */
   Word just; /*   */
   Word extraLS; /*   */
   Word flags; /*   */
   Word userData; /*   */
   Word tabType; /*   */
   TETabItem tabs[1]; /*   */
   Word tabTerminator; /*   */
} ;
typedef struct TERuler TERuler;
struct TEStyle {
   FontID teFont; /*   */
   Word foreColor; /*   */
   Word backColor; /*   */
   LongWord reserved; /*   */
} ;
typedef struct TEStyle TEStyle;
struct TEStyleGroup {
   Word count; /*   */
   TEStyle styles[1]; /*   */
} ;
typedef struct TEStyleGroup TEStyleGroup, *TEStyleGroupPtr, **TEStyleGroupHndl;
struct TEStyleItem {
   LongWord length; /*   */
   LongWord offset; /*   */
} ;
typedef struct TEStyleItem TEStyleItem;
struct TEFormat {
   Word version; /*   */
   LongWord rulerListLength; /*   */
   TERuler theRulerList[1]; /*   */
   LongWord styleListLength; /*   */
   TEStyle theStyleList[1]; /*   */
   LongWord numberOfStyles; /*   */
   TEStyleItem theStyles[1]; /*   */
} ;
typedef struct TEFormat TEFormat, *TEFormatPtr, **TEFormatHndl;
typedef struct TETextRef {
     Ptr TETextDesc;
} TETextRef,*TETextRefPtr, **TETextRefHndl;

typedef struct TEStyleRef {
      Ptr TEStyleDesc ;
} TEStyleRef,*TEStyleRefPtr,**TEStyleRefHndl ;

struct TEParamBlock {
   Word pCount; /*   */
   LongWord controlID; /*   */
   Rect boundsRect; /*   */
   LongWord procRef; /*   */
   Word flags; /*   */
   Word moreflags; /*   */
   LongWord refCon; /*   */
   LongWord textFlags; /*   */
   Rect indentRect; /*   */
   CtlRecHndl vertBar; /*   */
   Word vertScroll; /*   */
   CtlRecHndl horzBar; /*   */
   Word horzScroll; /*   */
   TEStyleRef styleRef; /*   */
   Word textDescriptor; /*   */
   TETextRef textRef; /*   */
   LongWord textLength; /*   */
   LongWord maxChars; /*   */
   LongWord maxLines; /*   */
   Word maxHeight; /*   */
   Word pageHeight; /*   */
   Word headerHeight; /*   */
   Word footerHeight; /*   */
   Word pageBoundary; /*   */
   LongWord colorRef; /*   */
   Word drawMode; /*   */
   ProcPtr filterProcPtr; /*   */
} ;
typedef struct TEParamBlock TEParamBlock, *TEParamBlockPtr, **TEParamBlockHndl;
struct TEInfoRec {
   LongWord charCount; /*   */
   LongWord lineCount; /*   */
   LongWord formatMemory; /*   */
   LongWord totalMemory; /*   */
   LongWord styleCount; /*   */
   LongWord rulerCount; /*   */
} ;
typedef struct TEInfoRec TEInfoRec;
struct TEHooks {
   ProcPtr charFilter; /*   */
   ProcPtr wordWrap; /*   */
   ProcPtr wordBreak; /*   */
   ProcPtr drawText; /*   */
   ProcPtr eraseText; /*   */
} ;
typedef struct TEHooks TEHooks;
extern pascal void TEBootInit () inline(0x0122,dispatcher);
extern pascal void TEStartup () inline(0x0222,dispatcher);
extern pascal void TEShutdown () inline(0x0322,dispatcher);
extern pascal Word TEVersion () inline(0x0422,dispatcher);
extern pascal void TEReset () inline(0x0522,dispatcher);
extern pascal Word TEStatus () inline(0x0622,dispatcher);
extern pascal void TEActivate () inline(0x0F22,dispatcher);
extern pascal void TEClear () inline(0x1922,dispatcher);
extern pascal void TEClick () inline(0x1122,dispatcher);
extern pascal void TECut () inline(0x1622,dispatcher);
extern pascal void TECopy () inline(0x1722,dispatcher);
extern pascal void TEDeactivate () inline(0x1022,dispatcher);
extern pascal ProcPtr TEGetDefProc () inline(0x2222,dispatcher);
extern pascal void TEGetHooks () inline(0x2022,dispatcher);
extern pascal void TEGetSelection () inline(0x1C22,dispatcher);
extern pascal Word TEGetSelectionStyle () inline(0x1E22,dispatcher);
extern pascal LongWord TEGetText () inline(0x0C22,dispatcher);
extern pascal void TEGetTextInfo () inline(0x0D22,dispatcher);
extern pascal void TEIdle () inline(0x0E22,dispatcher);
extern pascal void TEInsert () inline(0x1A22,dispatcher);
extern pascal void TEInsertPageBreak () inline(0x1522,dispatcher);
extern pascal void TEKey () inline(0x1422,dispatcher);
extern pascal void TEKill () inline(0x0A22,dispatcher);
extern pascal TEHandle TENew () inline(0x0922,dispatcher);
extern pascal LongWord TEPaintText () inline(0x1322,dispatcher);
extern pascal void TEPaste () inline(0x1822,dispatcher);
extern pascal void TEReplace () inline(0x1B22,dispatcher);
extern pascal void TESetHooks () inline(0x2122,dispatcher);
extern pascal void TESetSelection () inline(0x1D22,dispatcher);
extern pascal void TESetText () inline(0x0B22,dispatcher);
extern pascal void TEStyleChange () inline(0x1F22,dispatcher);
extern pascal void TEUpdate () inline(0x1222,dispatcher);
extern pascal void TEGetRuler() inline(0x2322,dispatcher);
extern pascal void TEOffsetToPoint() inline(0x2022,dispatcher);
extern pascal LongWord TEPointToOffset() inline(0x2122,dispatcher);
extern pascal LongWord TEScroll() inline(0x2522,dispatcher);
extern pascal LongWord TESetRuler() inline(0x2422,dispatcher);
#endif
