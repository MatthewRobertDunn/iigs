/********************************************
; File: Shell.h
;
;
; Copyright Apple Computer, Inc.1986-89
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __SHELL__
#define __SHELL__

struct GetLInfoPB {
   Ptr sfile; /* address of source file name */
   Ptr dfile; /* address of output file name */
   Ptr parms; /* address of parameter list */
   Ptr lstring; /* address of language specific input string */
   Byte merr; /* max error level allowed */
   Byte merrf; /* max error level found */
   Byte lops; /* operations flag */
   Byte kflag; /* KEEP flag */
   struct GetLInfoPB **mflags; /* set of letters selected with '-' */
   struct GetLInfoPB **pflags; /* set of letters selected with '+' */
   struct GetLInfoPB **org; /* abs start address of non-relloc load file */
} ;
typedef struct GetLInfoPB GetLInfoPB, *GetLInfoPBPtr;
extern void GET_LINFO();
extern void SET_LINFO();
extern Word GET_LANG();
extern void SET_LANG();
extern void ERROR();
extern void SET_VAR();
extern Word VERSION();
extern void READ_INDEXED();
extern void INIT_WILDCARD();
extern char NEXT_WILDCARD();
extern void GET_VAR();
extern void EXECUTE();
extern void DIRECTION();
extern void REDIRECT();
extern Word STOP();
extern void WRITE_CONSOLE();
#endif
