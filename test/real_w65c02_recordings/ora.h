/*
 * 
 *      .org $a
 *      .byte $01
 *      .byte $02
 *      .word $9000
 *      .word $8fff
 * 
 *      .org $8000
 *  reset:
 *      ldx #$1
 *      ldy #$2
 *      ora $9000
 *      ora $9000,X
 *      ora $8fff,X
 *      ora $9000,Y
 *      ora $8fff,Y
 *      ora #$ee
 *      ora $a
 *      ora ($c,X)
 *      ora $a,X
 *      ora ($c)
 *      ora ($c),Y
 *      ora ($e),Y
 *      nop
 * 
 *      .org $9000
 *      .byte $01, $02
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
ProgramFragment ora_prog[] = {
   {0x000a, 6, {0x01, 0x02, 0x00, 0x90, 0xff, 0x8f}},
   {0x8000, 10, {0xa2, 0x01, 0xa0, 0x02, 0x0d, 0x00, 0x90, 0x1d, 0x00, 0x90}},
   {0x800a, 16, {0x1d, 0xff, 0x8f, 0x19, 0x00, 0x90, 0x19, 0xff, 0x8f, 0x09, 0xee, 0x05, 0x0a, 0x01, 0x0c, 0x15}},
   {0x801a, 8, {0x0a, 0x12, 0x0c, 0x11, 0x0c, 0x11, 0x0e, 0xea}},
   {0x9000, 2, {0x01, 0x02}},
   {0xa000, 1, {0x40}},
   {0xfffb, 5, {0xa0, 0x00, 0x80, 0x00, 0xa0}},
   {0, 0, {0}}
};
PinState ora_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0xa0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8004, 0x0d},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0x1d},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8008, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8009, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800a, 0x1d},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800b, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800c, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800c, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800d, 0x19},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800e, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800f, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9002, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8010, 0x19},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8011, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8012, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8012, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8013, 0x09},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8014, 0xee},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8015, 0x05},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8016, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000a, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8017, 0x01},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8018, 0x0c},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8018, 0x0c},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000d, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000e, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0xff90, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8019, 0x15},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801a, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801a, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000b, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x801b, 0x12},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801c, 0x0c},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000c, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000d, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x801d, 0x11},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801e, 0x0c},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000c, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000d, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9002, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x801f, 0x11},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8020, 0x0e},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000e, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000f, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000f, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8021, 0xea},
};
const size_t ora_cycles = sizeof(ora_pin)/sizeof(ora_pin[0]);
