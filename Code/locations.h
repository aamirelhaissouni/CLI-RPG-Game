//File to store locations and movement functions
#ifndef LOCATIONS_H
#define LOCATIONS_H

#include <stdbool.h>
//forward declaration of player struct
typedef struct Player Player;


//Location struct
typedef struct Location Location;
struct Location{
    const char *name;
    const char *description;
    bool completed;
    bool battle;
    struct Location *north, *south, *east, *west;
};


//location initializer
void location_init(Location* location, const char* name, const char* description, bool battle, bool completion);

//link locations function only bidirectional, have to do north and south at once, and east and west at once
void link_loc(Location* a, Location* b, char dir);

//function to allow player ot move to different locations
void move_player(Player* player, char dir);

#endif 