#include "../lib/neslib.h"
#include "../lib/nesdoug.h"

//in dice-nuts.c
extern unsigned char pad1;
extern unsigned char *current_screen;
extern unsigned char selector_xpos;
extern unsigned char selector_ypos; 

void player_actions(void) 
{
    if (pad1 & PAD_LEFT && selector_xpos > 31) {
        selector_xpos -= 40;
    }
    else if (pad1 & PAD_RIGHT && selector_xpos < 111) {
        selector_xpos += 40;
    }
    else if (pad1 & PAD_DOWN && selector_ypos < 50) {
        selector_ypos += 32;
    }
    else if (pad1 & PAD_UP && selector_ypos > 18) {
        selector_ypos -= 32;
    }
}