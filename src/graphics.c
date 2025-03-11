#include "lib/neslib.h"
#include "lib/nesdoug.h"

extern unsigned char *current_screen;

//Puts a string into VRAM
void put_str(unsigned int adr, const char *str) {
    vram_adr(adr);

    while (1) {
        if (!*str) break;

        vram_put((*str++) - 0x20); // -0x20 because ASCII code 0x20 is placed in tile 0 of the CHR
    }
}

//Draw the screen pointed to by current_screen
void display_screen(void) 
{
    // Turn PPU off
    ppu_off();

    //Set brightness to 0 for fade effect
    pal_bright(0);

    // Clear nametable and load playfield data
    vram_adr(NAMETABLE_A);
    vram_unrle(current_screen); // Decompress and write playfield data

    // Turn screen back on
    ppu_on_all();

    //Fade the screen in
    pal_fade_to(0, 4);
}
