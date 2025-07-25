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
#include "locations.h"

#define ESCAPE_KEY 27
#define TAB_KEY 9

int main(){
    //Inital Message/Test
    printf("Welcome to my CLI_RPG, I hope you have fun! Press esc whenevr you'd like to exit, press tab to access your iventory.\n");

    //Create the player the user will be using
    Player character;
    player_init(&character);

    //testing player display
    //player_display(&character);

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

    printf("You open the top drawer of the dresser and within there lies a note: ''Further down this lodge follwing a cobbled path and west, the dragon awaits you in the cave. Eastwards down the path lies the Goblin and his castle.''\n");
    printf("Next to the note there is a potion, it's familiar scent tells you it heals you. You place it in your pocket.\n");
    //NEED TO ADD POTION TO PLAYERS INVENTORY
    printf("''The choice of whom you face first is yours, you are the only warrior capable of defeating them.''\n");

    //MAP INITIALIZATION USING MALLOC REMEMBER TO FREE MALLOC SPACE AT END OF CODE
    
    //memory allocation first then location initializations
        //base locations
    Location* lodge = malloc(sizeof(Location));
    location_init(lodge, "Lodge\n", "Your humble home, where you may rest to regain HP.\n", 0);
    Location* cPath = malloc(sizeof(Location));
    location_init(cPath, "Cobbled Path\n", "A long winding cobbled path, up the path west is the dragon cave, east is the goblin's castle.\n", 0);
    Location* castleE = malloc(sizeof(Location));
    location_init(castleE, "Goblin Castle Enterance\n", "A gigantic wooden door stands at the enterance of the castle, twoering above you. ''I thought goblins were small'' you think to yourself. \n", 0);
    Location* caveE = malloc(sizeof(Location));
    location_init(caveE, "Cave enterance\n", "The dark cave enterance is an abyss of inky black, you shiver at its sight.\n", 0);
        //inside of goblin castle
    Location* longHall = malloc(sizeof(Location));
    location_init(longHall, "Long hallway past the castle enternace.\n", "In the dim light of the hallway you see menacing figures start towards you, ready for battle.\n", 1);
    Location* barrelRoom = malloc(sizeof(Location));
    location_init(barrelRoom, "Small room packed with winery barrels.\n", "Two goblins perched atop the mound of barrels leap at you, a shiny key hanging from one of their belts.\n", 1);
    Location* stairway = malloc(sizeof(Location));
    location_init(stairway, "Winding Castle Stairway.\n", "You traverse through this long stairway, leading you to the castle's second floor.\n", 0);
    Location* secondFloor = malloc(sizeof(Location));
    location_init(secondFloor, "Castle Second Floor.\n", "In the second floor hallway now you see to your left a glass door with cobwebs surrounding it, and to your right you hear the clanging of metal of a forge through an iron bar door. Far ahead you see a massive metal doorway with two keyholes on either side.\n", 0);
    Location* cobwebRoom = malloc(sizeof(Location));
    location_init(cobwebRoom, "A massive room covered in cobwebs and spiders. \n", "You sense movement all around through the thick webs, an attack is coming.\n", 1);
    Location* forge = malloc(sizeof(Location));
    location_init(forge, "Goblin forge.\n", "The goblins working away on their anvils all stop and stare as you enter, they growl in deep disapproval.\n", 1);
    Location* giantDoor = malloc(sizeof(Location));
    location_init(giantDoor, "The Goblin King's massive door.\n", "The two keyholes glow dimly waiting to be united with their matching keys.\n", 0); 
    Location* goblinBoss = malloc(sizeof(Location));
    location_init(goblinBoss, "The Goblin King's Throne Room\n", "He stands there towering above you, a menacing snarl exits his mouth as he grbas his giant sword, leaping towards you.\n", 1);
    Location* castleT = malloc(sizeof(Location));
    location_init(castleT, "The Goblin's tresure room.\n", "A great assortment of gold and jewels lie before you, but a mystical piece of silver armor calls towards you, you take it.\n", 0);
        //inside of dragon cave
    Location* stalacmite = malloc(sizeof(Location));
    location_init(stalacmite, "Stalacmite cave.\n", "A small but tall cave with massive stalacmites hanging from the ceiling, small dragons hang from them staring at you, ready to pounce. Some of the guard the body of a dead soldier, his skeletal hand gripping onto a long a rope.\n", 1);
    Location* ravine = malloc(sizeof(Location));
    location_init(ravine, "Massive glowing ravine.\n", "Lava flows in multiple parts of this ravine, and fiery dragons drink from the lava, glaring and growling at you between licks.\n", 1); 
    Location* passage = malloc(sizeof(Location));
    location_init(passage, "A small passage.\n", "A small crack in the walls of the ravine leads you through this passage, greta heat emits from the light at the end.\n", 0);
    Location* dragonLair = malloc(sizeof(Location));
    location_init(dragonLair, "The Dragon's Lair.\n", "The massive dragon lies ontop of a pile of gold and jewels, snarling a massive blast of flame exits his mouth as he flies towards you.\n", 1);
    Location* caveT = malloc(sizeof(Location));
    location_init(caveT, "Huge treasure pile.\n", "With the dragon defeated you step into the massive pile of treasure.\n", 0);

    //linking locations
        //castle
    link_loc(lodge, cPath, 'n');
    link_loc(cPath, castleE, 'e');
    link_loc(cPath, caveE, 'w');
    link_loc(castleE, longHall, 'n');
    link_loc(longHall, stairway, 'e');
    link_loc(longHall, barrelRoom, 'w');
    link_loc(stairway, secondFloor, 'n');
    link_loc(secondFloor, forge, 'e');
    link_loc(secondFloor, cobwebRoom, 'w');
    link_loc(secondFloor, giantDoor, 'n');
    link_loc(giantDoor, goblinBoss, 'n');
    link_loc(goblinBoss, castleT, 'n');
    link_loc(castleT, lodge, 'w');
        //cave
    link_loc(caveE, stalacmite, 'n');
    link_loc(stalacmite, ravine, 'w');
    link_loc(ravine, passage, 'n');
    link_loc(passage, dragonLair, 'n');
    link_loc(dragonLair, caveT, 'n');
    link_loc(caveT, lodge, 'e');

    //END OF MAP INITIALIZATION

    ///////////////////////////////////////////////////

    

    //Variable to check what key the user is pressing
    char key_pressed;
    //Varaible to hold user exit
    int game_running = true;
    //Varaible to hold instruction from player
    char whatToDo[20];


    //////////////// ENEMIES/BATTLING AREA

    //array of enemy structs to hold spawned enemies
    Enemy* enemies[10];

    /////////////// END OF ENEMIES/BATTLING AREA

    //////////////////////////////////////////////////

    ///////////////START OF GAME LOOP

    //Integrating Game Loop
    while(game_running){
        printf("What would you like to do? \n");
        printf("Type Options: 'Go', 'Flee', 'Describe' | Press Tab to open your inventory | Press esc to exit the game ");
        scanf("%s", &whatToDo);
        //Check what user wants to do based on input
        //If user wants to move:
        if(strcmp(whatToDo, "go") == 0 || strcmp(whatToDo, "Go") || strcmp(whatToDo, "GO")){
            char go;
            printf("Where would you like to go? (Valid inputs: n, s, e, w, x (to stay))\n");
            //print a map of the players current location
            if(character.loc->north){
                printf("%s\n", character.loc->north->name);
            }else{
                printf("X\n");
            }
            printf("|\n");
            printf("|\n");
            if(character.loc->west){
                printf("%s", character.loc->west->name);
            }else{
                printf("X");
            }
            printf("----");
            printf("%s", character.loc->name);
            printf("-----");
            if(character.loc->east){
                printf("%s", character.loc->east->name);
            }else{
                printf("X");
            }
            printf("|\n");
            printf("|\n");
            if(character.loc->south){
                printf("%s\n", character.loc->south->name);
            }else{
                printf("X\n");
            }

            //gather user input and try to move
            scanf(" %c", &go);
            if(go == 'x'){
                break;
            }else{
                move_player(&character, go);
            }
        }

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
