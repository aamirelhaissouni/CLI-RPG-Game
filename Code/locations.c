// file with all functions to

#include "locations.h"
// #include "enemies.h"
#include "player.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// basic location initialization without linking other locations
void location_init(Location *location, const char *name,
                   const char *description, bool battle, bool completion,
                   int num) {
  location->name = name;
  location->description = description;
  location->battle = battle;
  location->completed = completion;
  location->location_num = num;
};

// used to link location structs and create a map using 4 direction parameters
// n,s,e,w
void link_loc(Location *a, Location *b, char dir) {
  switch (dir) {
  case 'n':
    a->north = b;
    b->south = a;
    break;
  case 's':
    a->south = b;
    b->north = a;
    break;
  case 'e':
    a->east = b;
    b->west = a;
    break;
  case 'w':
    a->west = b;
    b->east = a;
    break;
  }
};

// function to change players location based on their input
void move_player(World *world, Player *player, char dir) {
  // first check if the player is allowed to leave the area based on player bool
  // value if true then move base don char entered
  if (player->loc->completed == true) {
    switch (dir) {
    case 'n':
      if (player->loc->north) {
        player->loc = world->locations[player->loc->north->location_num];
      } else {
        printf(" \n");
        printf("You can't go north\n");
      }
      break;
    case 's':
      if (player->loc->south) {
        player->loc = world->locations[player->loc->south->location_num];
      } else {
        printf(" \n");
        printf("You can't go south\n");
      }
      break;
    case 'w':
      if (player->loc->west) {
        player->loc = world->locations[player->loc->west->location_num];
      } else {
        printf(" \n");
        printf("You can't go west\n");
      }
      break;
    case 'e':
      if (player->loc->east) {
        player->loc = world->locations[player->loc->east->location_num];
      } else {
        printf(" \n");
        printf("You can't go east\n");
      }
      break;
    default:
      printf(" \n");
      printf("Unknown direction\n");
    }
  } else {
    printf(" \n");
    printf("You haven't completed this area yet, you may not leave. \n");
    printf(" \n");
  }
};

