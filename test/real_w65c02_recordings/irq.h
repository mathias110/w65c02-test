/*
 * 
 *     .org $8000
 * reset:
 *     ldx #$ff
 *     txs
 *     clv
 *     cli
 *     nop
 *     nop
 *     nop
 *     nop
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
ProgramFragment irq_prog[] = {
   {0x8000, 9, {0xa2, 0xff, 0x9a, 0xb8, 0x58, 0xea, 0xea, 0xea, 0xea}},
   {0xa000, 1, {0x40}},
   {0xfffb, 5, {0xa0, 0x00, 0x80, 0x00, 0xa0}},
   {0, 0, {0}}
};
PinState irq_0_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01ff, 0x80},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01fe, 0x06},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01fd, 0xa0},
   {1, 1, 0, 1, 1, 0, 0, 1, 1, 0xfffe, 0x00},
   {1, 1, 1, 1, 1, 0, 0, 1, 1, 0xffff, 0xa0},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0xa000, 0x40},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0xa001, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fc, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fd, 0xa0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fe, 0x06},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
};
const size_t irq_0_cycles = sizeof(irq_0_pin)/sizeof(irq_0_pin[0]);
PinState irq_1_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01ff, 0x80},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01fe, 0x06},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01fd, 0xa0},
   {1, 1, 0, 1, 1, 0, 0, 1, 1, 0xfffe, 0x00},
   {1, 1, 0, 1, 1, 0, 0, 1, 1, 0xffff, 0xa0},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0xa000, 0x40},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0xa001, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fc, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fd, 0xa0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fe, 0x06},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
};
const size_t irq_1_cycles = sizeof(irq_1_pin)/sizeof(irq_1_pin[0]);
PinState irq_2_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01ff, 0x80},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01fe, 0x06},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01fd, 0xa0},
   {1, 1, 0, 1, 1, 0, 0, 1, 1, 0xfffe, 0x00},
   {1, 1, 0, 1, 1, 0, 0, 1, 1, 0xffff, 0xa0},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0xa000, 0x40},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0xa001, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fc, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fd, 0xa0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fe, 0x06},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
};
const size_t irq_2_cycles = sizeof(irq_2_pin)/sizeof(irq_2_pin[0]);
PinState irq_3_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01ff, 0x80},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01fe, 0x07},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01fd, 0xa0},
   {1, 1, 0, 1, 1, 0, 0, 1, 1, 0xfffe, 0x00},
   {1, 1, 0, 1, 1, 0, 0, 1, 1, 0xffff, 0xa0},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0xa000, 0x40},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0xa001, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fc, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fd, 0xa0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fe, 0x07},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
};
const size_t irq_3_cycles = sizeof(irq_3_pin)/sizeof(irq_3_pin[0]);
PinState irq_4_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01ff, 0x80},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01fe, 0x07},
   {1, 1, 0, 1, 1, 0, 1, 1, 0, 0x01fd, 0xa0},
   {1, 1, 0, 1, 1, 0, 0, 1, 1, 0xfffe, 0x00},
   {1, 1, 0, 1, 1, 0, 0, 1, 1, 0xffff, 0xa0},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0xa000, 0x40},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0xa001, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fc, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fd, 0xa0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fe, 0x07},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
};
const size_t irq_4_cycles = sizeof(irq_4_pin)/sizeof(irq_4_pin[0]);
PinState irq_5_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8008, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8008, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8009, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8009, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800a, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fe, 0x0b},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fd, 0xb0},
   {1, 1, 1, 1, 1, 0, 0, 1, 1, 0xfffe, 0x00},
   {1, 1, 1, 1, 1, 0, 0, 1, 1, 0xffff, 0xa0},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0xa000, 0x40},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0xa001, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fc, 0x00},
};
const size_t irq_5_cycles = sizeof(irq_5_pin)/sizeof(irq_5_pin[0]);
PinState irq_6_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8008, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8008, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8009, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8009, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800a, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fe, 0x0b},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fd, 0xb0},
   {1, 1, 1, 1, 1, 0, 0, 1, 1, 0xfffe, 0x00},
   {1, 1, 1, 1, 1, 0, 0, 1, 1, 0xffff, 0xa0},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0xa000, 0x40},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0xa001, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fc, 0x00},
};
const size_t irq_6_cycles = sizeof(irq_6_pin)/sizeof(irq_6_pin[0]);
PinState irq_7_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fe, 0x06},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fd, 0xa0},
   {1, 1, 1, 1, 1, 0, 0, 1, 1, 0xfffe, 0x00},
   {1, 1, 1, 1, 1, 0, 0, 1, 1, 0xffff, 0xa0},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0xa000, 0x40},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0xa001, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fc, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fd, 0xa0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fe, 0x06},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
};
const size_t irq_7_cycles = sizeof(irq_7_pin)/sizeof(irq_7_pin[0]);
PinState irq_8_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 0, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8008, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8008, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8009, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8009, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800a, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fe, 0x0b},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fd, 0xb0},
   {1, 1, 1, 1, 1, 0, 0, 1, 1, 0xfffe, 0x00},
   {1, 1, 1, 1, 1, 0, 0, 1, 1, 0xffff, 0xa0},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0xa000, 0x40},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0xa001, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fc, 0x00},
};
const size_t irq_8_cycles = sizeof(irq_8_pin)/sizeof(irq_8_pin[0]);
PinState irq_9_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xb8},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8004, 0x58},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8005, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 0, 1, 1, 1, 1, 1, 1, 0x8006, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0xea},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fe, 0x07},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fd, 0xa0},
   {1, 1, 1, 1, 1, 0, 0, 1, 1, 0xfffe, 0x00},
   {1, 1, 1, 1, 1, 0, 0, 1, 1, 0xffff, 0xa0},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0xa000, 0x40},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0xa001, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fc, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fd, 0xa0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01fe, 0x07},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x01ff, 0x80},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0xea},
};
const size_t irq_9_cycles = sizeof(irq_9_pin)/sizeof(irq_9_pin[0]);
PinTestSuite irq_suite[] = {
   {irq_0_pin, irq_0_cycles},
   {irq_1_pin, irq_1_cycles},
   {irq_2_pin, irq_2_cycles},
   {irq_3_pin, irq_3_cycles},
   {irq_4_pin, irq_4_cycles},
   {irq_5_pin, irq_5_cycles},
   {irq_6_pin, irq_6_cycles},
   {irq_7_pin, irq_7_cycles},
   {irq_8_pin, irq_8_cycles},
   {irq_9_pin, irq_9_cycles},
   {0, 0}
};