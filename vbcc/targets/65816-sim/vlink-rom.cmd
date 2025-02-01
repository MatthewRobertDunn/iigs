STACKLEN = 0x400;
WRAMSTART = 0x80000;
WRAMSIZE = 0x80000;
LORAMSTART = 0x0000;
LORAMSIZE = 0x8000;
ROMSTART = 0x8000;
ROMSIZE = 0x78000;


MEMORY
{
 out : org = 0x0000, len = 0x080000

 zero : org = 2 , len = 253

 loram : org = LORAMSTART + 256, len = (LORAMSIZE-256-STACKLEN)
 wram : org = (WRAMSTART + LORAMSIZE), len = WRAMSIZE-LORAMSIZE
 vectors : org = 0xFFE0, len = 0x20

 lrom : org = 0x008000, len = 0x8000 - 0x20
 hrom : org = 0x010000, len = ROMSIZE - 0x8000

}

SECTIONS
{

  nrom  : {*(*_text.startup) *(*_text.near.*) *(*_rodata.near.*) *(.ctors) *(.dtors) *(text) *(*_text*) *(*_rodata.*) } >lrom AT>out
  /* vector table if needed */
  fill : {.=0x10000-0x8000;} >out

  from (BANKSIZE=65536): {*(*_text.far.*) *(*_rodata.far.*) *(ctors) *(dtors)} >hrom AT>out
  hrom : {*(*_text.huge.*) *(*_rodata.huge.*) } >hrom AT>out

  ndata: {*(*_data.near.*)} >loram AT>out
  nbss (NOLOAD): {*(*_bss.near.*)} >loram
  fdata (BANKSIZE=65536): { *(SORT_BY_SIZE(*_data.far.*))} >wram AT>out
  fbss (BANKSIZE=65536) (NOLOAD): { *(SORT_BY_SIZE(*_bss.far.*))} >wram
  hdata: { *(*_data.huge.*)} >wram AT>out
  hbss (NOLOAD): { *(*_bss.huge.*)} >wram

  zpage (NOLOAD) : {*(zpage) *(zp1) *(zp2)} >zero

  ___heap = MAX(ADDR(fbss) + SIZEOF(fbss),ADDR(hbss)+SIZEOF(hbss));
  ___heapend = WRAMSTART+WRAMSIZE;

  __NDS = ADDR(ndata);
  __NDE = ADDR(ndata) +  SIZEOF(ndata);
  __NDC = MAX(ADDR(from)+SIZEOF(from),ADDR(hrom)+SIZEOF(hrom));

  __NBS = ADDR(nbss);
  __NBE = ADDR(nbss) + SIZEOF(nbss);

  __FDS = ADDR(fdata);
  __FDE = ADDR(fdata) +  SIZEOF(fdata);
  __FDC = __NDC+SIZEOF(ndata);

  __FBS = ADDR(fbss);
  __FBE = ADDR(fbss) + SIZEOF(fbss);

  __HDS = ADDR(hdata);
  __HDE = ADDR(hdata) +  SIZEOF(hdata);
  __HDC = __FDC+SIZEOF(fdata);

  __HBS = ADDR(hbss);
  __HBE = ADDR(hbss) + SIZEOF(hbss);

  __DBR_init = 0;
}

