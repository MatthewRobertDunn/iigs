STACKLEN = 0x400;
WRAMSTART = 0x7E0000;
WRAMSIZE = 0x20000;
LORAMSTART = 0x0000;
LORAMSIZE = 0x2000;
ROMSIZE = 0x8000;

MEMORY
{
 out : org = 0x0000, len = 0x1000000

 loram : org = LORAMSTART, len = LORAMSIZE
 wram : org = (WRAMSTART + LORAMSIZE), len = WRAMSIZE-LORAMSIZE
 header : org = 0xFFC0, len = 0x20
 vectors : org = 0xFFE0, len = 0x20

 lrom : org = 0x008000, len = 0x8000 - 0x40

}

SECTIONS
{
  zpage (NOLOAD) : {*(zpage) *(zp1) *(zp2)} >loram

  nrom : {.=0x8000; *(*_text.startup) *(.ctors) *(.dtors) *(text) *(*_text*) *(*_rodata.*) } >lrom AT>out
  ndata: {*(*_data.*)} >loram AT>out
  fill : {RESERVE(0x7FC0-SIZEOF(ndata)-SIZEOF(nrom));} >out
  header : {EXTERN(___header_mini_ntsc)  *(*header)} >header AT>out
  vectors : {EXTERN(___vecs) *(*vectors)} >vectors AT>out

  nbss (NOLOAD): {*(*_bss.*)} >loram


  ___heap = ADDR(nbss) + SIZEOF(nbss);
  ___heapend = LORAMSTART+LORAMSIZE-STACKLEN;

  __NDS = ADDR(ndata);
  __NDE = ADDR(ndata) + SIZEOF(ndata);
  __NDC = ADDR(nrom) + SIZEOF(nrom);
  __NDCNT = __NDE - __NDS;

  __NBS = ADDR(nbss);
  __NBE = ADDR(nbss) + SIZEOF(nbss);

  __DBR_init = 0;
}

