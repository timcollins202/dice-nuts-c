#include "../lib/neslib.h"
#include "../lib/nesdoug.h"

//in dice-nuts.c
extern unsigned char pad1;
extern unsigned char *current_screen;
extern unsigned char selector_xpos;
extern unsigned char selector_ypos; 

unsigned char pointed_to_die;

void player_actions() 
{
    if (pad1 & PAD_LEFT && selector_xpos > 32) {
        selector_xpos -= 40;
    }
    else if (pad1 & PAD_RIGHT && selector_xpos < 192) {
        selector_xpos += 32;
    }
}