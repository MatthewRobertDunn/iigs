/********************************************
; File: Types.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#define __TYPES__

#ifdef __VBCC__
#define pascal __pascal
#define inline(n,d) ="\tinline\n\tldx\t#"#n"\n\tjsl\t$E10000\n\tbcs\t.1\n\tlda\t#0\n\.1:\n\tsta\t>__toolErr\n\teinline"
void pascal __sysCall(int x,void *p)="\tinline\n\tjsl\t$E100B0\n\tbcs\t.1\n\tlda\t#0\n.1:\n\tsta\t>__toolErr\n\teinline";
#define sysCall(a,b) __sysCall((b),(a))
#define extended void
#endif

#ifndef noError /*  -  */
#define noError 0x0000
#endif
#ifndef nil /*  -  */
#define nil 0x0L
#endif
#ifndef NULL /* -  */
#define NULL 0x0L
#endif
#ifndef NIL /* -  */
#define NIL 0x0L
#endif
#define dispatcher 0xE10000L /* - tool locator dispatch address */
#define TRUE 1
#define true TRUE
#define FALSE 0
#define false FALSE

#define refIsPointer 0x0000 /* RefDescriptor -  */
#define refIsHandle 0x0001 /* RefDescriptor -  */
#define refIsResource 0x0002 /* RefDescriptor -  */
#define refIsNewHandle 0x0003 /* RefDescriptor -  */
typedef unsigned char byte, Byte;
typedef unsigned int word, Word ;
typedef int integer, Integer;
typedef long longint, Longint ;
typedef long Long;
typedef unsigned long longword, Longword, LongWord ;
typedef unsigned long Dblword, DblWord ; /* retained for back compatibility */
typedef long Fixed;
typedef long Frac;
typedef extended *ExtendedPtr ;
typedef char *ptr, *Ptr, *pointer, *Pointer;
typedef ptr *handle, *Handle;
typedef Handle *HandlePtr ;
typedef char *CStringPtr, **CStringHndl, ***CStringHndlPtr ;
typedef long (*ProcPtr)();  /* retained for back compatibility */
typedef pascal void (*VoidProcPtr)();
typedef pascal Word (*WordProcPtr)();
typedef pascal LongWord (*LongProcPtr)();

typedef unsigned int boolean, Boolean, BOOLEAN;
typedef short OSErr;
typedef int *IntPtr ;
typedef Ptr FPTPtr;
#define String(size) struct { unsigned char length; unsigned char text[size]; }
typedef String(255) Str255, *StringPtr, **StringHandle;


typedef String(32) Str32, *String32Ptr, **String32Handle;

struct Point {
   Word v; /*   */
   Word h; /*   */
} ;
typedef struct Point Point, *PointPtr;
struct Rect {
   Word v1; /*   */
   Word h1; /*   */
   Word v2; /*   */
   Word h2; /*   */
} ;
typedef struct Rect Rect, *RectPtr, **RectHndl;
struct TimeRec {
   Byte second; /*   */
   Byte minute; /*   */
   Byte hour; /*   */
   Byte year; /*   */
   Byte day; /*   */
   Byte month; /*   */
   Byte extra; /*   */
   Byte weekDay; /*   */
} ;
typedef struct TimeRec TimeRec, *TimeRecPtr, **TimeRecHndl;
typedef Word RefDescriptor ;



typedef Long Ref ;
extern unsigned _ownerid;
extern int _toolErr;
#endif
