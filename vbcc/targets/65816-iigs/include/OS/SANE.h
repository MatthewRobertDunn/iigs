/********************************************
; File: SANE.h
;
;
; Copyright Apple Computer, Inc. 1985, 1986, 1987, 1988
; All Rights Reserved
;
; 09-01-88 JAL  added fabs from previous released sane.h
********************************************/

#ifndef __TYPES__
#include <Types.h>
#endif

#ifndef __SANE__
#define __SANE__

/*
 *  Decimal Representation Constants
 */

#define SIGDIGLEN    28   /* significant decimal digits */
#define DECSTROUTLEN 80   /* max length for dec2str output */

/*
 *  Decimal Formatting Styles
 */

#define FLOATDECIMAL 0
#define FIXEDDECIMAL 1

/*
 *  SANE Exceptions
 */

#define INVALID   1
#define UNDERFLOW 2
#define OVERFLOW  4
#define DIVBYZERO 8
#define INEXACT  16

/*
 *  Ordering Relations
 */

#define GREATERTHAN 0
#define LESSTHAN    1
#define EQUALTO     2
#define UNORDERED   3

/*
 *  Inquiry Classes
 */

#define SNAN        0
#define QNAN        1
#define INFINITE    2
#define ZERONUM     3
#define NORMALNUM   4
#define DENORMALNUM 5

/*
 *  Rounding Directions
 */

#define TONEAREST  0
#define UPWARD     1
#define DOWNWARD   2
#define TOWARDZERO 3

/*
 *  Rounding Precisions
 */

#define EXTPRECISION   0
#define DBLPRECISION   1
#define FLOATPRECISION 2

/*
 *  Type Definitions
 */

typedef short exception;
typedef short environment;
typedef short relop;      /* relational operator */
typedef short numclass;   /* inquiry class */
typedef short rounddir;   /* rounding direction */
typedef short roundpre;   /* rounding precision */

typedef struct decimal {
   short sgn;             /* sign 0 for +, 1 for - */
   short exp;             /* decimal exponent */
   struct {
           unsigned char length, text[SIGDIGLEN], unused;
        } sig;                 /* significant digits */
} decimal;

typedef struct decform {
   short style;           /* FLOATDECIMAL or FIXEDDECIMAL */
   short digits;
} decform;

typedef void (*haltvector)();

/*
 *  JAL  09-01-88  added fabs here
 */

extended fabs();

/*
 *  Conversions between Binary and Decimal Records
 */

void num2dec( /*  decform *f, extended x, decimal *d  */ );
/*
 *  d <-- x, according to format f
 */

extended dec2num( /*  decimal *d  */ );   /* returns d as extended */

/*
 *  Conversions between Decimal Records and ASCII Strings
 */

void dec2str( /*  decform *f, decimal *d, char *s  */ );
/*
 *  s <-- d, according to format f
 */

void str2dec( /*  char *s, short *ix, decimal *d, short *vp  */ );
/*
 *  on input ix is starting index into s,
 *  on output ix is one greater than index of last character of
 *  longest numeric substring;
 *  boolean vp = "s begining at given ix is a valid numeric string or
 *  a valid prefix of some numeric string"
 */

/*
 *  Arithmetic, Auxiliary, and Elementary Functions
 */

extended remainder( /*  extended x, extended y, short *quo  */ );
/*
 *  IEEE remainder; quo <-- 7 low order bits of integer quotient x/y,
 *   -127 <= quo <= 127
 */

extended  sqrt( /*  extended x  */ );   /* square root */
extended  rint( /*  extended x  */ );   /* round to integral value */
extended scalb( /*  short n, extended x  */ );
/*
 *  binary scale: x * 2^n;
 *  first coerces n to short
 */
 
extended logb( /*  extended x  */ );
/*
 *  binary log: binary exponent of normalized x
 */

extended copysign( /*  extended x, extended y  */ );
/*
 *  returns y with sign of x
 */
 
extended nextfloat( /*  extended x, extended y  */ );
/*
 *  next float representation after
 *  (float) x in direction of (float) y
 */
 
extended nextdouble( /*  extended x, extended y  */ );
/*
 *  next double representation after
 *  (double) x in direction of (double) y
 */
 
extended nextextended( /*  extended x, extended y  */ );
/*
 *  next extended representation after x in direction of y
 */
 
