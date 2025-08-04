// File to store locations and movement functions
#ifndef LOCATIONS_H
#define LOCATIONS_H

#include <stdbool.h>
// forward declaration of player struct
typedef struct Player Player;

// Location struct
typedef struct Location Location;
struct Location {
  const char *name;
  const char *description;
  bool completed;
  bool battle;
  struct Location *north, *south, *east, *west;
};

// location initializer
void location_init(Location *location, const char *name,
                   const char *description, bool battle, bool completion);

// link locations function only bidirectional, have to do north and south at
// once, and east and west at once
void link_loc(Location *a, Location *b, char dir);

// function to allow player ot move to different locations
void move_player(Player *player, char dir);

typedef struct {
  int num_locations;
  Location *locations[20];
  Location *player_start; // don't know if I need this yet
} World;

World *world_init(void);

void end_world(World *world);

// main 4
#define LOC_LODGE 1
#define LOC_COBBLEDP 2
#define LOC_CASTLE_ENTERANCE 3
#define LOC_CAVE_ENTERANCE 4

// inside castle
#define LOC_LONG_HALL 5
#define LOC_BARREL_ROOM 6
#define LOC_STAIRWAY 7
#define LOC_SECOND_FLOOR 8
#define LOC_COBWEB_ROOM 9
#define LOC_FORGE 10 // need to fix from here on out all the numbers
#define LOC_GIANT_DOOR 11
#define LOC_GOBLIN_BOSS 12
#define LOC_GOBLIN_TREASURE 13

// inside cave
#define LOC_STALACMITE 14
#define LOC_RAVINE 15
#define PASSAGE 16
#define DRAGON_LAIR 17
#define CAVE_TREASURE 18

#endif
