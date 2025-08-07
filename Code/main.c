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

#include "player.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include "enemies.h"
#include "locations.h"

#define ESCAPE_KEY 27
#define TAB_KEY 9
#define timey 5

int main(void) {
  // Inital Message/Test
  printf("Welcome to my CLI_RPG, I hope you have fun!\n");
  printf(" \n");

  // World initialization
  World *world;
  world = world_init();

  // Create the player the user will be using
  Player character;
  player_init(&character);

  // testing player display
  // player_display(&character);

  // Game start print
  printf(" \n");
  printf("You awaken beneath the soft rustle of leaves, the scent of "
         "wildflowers and morning dew in the air. Sunlight filters gently "
         "through a canopy of trees above you.\n");
  sleep(timey);
  printf("Your clothes are worn, your hands are calloused but your mind is a "
         "haze. No name comes to you. No past. Only the sound of birdsong and "
         "the distant whisper of a stream.\n");
  sleep(timey);
  printf("Wherever you are, your story begins now.");
  sleep(timey);
  printf(" \n");

  if (character.class == 'k') {
    printf(" \n");
    printf("You look down and see tattered chainmail covering you from your "
           "toes to your chest, a battered helmet and long sword lie next to "
           "you, you pick them up.\n");
  } else {
    printf(" \n");
    printf("You look down and you see you are wearing a long robe, a mystical "
           "wand lies next to you, as you reach for it floats and lands in "
           "your hand, fitting perfectly.\n");
  }

  printf(" \n");
  printf(" \n");

  printf("You notice a familiar feeling lodge down a dirtpath to your right, "
         "you head over and enter it, all that is there is a bed and dresser "
         "with one window.\n");

  printf(" \n");

  sleep(timey);

  printf("You open the top drawer of the dresser and within there lies a note: "
         "''Further down this lodge follwing a cobbled path and west, the "
         "dragon awaits you in the cave. Eastwards down the path lies the "
         "Goblin and his castle.''\n");
  sleep(timey);
  printf("Next to the note there is a potion, it's familiar scent tells you it "
         "heals you. You place it in your pocket.\n");

  sleep(timey);
  // NEED TO ADD POTION TO PLAYERS INVENTORY
  printf("''The choice of whom you face first is yours, you are the only "
         "warrior capable of defeating them.''\n");
  sleep(timey);
  
  // Variable to check what key the user is pressing
  char key_pressed;
  // Varaible to hold user exit
  int game_running = true;
  // variable to hold user type input
  char whatToDo[20];

  //////////////// ENEMIES/BATTLING AREA

  // array of enemy structs to hold spawned enemies
  // Enemy* enemies[10];

  /////////////// END OF ENEMIES/BATTLING AREA

  //////////////////////////////////////////////////

  ///////////////START OF GAME LOOP

  // Integrating Game Loop
  while (game_running) {
    sleep(1);
    printf(" \n");
    printf("What would you like to do? \n");
    printf(" \n");
    printf("Type Options: 'Go', 'Flee', 'Location', 'Exit', 'Inventory' \n");

    // check for user exit and inventory check
    // try to implement this later but will def use it for battling
    // still have to figure out non-conio.h way to implement
    /*
    if (kbhit()) {  //Checks if a key has been pressed
        key_pressed = getch();  //Reads the pressed key without waiting for
    Enter

        if (key_pressed == ESCAPE_KEY) { //Check if the pressed key is Escape
            game_running = false; //Set the flag to exit the loop
        }
    }else if (kbhit()) {  //Checks if a key has been pressed
        key_pressed = getch();  //Reads the pressed key without waiting for
    Enter

        if (key_pressed == TAB_KEY) { //Check if the pressed key is Tab
                player_display(&character); //Display inventory if tab is
    pressed
        }
    }
    */
    scanf("%s", &whatToDo);

    // Check what user wants to do based on input
    // If user wants to move:
    if (strcmp(whatToDo, "go") == 0 || strcmp(whatToDo, "Go") == 0 ||
        strcmp(whatToDo, "GO") == 0) {
      // print a map of the players current location
      if (character.loc->north) {
        printf("  %s", character.loc->north->name);
      } else {
        printf("    X");
      }
      printf("    |\n");
      printf("    |\n");
      if (character.loc->west) {
        printf("%s ", character.loc->west->name);
      } else {
        printf("X ");
      }
      printf("----");
      printf("%s", character.loc->name);
      printf("-----");
      if (character.loc->east) {
        printf(" %s", character.loc->east->name);
      } else {
        printf("X");
      }
      printf("    |\n");
      printf("    |\n");
      if (character.loc->south) {
        printf("    %s\n", character.loc->south->name);
      } else {
        printf("    X\n");
      }

      char go;
      printf("Where would you like to go? (Valid inputs: n, s, e, w, (x to "
             "stay))\n");

      // gather user input and try to move
      scanf(" %c", &go);
      if (go == 'x') {
        continue;
      } else {
        move_player(world, &character, go);
      }
    } else if (strcmp(whatToDo, "Inventory") == 0 ||
               strcmp(whatToDo, "inventory") == 0 ||
               strcmp(whatToDo, "INVENTORY") ==
                   0) { // check if user wants to see their inventory then print
                        // it out
      player_display(&character);
    } else if (strcmp(whatToDo, "Location") == 0 ||
               strcmp(whatToDo, "Location") == 0 ||
               strcmp(whatToDo, "Location") ==
                   0) { // check if user wants to see their location then print
                        // it out
      printf(" \n");
      printf("Name: %s\n", character.loc->name);
      printf(" \n");
      printf("Description: %s\n", character.loc->description);
      printf(" \n");
    } else if (strcmp(whatToDo, "Exit") == 0 || strcmp(whatToDo, "exit") == 0 ||
               strcmp(whatToDo, "EXIT") == 0) { // check if user wants to exit
      game_running = false;
      // checks if game_running is true or false, if false it exits the game
      // loop and exits the game as a whole
      if (!game_running) {
        break;
      }
    }
  }

  return 0;
}
