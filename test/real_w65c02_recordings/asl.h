/*
 * 
 *     .org $a
 *     .byte $20
 *     .byte $11
 * 
 *     .org $8000
 * reset:
 *     ldx #$ff
 *     txs
 *     lda #$01
 *     ldx #$01
 *     asl $9000
 *     asl $9000,X
 *     asl $8fff,X
 *     asl
 *     asl $a
 *     asl $a,X
 *     pha
 * 
 *     .org $9000
 *     .byte $1, $2
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
ProgramFragment asl_prog[] = {
   {0x000a, 2, {0x20, 0x11}},
   {0x8000, 10, {0xa2, 0xff, 0x9a, 0xa9, 0x01, 0xa2, 0x01, 0x0e, 0x00, 0x90}},
   {0x800a, 12, {0x1e, 0x00, 0x90, 0x1e, 0xff, 0x8f, 0x0a, 0x06, 0x0a, 0x16, 0x0a, 0x48}},
   {0x9000, 2, {0x01, 0x02}},
   {0xa000, 1, {0x40}},
   {0xfffb, 5, {0xa0, 0x00, 0x80, 0x00, 0xa0}},
   {0, 0, {0}}
};
PinState asl_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xa9},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xa9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8005, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0x0e},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8008, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8009, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 0, 1, 0, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 0, 1, 0, 0, 0x9000, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800a, 0x1e},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800b, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800c, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 0, 1, 0, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 0, 1, 0, 0, 0x9001, 0x04},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800d, 0x1e},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800e, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800f, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800f, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x02},
   {1, 1, 1, 1, 1, 0, 1, 0, 1, 0x9000, 0x02},
   {1, 1, 1, 1, 1, 0, 1, 0, 0, 0x9000, 0x04},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8010, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8011, 0x06},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8011, 0x06},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8012, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000a, 0x20},
   {1, 1, 1, 1, 1, 0, 1, 0, 1, 0x000a, 0x20},
   {1, 1, 1, 1, 1, 0, 1, 0, 0, 0x000a, 0x40},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8013, 0x16},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8014, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8014, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000b, 0x11},
   {1, 1, 1, 1, 1, 0, 1, 0, 1, 0x000b, 0x11},
   {1, 1, 1, 1, 1, 0, 1, 0, 0, 0x000b, 0x22},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8015, 0x48},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8016, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01ff, 0x02},
};
const size_t asl_cycles = sizeof(asl_pin)/sizeof(asl_pin[0]);
