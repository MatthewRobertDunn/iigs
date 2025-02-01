MEMSTART = 0x200;
STACKLEN = 0x400;
RAMSIZE = 0x100000;

MEMORY
{
 zero : org = 0x02 , len = 253
 start : org = 0x200, len = 0x100
 near: org = 0x300, len=0x10000-STACKLEN-0x300

 ram: org = 0x10000, len=RAMSIZE-0x10000
}

SECTIONS
{
  zpage (NOLOAD) : {*(zpage) *(zp1) *(zp2)} >zero

  start : {*(*_text.startup)} >start
  ndata : { *(*data.near.*) *(*.near.*) *(*_bss.*) } >near

  constr : {*(.dtors) *(.ctors)} >ram

  far (BANKSIZE=65536) : { *(*text*) *(*_rodata.far.*) *(*_data.far.*) *(*.far.*)} >ram
  huge : { *(*data.*) *(*_bss.*) } >ram

  ___heap = ADDR(ndata) + SIZEOF(ndata);
  ___heapend = 0x10000-STACKLEN;
  __DBR_init = ADDR(ndata);
}
