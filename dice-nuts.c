#include "lib/neslib.h"
#include "lib/nesdoug.h"

#include "src/graphics.h"
#include "src/player_actions.h"
#include "data/nametables.h"


// Define palettes
const unsigned char bg_palette[16] = { 
    0x0f, 0x00, 0x10, 0x30,
    0x0f, 0x0c, 0x21, 0x32,
    0x0f, 0x05, 0x16, 0x30,
    0x0f, 0x0b, 0x1a, 0x29 
};

const unsigned char spr_palette[16] = {
    0x0f, 0x05, 0x15, 0x27,
    0x0f, 0x14, 0x24, 0x34,
    0x0f, 0x1b, 0x2b, 0x3b,
    0x0f, 0x12, 0x22, 0x32
};


// Global Variables
unsigned char pad1;
unsigned char *current_screen;

unsigned char selector_xpos;
unsigned char selector_ypos;


void main() 
{
    // Turn the screen off
    ppu_off();

    // Load palettes
    pal_bg(bg_palette);
    pal_spr(spr_palette);

    //Set sprite bank.  BG defaults to 0, SPR set to 1
    bank_spr(1);

    // Clear sprites
    oam_clear();

    // Display title screen
    current_screen = titlescreen;
    display_screen();

    // Wait for the start button to be pressed
    while (1) {
        pad1 = pad_trigger(0);
        if (pad1 & PAD_START) { break; }
        ppu_wait_frame(); 
    }

    // Display playfield
    current_screen = playfield;
    display_screen();

    // Initialize selector position
    selector_xpos = 32;
    selector_ypos = 72;

    // Game loop
    while (1) {
        //wait for beginning of frame
        ppu_wait_frame(); 

        //read controller 1
        pad1 = pad_trigger(0);
        
        player_actions();
        draw_sprites();
    }
}