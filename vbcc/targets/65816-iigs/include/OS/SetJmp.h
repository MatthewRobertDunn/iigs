/*
 * SetJmp.h
 *
 * Copyright 1986, Apple Computer
 * All rights reserved.
 */
 
typedef long jmp_buf[2];         

int  setjmp();
void longjmp();
