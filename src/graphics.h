#ifndef GRAPHICS_H
#define GRAPHICS_H

//Metasprite of dice selector arrows
extern const unsigned char metasprite_selector[];

//Display the screen pointed to by current_screen
void display_screen();

//Push sprite data to OAM
void draw_sprites();

#endif