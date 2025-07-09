/*
Git Commands:
- git add .
- git commit -m 
- git push -u origin main
*/


// Start of CLI game 
// Made by Aamir Elhaissouni
// Started 7-7-25

// Game Goals:
// Have a game Loop
// Have different classes
// Have different stats
// Have an inventory
// Have levels (health, mana, strength etc)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"

int main(){
    //Inital Message/Test
    printf("Welcome to my CLI_RPG, I hope you have fun!\n");
    //Create the player the user will be using
    Player character;
    player_init(&character);
}
