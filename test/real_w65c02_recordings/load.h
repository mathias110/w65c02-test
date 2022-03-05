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
 *      lda $9000
 *      ldx $9000
 *      ldy $9000
 *      lda $9000,X
 *      ldy $9000,X
 *      lda $8fff,X
 *      ldy $8fff,X
 *      lda $9000,Y
 *      ldx $9000,Y
 *      lda $8fff,Y
 *      ldx $8fff,Y
 *      lda #$01
 *      ldx #$02
 *      ldy #$03
 *      lda $a
 *      ldx $b
 *      ldy $b
 *      lda ($c,X)
 *      lda $a,X
 *      ldy $9,X
 *      ldx $a,Y
 *      lda ($c)
 *      lda ($c),Y
 *      lda ($e),Y
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
ProgramFragment load_prog[] = {
   {0x000a, 6, {0x01, 0x02, 0x00, 0x90, 0xff, 0x8f}},
   {0x8000, 10, {0xad, 0x00, 0x90, 0xae, 0x00, 0x90, 0xac, 0x00, 0x90, 0xbd}},
   {0x800b, 14, {0x90, 0xbc, 0x00, 0x90, 0xbd, 0xff, 0x8f, 0xbc, 0xff, 0x8f, 0xb9, 0x00, 0x90, 0xbe}},
   {0x801a, 16, {0x90, 0xb9, 0xff, 0x8f, 0xbe, 0xff, 0x8f, 0xa9, 0x01, 0xa2, 0x02, 0xa0, 0x03, 0xa5, 0x0a, 0xa6}},
   {0x802a, 16, {0x0b, 0xa4, 0x0b, 0xa1, 0x0c, 0xb5, 0x0a, 0xb4, 0x09, 0xb6, 0x0a, 0xb2, 0x0c, 0xb1, 0x0c, 0xb1}},
   {0x803a, 2, {0x0e, 0xea}},
   {0x9000, 2, {0x01, 0x02}},
   {0xa000, 1, {0x40}},
   {0xfffb, 5, {0xa0, 0x00, 0x80, 0x00, 0xa0}},
   {0, 0, {0}}
};
PinState load_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xad},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8002, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xae},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8005, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8006, 0xac},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8007, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8008, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8009, 0xbd},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800a, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800b, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800c, 0xbc},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800d, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800e, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800f, 0xbd},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8010, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8011, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8011, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8012, 0xbc},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8013, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8014, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8014, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8015, 0xb9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8016, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8017, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8018, 0xbe},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8019, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801a, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x801b, 0xb9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801c, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801d, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801d, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x801e, 0xbe},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801f, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8020, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8020, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8021, 0xa9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8022, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8023, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8024, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8025, 0xa0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8026, 0x03},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8027, 0xa5},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8028, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000a, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8029, 0xa6},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x802a, 0x0b},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000b, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x802b, 0xa4},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x802c, 0x0b},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000b, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x802d, 0xa1},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x802e, 0x0c},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x802e, 0x0c},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000e, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000f, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8fff, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x802f, 0xb5},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8030, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8030, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000c, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8031, 0xb4},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8032, 0x09},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8032, 0x09},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000b, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8033, 0xb6},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8034, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8034, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000c, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8035, 0xb2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8036, 0x0c},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000c, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000d, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8037, 0xb1},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8038, 0x0c},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000c, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000d, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9002, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8039, 0xb1},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x803a, 0x0e},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000e, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000f, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000f, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x803b, 0xea},
};
const size_t load_cycles = sizeof(load_pin)/sizeof(load_pin[0]);