extended  log2( /*  extended x  */ );   /* base-2 logarithm */
extended   log( /*  extended x  */ );   /* base-e logarithm */
extended  log1( /*  extended x  */ );   /* log(1 + x) */
extended  exp2( /*  extended x  */ );   /* base-2 exponential */
extended   exp( /*  extended x  */ );   /* base-e exponential */
extended  exp1( /*  extended x  */ );   /* exp(x) - 1 */

extended    power( /*  extended x, extended y  */ );
/*
 *  general exponential: x ^ y
 */
 
extended   ipower( /*  extended x, short i  */ );
/*
 *  integer exponential: x ^ i
 */
 
extended compound( /*  extended r, extended n  */ );
/*
 *  compound: (1 + r) ^ n
 */
 
extended  annuity( /*  extended r, extended n  */ );
/*
 *  annuity: (1 - (1 + r) ^ (-n)) / r
 */
 
extended     tan( /*  extended x  */ );   /* tangent */
extended     sin( /*  extended x  */ );   /* sine */
extended     cos( /*  extended x  */ );   /* cosine */
extended    atan( /*  extended x  */ );   /* arctangent */

extended randomx( /*  extended *x  */ );
/*
 *  returns next random number; updates x
 *  x must be integral, 1 <= x <= 2^31 - 2
 */

/*
 *  Inquiry Routines
 */

numclass    classfloat( /*  extended x  */ );   /* class of (float) x */
numclass   classdouble( /*  extended x  */ );   /* class of (double) x */
numclass     classcomp( /*  extended x  */ );   /* class of (comp) x */
numclass classextended( /*  extended x  */ );   /* class of x */
long           signnum( /*  extended x  */ );   /* returns 0 for +, 1 for - */

/*
 *  Environment Access Routines.
 *  An exception variable encodes the exceptions whose sum is its value.
 */

#define IEEEDEFAULTENV 0   /* IEEE-default floating-point environment */

void setexception( /*  exception e, long s  */ );
/*
 *  clears e flags if s is 0, sets e flags otherwise; may cause halt
 */
 
long testexception( /*  exception e  */ );
/*
 *  returns 1 if any e flag is set, returns 0 otherwise
 */
 
void sethalt( /*  exception e, long s  */ );
/*
 *  disables e halts if s is 0, enables e halts otherwise
 */

long testhalt( /*  exception e  */ );
/*
 *  returns 1 if any e halt is enabled, returns 0 otherwise
 */

void         setround( /*  rounddir r  */ );   /* sets rnd'n direction to r */
rounddir     getround();                       /* rtns current rnd'n direction*/ 
void     setprecision( /*  roundpre p  */ );   /* sets rnd'n precision to p */
roundpre getprecision();                       /* rtns current rnd'n precision*/ 

void   setenvironment( /*  environment e  */ );
/*
 *  sets SANE environment to e
 */

void   getenvironment( /*  environment *e  */ );
/*
 *  e <-- SANE environment
 */

void        procentry( /*  environment *e  */ );
/*
 *  e <-- SANE environment; SANE environment <-- IEEEdefaultenv
 */

void         procexit( /*  environment e  */ );
/*
 *  temp <-- current exceptions; SANE environment <-- e;
 *  signals exceptions in temp
 */

haltvector gethaltvector();                         /* rtns SANE halt vector */ 
void       sethaltvector( /*  haltvector v  */ );   /* SANE halt vector <-- v*/


/*
 *  Comparision Routine
 */

relop relation( /*  extended x, extended y  */ );
/*
 *  returns relation such that "x relation y" is true
 */

/*
 *  NaNs and Special Constants
 */

extended nan( /*  unsigned char c  */ );   /* returns NaN with code c */
extended inf();                            /* returns infinity */
extended  pi();                            /* returns pi */

extern pascal void  SANEBootInit() inline(0x010A, dispatcher);
extern pascal void   SANEStartUp() inline(0x020A, dispatcher);
extern pascal void  SANEShutDown() inline(0x030A, dispatcher);
extern pascal word   SANEVersion() inline(0x040A, dispatcher);
extern pascal void    SANEBReset() inline(0x050A, dispatcher);
extern pascal Boolean SANEStatus() inline(0x060A, dispatcher);

extern pascal void     SANEFP816() inline(0x090A, dispatcher);
extern pascal void SANEDecStr816() inline(0x0A0A, dispatcher);
extern pascal void  SANEElems816() inline(0x0B0A, dispatcher);

#endif
