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
// Have levels 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "player.h"
#include "enemies.h"

#define ESCAPE_KEY 27
#define TAB_KEY 9

int main(){
    //Inital Message/Test
    printf("Welcome to my CLI_RPG, I hope you have fun! Press esc whenevr you'd like to exit, press tab to access your iventory.\n");

    //Create the player the user will be using
    Player character;
    player_init(&character);

    //testing player display
    player_display(&character);

    // Game start print
    printf("You awaken beneath the soft rustle of leaves, the scent of wildflowers and morning dew in the air. Sunlight filters gently through a canopy of trees above you.\n");
    printf("Your clothes are worn, your hands are calloused… but your mind is a haze. No name comes to you. No past. Only the sound of birdsong and the distant whisper of a stream.\n");
    printf("Wherever you are, your story begins now.");

    if(character.class == 'k'){
        printf("You look down and see tattered chainmail covering you from your toes to your chest, a battered helmet and long sword lie next to you, you pick them up.\n");
    }else{
        printf("You look down and you see you are wearing a long robe, a mystical wand lies next to you, as you reach for it floats and lands in your hand, fitting perfectly.\n");
    }

    printf(" \n");

    printf("You notice a familiar feeling lodge down a dirtpath to your right, you head over and enter it, all that is there is a bed and dresser with one window.\n");

    printf(" \n");

    printf("You open the top drawer of the dresser and within there lies a note: ''Further down this path the dragon awaits you in the cave, and into the forest the goblin king does the same''\n");
    printf("''The choice of whom you face first is yours, but you are the only warrior capable of defeating them.''\n");

    //Variable to hold the current enemy the player is battling
    

    //Variable to check what key the user is pressing
    char key_pressed;
    //Varaible to hold
    int game_running = true;
    //Integrating Game Loop
    while(game_running){
        prtinf("What would you like to do? ")


        //check for user exit and inventory check
        if (kbhit()) {  // Checks if a key has been pressed
            key_pressed = getch();  // Reads the pressed key without waiting for Enter

            if (key_pressed == ESCAPE_KEY) { // Check if the pressed key is Escape
                game_running = false; // Set the flag to exit the loop
        }
    }

            if (kbhit()) {  // Checks if a key has been pressed
            key_pressed = getch();  // Reads the pressed key without waiting for Enter

            if (key_pressed == TAB_KEY) { // Check if the pressed key is Tab
                player_display(&character); //Display inventory if tab is pressed
        }
    }
}
};
