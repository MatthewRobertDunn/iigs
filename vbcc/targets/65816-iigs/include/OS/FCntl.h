/*
 * fcntl.h -- fAccess(), fcntl(), and open() mode flags
 *
 * Copyright American Telephone & Telegraph
 * Modified and used with permission, Apple Computer Inc.
 * Copyright Apple Computer Inc. 1985, 1986, 1987
 * All rights reserved.
 */

#ifndef __FCNTL__
#define __FCNTL__
/*
 * fAccess() commands
 */
# define F_OPEN         (('d'<<8)|00)         /* 'd' => "directory" ops */
# define F_DELETE       (('d'<<8)|01)
# define F_RENAME       (('d'<<8)|02)
# define F_TYPE         (('d'<<8)|03)
# define F_AUX          (('d'<<8)|04)

# define F_GTABINFO     (('e'<<8)|00)         /* 'e' => "editor" ops */ 
# define F_STABINFO     (('e'<<8)|01)
# define F_GFONTINFO    (('e'<<8)|02)
# define F_SFONTINFO    (('e'<<8)|03)
# define F_GPRINTREC    (('e'<<8)|04)
# define F_SPRINTREC    (('e'<<8)|05)

/*
 * Mode values accessible to open()
 */
# define O_RDONLY    0        /* Bits 0 and 1 are used internally */
# define O_WRONLY    1        /* Values 0..2 are historical */
# define O_RDWR      2
# define O_APPEND   (1<<3)    /* append (writes guaranteed at the end) */
# define O_RSRC   (1<<4)      /* OPEN the resource fork */
# define O_BINARY (1<<5)
# define O_CREAT      (1<<8)      /* OPEN with file create */
# define O_TRUNC      (1<<9)      /* OPEN with truncation */
# define O_EXCL   (1<<10)     /* Exclusive open */

/*
 * fcntl() requests
 */
# define F_DUPFD 0    /* Duplicate fildes */

long lseek();

# endif __FCNTL__
