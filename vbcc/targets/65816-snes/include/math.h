
#ifndef __MATH_H
#define __MATH_H 1

#define HUGE_VAL        1e500

/*
  Several of these functions may be well-suited to
  inline-assembly.
*/

double sin(double);
double cos(double);
double tan(double);
double sinh(double);
double cosh(double);
double tanh(double);
double asin(double);
double acos(double);
double atan(double);
double exp(double);
double __exp_r(__reg("r0/r1") double);
#define exp(x) __exp_r(x)
double log(double);
double __log_r(__reg("r0/r1") double);
#define log(x) __log_r(x)
double log10(double);
double __log10_r(__reg("r0/r1") double);
#define log10(x) __log10_r(x)
double pow(double,double);
double sqrt(double);
double ceil(double);
double floor(double);
double fabs(double);
double atan2(double,double);
double ldexp(double,int);
double frexp(double,int *);
double modf(double,double *);
double fmod(double,double);

int    isinf(double);
int    isnan(double);



#endif
