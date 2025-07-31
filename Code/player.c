#include "player.h"
#include "enemies.h"
#include "locations.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Set up player function
void player_init(Player* player){
    //Set player status 0, for no battle, 1 for battle
    player->status = 0;
    //Choosing name
    char n[MAX];
    printf("Please enter your characters name (max 12 characters): \n");
    //scanf that reads up to 11 characters with null terminator
    scanf("%11s", n);
    //use strcpy to appply string to player name becasue you can't directly 
    //assign an array to an array in C
    strcpy(player->name, n);

    //Choosing class
    char c;
    do {
        printf("Enter your desired class, press K for Knight, N for Necromancer. ");
        scanf(" %c", &c);  // Space before %c skips whitespace/newlines
        printf(" \n");
    } while (c != 'k' && c != 'n' && c != 'K' && c != 'N');
    /*testing while loop
    printf("%c", c); */
    player->class = c;

    //Setting player hp based on class:
    if(player->class == 'k'){
        player->hp = 100;
    }else{
        player->hp = 75;
    }

    //Setting player power based on class
    if(player->class == 'k'){
        player->power = UP;
    }else{
        player->power = LOW;
    }

    //Setting player magic/magic power based on class
    if (player->class == 'n'){
        player->magic = UP;
    }else{
        player->magic = LOW;
    }

    //Setting player level
    player->level = 1;

    //Setting player armor based on class
    if (player->class == 'k'){
        player->armor = KARMOR;
    }else{
        player->armor = NARMOR;
    };

    //Setting player inventory
    strcpy(player->inventory[0], BOOK);
    for(int i = 1; i<6; i++){
        strcpy(player->inventory[i], "Empty");
    };
    printf(" \n");
    printf("Character creation complete! Welcome %s!\n", player->name);

    //End of player_init all further modifications through general gameplay
};

//Display player stats/inventory:
void player_display(Player* player){
//Printing player stauses and current inventory
printf("+---------+--------------------+\n");
printf("| Player: %s | Inventory:         |\n", player->name);
printf("+---------+--------------------+\n");
printf("| Level: %d     | * %s          \n", player->level, player->inventory[0]);
printf("| Class: %c     | * %s          \n", player->class, player->inventory[1]);
printf("| Health: %d   | * %s          \n", player->hp, player->inventory[2]);
printf("| Power: %.2lf  | * %s       \n", player->power, player->inventory[3]);
printf("| Magic: %.2lf  | * %s       \n", player->magic, player->inventory[4]);
printf("| Armor: %.2lf  | * %s       \n", player->armor, player->inventory[5]);
printf("+------------+--------------+\n");

//End of player_display function
}; 

