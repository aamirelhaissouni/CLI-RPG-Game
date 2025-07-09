#include "player.h"
#include <stdio.h>
#include <conio.h>

// Set up player function
voidplayer_init(Player* player){
    char n[12];
    printf("Please enter your characters name (max 12 characters): \n");
    scanf("%s", &n);
    int c;
    printf("Enter your desired class, press K for Knight, N for Necromancer\n ");
    c = getch();
    putch(c);
};

//Display player stats/inventory:
/*
void player_display(Player* player){

}; 
*/
