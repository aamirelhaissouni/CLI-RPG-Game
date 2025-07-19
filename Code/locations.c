#include "player.h"
#include "enemies.h"
#include "locations.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>



void location_init(Location* location, const char* name, const char* description, int battle){
    strcpy(location->name, name);
    strcpy(location->description, description);
    location->completed = 0;
    location->battle = battle;
};

void link_loc(Location *a, Location *b, char dir){
    switch(dir){
        case 'n': a->north = b; b->south = a; break;
        case 's': a->south = b; b->north = a; break;
        case 'e': a->east = b; b->west = a; break;
        case 'w': a->west =b; b->east = a; break;
    }
};

void move(Player* player, char dir){
    switch(dir){
        case 'n': 
        if(player->loc->north){
            player->loc = player->loc->north;
        }else{
            printf("You can't go north\n");
        };
        case 's':
        if(player->loc->south){
            player->loc = player->loc->south;
        }else{
            printf("You can't go south\n");
        }
        
    }
};