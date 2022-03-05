/*
 * 
 *      .org $a
 *      .byte $01
 *      .byte $75
 * 
 *      .org $8000
 *  reset:
 *      ldx #$1
 *      lda #$2
 *      ror $9000
 *      ror $9000,X
 *      ror $8fff,X
 *      ror
 *      ror $a
 *      ror $a,X
 *      nop
 * 
 *      .org $9000
 *      .byte $05, $02
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
ProgramFragment ror_prog[] = {
   {0x000a, 2, {0x01, 0x75}},
   {0x8000, 10, {0xa2, 0x01, 0xa9, 0x02, 0x6e, 0x00, 0x90, 0x7e, 0x00, 0x90}},
   {0x800a, 9, {0x7e, 0xff, 0x8f, 0x6a, 0x66, 0x0a, 0x76, 0x0a, 0xea}},
   {0x9000, 2, {0x05, 0x02}},
   {0xa000, 1, {0x40}},
   {0xfffb, 5, {0xa0, 0x00, 0x80, 0x00, 0xa0}},
   {0, 0, {0}}
};
PinState ror_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0xa9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8004, 0x6e},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x05},
   {1, 1, 1, 1, 1, 0, 1, 0, 1, 0x9000, 0x05},
   {1, 1, 1, 1, 1, 0, 1, 0, 0, 0x9000, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0x7e},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8008, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8009, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 0, 1, 0, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 0, 1, 0, 0, 0x9001, 0x81},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800a, 0x7e},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800b, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800c, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800c, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x02},
   {1, 1, 1, 1, 1, 0, 1, 0, 1, 0x9000, 0x02},
   {1, 1, 1, 1, 1, 0, 1, 0, 0, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800d, 0x6a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800e, 0x66},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800e, 0x66},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800f, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000a, 0x01},
   {1, 1, 1, 1, 1, 0, 1, 0, 1, 0x000a, 0x01},
   {1, 1, 1, 1, 1, 0, 1, 0, 0, 0x000a, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8010, 0x76},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8011, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8011, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000b, 0x75},
   {1, 1, 1, 1, 1, 0, 1, 0, 1, 0x000b, 0x75},
   {1, 1, 1, 1, 1, 0, 1, 0, 0, 0x000b, 0xba},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8012, 0xea},
};
const size_t ror_cycles = sizeof(ror_pin)/sizeof(ror_pin[0]);