/*
 * 
 *      .org $8000
 *  reset:
 *      ldx #$ff
 *      txs
 *      jsr sub
 *      nop
 *  sub:
 *      rts
 * 
 *      .org $a000
 *  irq:
 *  nmi:
 *      rti
 * 
 *      .org $fffa
 *      .word nmi
 *      .word reset
 *      .word irq
 *  
*/
ProgramFragment jsr_prog[] = {
   {0x8000, 8, {0xa2, 0xff, 0x9a, 0x20, 0x07, 0x80, 0xea, 0x60}},
   {0xa000, 1, {0x40}},
   {0xfffb, 5, {0xa0, 0x00, 0x80, 0x00, 0xa0}},
   {0, 0, {0}}
};
PinState jsr_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0x20},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0x20},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x07},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01ff, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fe, 0x05},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0x80},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0x60},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8008, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fd, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fe, 0x05},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0x80},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
};
const size_t jsr_cycles = sizeof(jsr_pin)/sizeof(jsr_pin[0]);
