/*
 * 
 *     .org $7ff0
 * beq_1:
 *     beq beq_2
 * 
 *     .org $8000
 * reset:
 *     lda #$00
 *     beq beq_1
 * beq_2:
 *     beq beq_3
 *     nop
 * beq_3:
 *     ina
 *     beq beq_4
 *     nop
 * beq_4:
 *     nop
 * 
 *     .org $a000
 * irq:
 * nmi:
 *     rti
 * 
 *     .org $fffa
 *     .word nmi
 *     .word reset
 *     .word irq
 * 
*/
ProgramFragment beq_prog[] = {
   {0x7ff0, 2, {0xf0, 0x12}},
   {0x8000, 12, {0xa9, 0x00, 0xf0, 0xec, 0xf0, 0x01, 0xea, 0x1a, 0xf0, 0x01, 0xea, 0xea}},
   {0xa000, 1, {0x40}},
   {0xfffb, 5, {0xa0, 0x00, 0x80, 0x00, 0xa0}},
   {0, 0, {0}}
};
PinState beq_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0xf0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xec},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0xf0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0xf0},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x7ff0, 0xf0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x7ff1, 0x12},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x7ff2, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x7ff2, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8004, 0xf0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0x01},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0x1a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8008, 0xf0},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8008, 0xf0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8009, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800a, 0xea},
};
const size_t beq_cycles = sizeof(beq_pin)/sizeof(beq_pin[0]);
