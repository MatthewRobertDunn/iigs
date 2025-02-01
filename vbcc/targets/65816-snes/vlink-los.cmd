MEMSTART = 0x200;
STACKLEN = 0x400;
WRAMSTART = 0x7E0000;
WRAMSIZE = 0x20000;
LORAMSTART = 0x0000;
LORAMSIZE = 0x2000;
INIT = 0x48000;

MEMORY
{
 outlo : org = 0x008000, len = 0x800000

 zero : org = 0 , len = 255

 loram : org = LORAMSTART + 256, len = (LORAMSIZE-256)
 wram : org = (WRAMSTART + 0x2000), len = 0x20000
 header : org = 0xFFC0, len = 0x20
 vectors : org = 0xFFE0, len = 0x20

 /* WS1 LoROM (max 2048 Kbytes) (64x32K) 2.68MHz */
 lorom0: org = 0x008000, len=(0x8000-0x40)
 lorom1: org = 0x018000, len=0x8000
 lorom2: org = 0x028000, len=0x8000
 lorom3: org = 0x038000, len=0x8000
 lorom4: org = 0x048000, len=0x8000
 lorom5: org = 0x058000, len=0x8000
 lorom6: org = 0x068000, len=0x8000
 lorom7: org = 0x078000, len=0x8000
 /* up to lorom63 possible */
}

SECTIONS
{
  start : {.=0x8000; *(*_text.startup) } >lorom0 AT>outlo
  text0 : {*(*_text.startup) *(.ctors) *(.dtors) *(text) *(*_text*) *(*_rodata.*) } >lorom0 AT>outlo
  fill0 : {.=0xFFC0;} >lorom0 AT>outlo
  header : {EXTERN(___header_lorom_ntsc) *(*header)} >header AT>outlo
  vectors : {EXTERN(___vecs) *(*vectors)} >vectors AT>outlo

  text1 : {.=0x18000; *(*_text.startup) *(*_text.*) *(*_rodata.*)} >lorom1 AT>outlo
  fill1 : {.=0x20000;} >lorom1 AT>outlo

  text2 : {.=0x28000; *(*_text.startup) *(*_text.*) *(*_rodata.*)} >lorom2 AT>outlo
  fill2 : {.=0x30000;} >lorom2 AT>outlo

  text3 : {.=0x38000; *(*_text.startup) *(*_text.*) *(*_rodata.*)} >lorom3 AT>outlo
  fill3 : {.=0x40000;} >lorom3 AT>outlo

/*
  ...
*/

  ndata: {*(*_data.near*)} >loram AT>outlo
  nbss (NOLOAD): {*(*_bss.near.*)} >loram
  fdata: { *(*_data.far.*)} >wram AT>outlo
  fbss (NOLOAD): { *(*_bss.far.*)} >wram
  zpage (NOLOAD) : {*(zpage) *(zp1) *(zp2)} >zero

  filll : {RESERVE(0x8000-SIZEOF(ndata)-SIZEOF(fdata));} >outlo

  ___heap = ADDR(nbss) + SIZEOF(nbss);
  ___heapend = LORAMSTART+LORAMSIZE-STACKLEN;

  __NEAR__ = ADDR(ndata);

  __NDS = ADDR(ndata);
  __NDE = ADDR(ndata) +  SIZEOF(ndata);
  __NDC = INIT;

  __NBS = ADDR(nbss);
  __NBE = ADDR(nbss) + SIZEOF(nbss);

  __FDS = ADDR(fdata);
  __FDE = ADDR(fdata) +  SIZEOF(fdata);
  __FDC = INIT+SIZEOF(ndata);

  __FBS = ADDR(fbss);
  __FBE = ADDR(fbss) + SIZEOF(fbss);

  __HDS = 0;
  __HDE = 0;
  __HDC = 0;

  __HBS = 0;
  __HBE = 0;

  __DBR_init = 0;
}