World *world_init(void) {
  bool battle = true;
  bool complete = true;

  // malloc world struct that will hold everthing
  World *world = malloc(sizeof(World));
  
  //testing 1
  printf("Beginning world initialization\n");


  // set lcoation count to 0 (most important for end_world for loop)
  world->num_locations = 0;

  // begin world initialization

  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations], "Lodge",
                "Your humble home where you may rest to regain HP.\n", !battle,
                complete, LOC_LODGE);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations], "Cobbled Path\n",
                "A long winding cobbled path, up the path west is the dragon \n"
                "cave, east is the goblin's castle.\n",
                !battle, complete, LOC_COBBLEDP);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(
      world->locations[world->num_locations], "Goblin Castle Enterance\n",
      "A gigantic wooden door stands at the enterance of the castle, towering "
      "above you. ''I thought goblins were small'' you think to yourself. \n",
      !battle, complete, LOC_CASTLE_ENTERANCE);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations], "Cave enterance\n",
                "The dark cave enterance is an abyss of inky black, you shiver "
                "at its sight.\n",
                !battle, complete, LOC_CAVE_ENTERANCE);
  world->num_locations++;
  // End of Main Four
  // Start of Castle
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations],
                "Long hallway past the castle enternace.\n",
                "In the dim light of the hallway you see menacing figures "
                "start towards you, ready for battle.\n",
                battle, !complete, LOC_LONG_HALL);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations],
                "Small room packed with winery barrels.\n",
                "Two goblins perched atop the mound of barrels leap at you, a "
                "shiny key hanging from one of their belts.\n",
                battle, !complete, LOC_BARREL_ROOM);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations],
                "Winding Castle Stairway.\n",
                "You traverse through this long stairway, leading you to the "
                "castle's second floor.\n",
                !battle, complete, LOC_STAIRWAY);
  world->num_locations++;
  //
  world->locations[world->num_locations] =
      world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(
      world->locations[world->num_locations], "Castle Second Floor.\n",
      "In the second floor hallway now you see to your left a glass door with "
      "cobwebs surrounding it, and to your right you hear the clanging of "
      "metal of a forge through an iron bar door. Far ahead you see a massive "
      "metal doorway with two keyholes on either side.\n",
      !battle, complete, LOC_SECOND_FLOOR);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations],
                "A massive room covered in cobwebs and spiders. \n",
                "You sense movement all around through the thick webs, an "
                "attack is coming.\n",
                battle, !complete, LOC_COBWEB_ROOM);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations], "Goblin forge.\n",
                "The goblins working away on their anvils all stop and stare "
                "as you enter, they growl in deep disapproval.\n",
                battle, !complete, LOC_FORGE);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations],
                "The Goblin King's massive door.\n",
                "The two keyholes glow dimly waiting to be united with their "
                "matching keys.\n",
                !battle, !complete, LOC_GIANT_DOOR);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations],
                "The Goblin King's Throne Room\n",
                "He stands there towering above you, a menacing snarl exits "
                "his mouth as he grabs his giant sword, leaping towards you.\n",
                battle, !complete, LOC_GOBLIN_BOSS);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(
      world->locations[world->num_locations], "The Goblin's tresure room.\n",
      "A great assortment of gold and jewels lie before you, but a mystical "
      "piece of silver armor calls towards you, you take it.\n",
      !battle, !complete, LOC_GOBLIN_TREASURE);
  world->num_locations++;
  // End of Castle
  // Start of Cave
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations], "Stalacmite cave.\n",
                "A small but tall cave with massive stalacmites hanging from "
                "the ceiling, small dragons hang from them staring at you, "
                "ready to pounce. Some of them guard the body of a dead "
                "soldier, his skeletal hand gripping onto a long a rope.\n",
                battle, !complete, LOC_STALACMITE);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(
      world->locations[world->num_locations], "Massive glowing ravine.\n",
      "Lava flows in multiple parts of this ravine, and fiery dragons drink "
      "from the lava, glaring and growling at you between licks.\n",
      battle, !complete, LOC_RAVINE);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations], "A small passage.\n",
                "A small crack in the walls of the ravine leads you through "
                "this passage, great heat emits from the light at the end.\n",
                !battle, complete, LOC_PASSAGE);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(
      world->locations[world->num_locations], "The Dragon's Lair.\n",
      "The massive dragon lies ontop of a pile of gold and jewels, snarling a "
      "massive blast of flame exits his mouth as he flies towards you.\n",
      battle, !complete, LOC_DRAGON_LAIR);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(
      world->locations[world->num_locations], "Huge treasure pile.\n",
      "With the dragon defeated you step into the massive pile of treasure.\n",
      !battle, complete, LOC_CAVE_TREASURE);
  world->num_locations++;


  // linking locations in the world
  // main four
  link_loc(world->locations[LOC_LODGE], world->locations[LOC_COBBLEDP], 'n');
  link_loc(world->locations[LOC_COBBLEDP],
           world->locations[LOC_CASTLE_ENTERANCE], 'e');
  link_loc(world->locations[LOC_COBBLEDP], world->locations[LOC_CAVE_ENTERANCE],
           'w');
  // Castle
  link_loc(world->locations[LOC_CASTLE_ENTERANCE],
           world->locations[LOC_LONG_HALL], 'n');
  link_loc(world->locations[LOC_LONG_HALL], world->locations[LOC_STAIRWAY],
           'e');
  link_loc(world->locations[LOC_LONG_HALL], world->locations[LOC_BARREL_ROOM],
           'w');
  link_loc(world->locations[LOC_STAIRWAY], world->locations[LOC_SECOND_FLOOR],
           'n');
  link_loc(world->locations[LOC_SECOND_FLOOR], world->locations[LOC_FORGE],
           'e');
  link_loc(world->locations[LOC_SECOND_FLOOR],
           world->locations[LOC_COBWEB_ROOM], 'w');
  link_loc(world->locations[LOC_SECOND_FLOOR], world->locations[LOC_GIANT_DOOR],
           'n');
  link_loc(world->locations[LOC_GIANT_DOOR], world->locations[LOC_GOBLIN_BOSS],
           'n');
  link_loc(world->locations[LOC_GOBLIN_BOSS],
           world->locations[LOC_GOBLIN_TREASURE], 'n');
  // gotta wait until player defeats the boss here to link this:
  // link_loc(castleT, lodge, 'w');

  // cave linking
  link_loc(world->locations[LOC_CAVE_ENTERANCE], world->locations[LOC_STALACMITE], 'n');
  printf("CAVE->SATALCMITE North");
  link_loc(world->locations[LOC_STALACMITE], world->locations[LOC_RAVINE], 'w');
  printf("STALACMITE->RAVINE West");
  link_loc(world->locations[LOC_RAVINE], world->locations[LOC_PASSAGE], 'n');
  printf("ravine->passage north");
  link_loc(world->locations[LOC_PASSAGE], world->locations[LOC_DRAGON_LAIR],'n');
  printf("passage->dragonlair north");
  link_loc(world->locations[LOC_DRAGON_LAIR], world->locations[LOC_CAVE_TREASURE], 'n');

  // gotta wait until player defeats the boss here to link this:
  // link_loc(caveT,lodge, 'e');

  // End of world init function
  printf("World initialized successfully! \n");
  return world;
}


void end_world(World *world){
    if (!world) return;
    for(int i = 0; i<world->num_locations; i++){
        free(world->locations[i]);
    }
}














