#include "../lib/neslib.h"
#include "../lib/nesdoug.h"

#define MAX_DICE 6

unsigned char dice_values[MAX_DICE];    //stores the dice values we have rolled
unsigned char dice_selected[MAX_DICE];  //1 if selected, 0 if not

unsigned char random_number;            //random value 1-6 we'll use as a die roll
unsigned char toggle_index;             //set before calling toggle_die_selection()

void roll_die() 
{
    do{
        random_number = rand8() & 0x07;     //mask off the lowest 3 bits 0-7
    } while (random_number >= 5);           //reject values 6 and 7 (leaving 0-5)

    random_number += 1;                     //shift range to 1-6
}

void roll_unselected_dice() 
{
    unsigned char i;
    
    for ( i = 0; i < MAX_DICE; i++) {
        if (!dice_selected[i]) {
            roll_die();
            dice_values[i] = (random_number);
        }
    }
}

void toggle_die_selection() 
{
    if (toggle_index < MAX_DICE) {
        dice_selected[toggle_index] ^= 1;   //toggle between 0 and 1
    }
}