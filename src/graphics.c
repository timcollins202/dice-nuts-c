#include "../lib/neslib.h"
#include "../lib/nesdoug.h"
#include "../data/metatiles.h"

extern unsigned char *current_screen;

extern unsigned char selector_xpos;
extern unsigned char selector_ypos; 

//x offset, y offset, tile, attribute. 128 terminates
const unsigned char metasprite_selector[]={
    0, 0, 0x02, 0,
    8, 0, 0x02, 0|OAM_FLIP_H,
    0, 33, 0x02, 0|OAM_FLIP_V,
    8, 33, 0x02, 0|OAM_FLIP_H|OAM_FLIP_V,
    128
};

//Draw the screen pointed to by current_screen
void display_screen() 
{
    // Turn PPU off
    ppu_off();

    //Set brightness to 0 for fade effect
    pal_bright(0);

    // Clear nametable and load playfield data
    vram_adr(NAMETABLE_A);
    vram_unrle(current_screen); 

    // Turn screen back on
    ppu_on_all();

    //Fade the screen in
    pal_fade_to(0, 4);
}

void draw_sprites() 
{
    //clear sprite buffer
    oam_clear();

    //Draw selector metasprite
    oam_meta_spr(selector_xpos, selector_ypos, metasprite_selector);
}


