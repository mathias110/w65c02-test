/*
 * 
 *      .org $7ff0
 *  bvs_1:
 *      bvs bvs_2
 * 
 *      .org $8000
 *  reset:
 *      lda #$ff
 *      clc
 *      adc #$80
 *      bvs bvs_1
 *  bvs_2:
 *      bvs bvs_3
 *      nop
 *  bvs_3:
 *      clv
 *      bvs bvs_4
 *      nop
 *  bvs_4:
 *      nop
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
ProgramFragment bvs_prog[] = {
   {0x7ff0, 2, {0x70, 0x15}},
   {0x8000, 15, {0xa9, 0xff, 0x18, 0x69, 0x80, 0x70, 0xe9, 0x70, 0x01, 0xea, 0xb8, 0x70, 0x01, 0xea, 0xea}},
   {0xa000, 1, {0x40}},
   {0xfffb, 5, {0xa0, 0x00, 0x80, 0x00, 0xa0}},
   {0, 0, {0}}
};
PinState bvs_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x18},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0x69},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0x69},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x80},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8005, 0x70},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0xe9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0x70},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0x70},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x7ff0, 0x70},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x7ff1, 0x15},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x7ff2, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x7ff2, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0x70},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8008, 0x01},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8009, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800a, 0xb8},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800b, 0x70},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800b, 0x70},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800c, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800d, 0xea},
};
const size_t bvs_cycles = sizeof(bvs_pin)/sizeof(bvs_pin[0]);