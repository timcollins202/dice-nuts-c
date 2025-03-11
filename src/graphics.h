#ifndef GRAPHICS_H
#define GRAPHICS_H

//x offset, y offset, tile, attribute
const unsigned char metasprite_selector[]={
    0, 0, 0x02, 0,
    0, 8, 0x02, 0,
    8, 0, 0x02, 0|OAM_FLIP_H,
    8, 8, 0x02, 0|OAM_FLIP_H,
    128
};

//Display the screen pointed to by current_screen
void display_screen(void);

#endif