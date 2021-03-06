/*
 * 
 *      .org $7ff0
 *  bvc_1:
 *      bvc bvc_2
 * 
 *      .org $8000
 *  reset:
 *      lda #$00
 *      clc
 *      adc #$ff
 *      bvc bvc_1
 *  bvc_2:
 *      bvc bvc_3
 *      nop
 *  bvc_3:
 *      adc #$80
 *      bvc bvc_4
 *      nop
 *  bvc_4:
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
ProgramFragment bvc_prog[] = {
   {0x7ff0, 2, {0x50, 0x15}},
   {0x8000, 16, {0xa9, 0x00, 0x18, 0x69, 0xff, 0x50, 0xe9, 0x50, 0x01, 0xea, 0x69, 0x80, 0x50, 0x01, 0xea, 0xea}},
   {0xa000, 1, {0x40}},
   {0xfffb, 5, {0xa0, 0x00, 0x80, 0x00, 0xa0}},
   {0, 0, {0}}
};
PinState bvc_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x18},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0x69},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0x69},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8005, 0x50},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0xe9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0x50},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0x50},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x7ff0, 0x50},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x7ff1, 0x15},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x7ff2, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x7ff2, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0x50},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8008, 0x01},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8009, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800a, 0x69},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800b, 0x80},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800c, 0x50},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800d, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800e, 0xea},
};
const size_t bvc_cycles = sizeof(bvc_pin)/sizeof(bvc_pin[0]);
