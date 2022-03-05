/*
 * 
 *     .org $a
 *     .byte $20
 *     .word $9000
 *     .word $8fff
 * 
 *     .org $8000
 * reset:
 *     ldx #$ff
 *     txs
 *     lda #$00
 *     ldx #$01
 *     ldy #$03
 *     clc
 *     sbc $9000
 *     sbc $9000,X
 *     sbc $8fff,X
 *     sbc $9000,Y
 *     sbc $8fff,Y
 *     sbc #$10
 *     sbc $a
 *     sbc ($9,X)
 *     sbc $9,X
 *     sbc ($b)
 *     sbc ($b),Y
 *     sbc ($d),Y
 *     sed
 *     sbc $9,X
 *     pha
 *     phx
 *     phy
 *     php
 * 
 *     .org $9000
 *     .byte $1,$2,$3
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
ProgramFragment sbc_prog[] = {
   {0x000a, 5, {0x20, 0x00, 0x90, 0xff, 0x8f}},
   {0x8000, 10, {0xa2, 0xff, 0x9a, 0xa9, 0x00, 0xa2, 0x01, 0xa0, 0x03, 0x18}},
   {0x800a, 16, {0xed, 0x00, 0x90, 0xfd, 0x00, 0x90, 0xfd, 0xff, 0x8f, 0xf9, 0x00, 0x90, 0xf9, 0xff, 0x8f, 0xe9}},
   {0x801a, 16, {0x10, 0xe5, 0x0a, 0xe1, 0x09, 0xf5, 0x09, 0xf2, 0x0b, 0xf1, 0x0b, 0xf1, 0x0d, 0xf8, 0xf5, 0x09}},
   {0x802a, 4, {0x48, 0xda, 0x5a, 0x08}},
   {0x9000, 3, {0x01, 0x02, 0x03}},
   {0xa000, 1, {0x40}},
   {0xfffb, 5, {0xa0, 0x00, 0x80, 0x00, 0xa0}},
   {0, 0, {0}}
};
PinState sbc_pin[] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8000, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8001, 0xff},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8002, 0x9a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8003, 0xa9},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8003, 0xa9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8004, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8005, 0xa2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8006, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8007, 0xa0},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8008, 0x03},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8009, 0x18},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800a, 0xed},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800a, 0xed},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800b, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800c, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x800d, 0xfd},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800e, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x800f, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9001, 0x02},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8010, 0xfd},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8011, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8012, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8012, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8013, 0xf9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8014, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8015, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9003, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8016, 0xf9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8017, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8018, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8018, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9002, 0x03},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8019, 0xe9},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801a, 0x10},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x801b, 0xe5},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801c, 0x0a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000a, 0x20},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x801d, 0xe1},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801e, 0x09},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x801e, 0x09},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000a, 0x20},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000b, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x0020, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x801f, 0xf5},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8020, 0x09},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8020, 0x09},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000a, 0x20},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8021, 0xf2},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8022, 0x0b},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000b, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000c, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9000, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8023, 0xf1},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8024, 0x0b},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000b, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000c, 0x90},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9003, 0x00},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8025, 0xf1},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8026, 0x0d},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000d, 0xff},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000e, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000e, 0x8f},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x9002, 0x03},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8027, 0xf8},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8028, 0xf5},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x8028, 0xf5},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8029, 0x09},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x8029, 0x09},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x000a, 0x20},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x802a, 0x48},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x802a, 0x48},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x802b, 0xda},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01ff, 0x83},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x802b, 0xda},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x802c, 0x5a},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fe, 0x01},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x802c, 0x5a},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x802d, 0x08},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fd, 0x03},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 0x802d, 0x08},
   {1, 1, 1, 1, 1, 0, 1, 1, 1, 0x802e, 0x00},
   {1, 1, 1, 1, 1, 0, 1, 1, 0, 0x01fc, 0xbd},
};
const size_t sbc_cycles = sizeof(sbc_pin)/sizeof(sbc_pin[0]);