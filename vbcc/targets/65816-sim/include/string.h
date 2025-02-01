#ifndef __STRING_H
#define __STRING_H 1

#ifndef __SIZE_T
#define __SIZE_T 1
#ifdef __SIZE_T_INT
typedef unsigned int size_t;
#else
typedef unsigned long size_t;
#endif
#endif

#undef NULL
#define NULL ((void *)0)

void _fmemcpy(__far void *,const __far void *,size_t);
void *memcpy(void *,const void *,size_t);
void *memmove(void *,const void *,size_t);
char *strcpy(char *,const char *);
char *strncpy(char *,const char *,size_t);
char *strcat(char *,const char *);
char *strncat(char *,const char *,size_t);
int memcmp(const void *,const void *,size_t);
int strcmp(const char *,const char *);
int strncmp(const char *,const char *,size_t);
void *memchr(const void *,int,size_t);
char *strchr(const char *,int);
size_t strcspn(const char *,const char *);
char *strpbrk(const char *,const char *);
char *strrchr(const char *,int);
size_t strspn(const char *,const char *);
char *strstr(const char *,const char *);
void *memset(void *,int,size_t);
size_t strlen(const char *);
char *strtok(char *,const char *);
char *strerror(int);
int strcoll(const char *,const char *);
size_t strxfrm(char *,const char *,size_t);

#if !defined(__NOINLINE__) && defined(__OPTSPEED__)
#endif /* !__NOINLINE__ && __OPTSPEED__ */

#endif /* __STRING_H */
