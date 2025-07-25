//file with all functions to 


#include "player.h"
#include "enemies.h"
#include "locations.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


//basic location initialization without linking other locations
void location_init(Location* location, const char* name, const char* description, int battle, int completion){
    location->name = name;
    location->description = description;
    location->completed = 0;
    location->battle = battle;
    location->completed = completion;
};

//used to link location structs and create a map using 4 direction parameters n,s,e,w
void link_loc(Location *a, Location *b, char dir){
    switch(dir){
        case 'n': a->north = b; b->south = a; break;
        case 's': a->south = b; b->north = a; break;
        case 'e': a->east = b; b->west = a; break;
        case 'w': a->west =b; b->east = a; break;
    }
};

//function to change players location based on their input
void move_player(Player* player, char dir){
    //first check if the player is allowed to leave the area based on player loc int value
    if(player->loc->completed == 1){
        switch(dir){
            case 'n': 
                if(player->loc->north){
                    player->loc = player->loc->north;
                }else{
                    printf(" \n");
                    printf("You can't go north\n");
                }
                break;
            case 's':
                if(player->loc->south){
                    player->loc = player->loc->south;
                }else{
                    printf(" \n");
                    printf("You can't go south\n");
                }
                break;
            case 'w':
                if(player->loc->west){
                    player->loc = player->loc->west;
                }else{
                    printf(" \n");
                    printf("You can't go west\n");
                }
                break;
            case 'e':
                if(player->loc->east){
                    player->loc = player->loc->east;
                }else{
                    printf(" \n");
                    printf("You can't go east\n");
                }
                break;
            default:
                printf(" \n");
                printf("Unknown direction\n");
        }
    }else{
        printf(" \n");
        printf("You haven't completed this area yet, you may not leave. \n");
        printf(" \n");
    }
};

