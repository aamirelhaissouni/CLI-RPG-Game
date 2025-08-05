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
                   const char *description, bool battle, bool completion) {
  location->name = name;
  location->description = description;
  location->battle = battle;
  location->completed = completion;
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
void move_player(Player *player, char dir) {
  // first check if the player is allowed to leave the area based on player loc
  // int value
  if (player->loc->completed == 1) {
    switch (dir) {
    case 'n':
      if (player->loc->north) {
        player->loc = player->loc->north;
      } else {
        printf(" \n");
        printf("You can't go north\n");
      }
      break;
    case 's':
      if (player->loc->south) {
        player->loc = player->loc->south;
      } else {
        printf(" \n");
        printf("You can't go south\n");
      }
      break;
    case 'w':
      if (player->loc->west) {
        player->loc = player->loc->west;
      } else {
        printf(" \n");
        printf("You can't go west\n");
      }
      break;
    case 'e':
      if (player->loc->east) {
        player->loc = player->loc->east;
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

  // set lcoation count to 0 (most important for end_world for loop)
  world->num_locations = 0;

  // begin world initialization
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations], "Lodge",
                "Your humble home where you may rest to regain HP.\n", !battle,
                complete);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations], "Cobbled Path\n",
                "A long winding cobbled path, up the path west is the dragon \n"
                "cave, east is the goblin's castle.\n",
                !battle, complete);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(
      world->locations[world->num_locations], "Goblin Castle Enterance\n",
      "A gigantic wooden door stands at the enterance of the castle, towering "
      "above you. ''I thought goblins were small'' you think to yourself. \n",
      !battle, complete);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations], "Cave enterance\n",
                "The dark cave enterance is an abyss of inky black, you shiver "
                "at its sight.\n",
                !battle, complete);
  // End of Main Four
  // Start of Castle
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations],
                "Long hallway past the castle enternace.\n",
                "In the dim light of the hallway you see menacing figures "
                "start towards you, ready for battle.\n",
                battle, !complete);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations],
                "Small room packed with winery barrels.\n",
                "Two goblins perched atop the mound of barrels leap at you, a "
                "shiny key hanging from one of their belts.\n",
                battle, !complete);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations],
                "Winding Castle Stairway.\n",
                "You traverse through this long stairway, leading you to the "
                "castle's second floor.\n",
                !battle, complete);
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
      !battle, complete);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations],
                "A massive room covered in cobwebs and spiders. \n",
                "You sense movement all around through the thick webs, an "
                "attack is coming.\n",
                battle, !complete);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations], "Goblin forge.\n",
                "The goblins working away on their anvils all stop and stare "
                "as you enter, they growl in deep disapproval.\n",
                battle, !complete);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations],
                "The Goblin King's massive door.\n",
                "The two keyholes glow dimly waiting to be united with their "
                "matching keys.\n",
                !battle, !complete);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(world->locations[world->num_locations],
                "The Goblin King's Throne Room\n",
                "He stands there towering above you, a menacing snarl exits "
                "his mouth as he grabs his giant sword, leaping towards you.\n",
                battle, !complete);
  world->num_locations++;
  //
  world->locations[world->num_locations] = malloc(sizeof(Location));
  location_init(
      world->locations[world->num_locations], "The Goblin's tresure room.\n",
      "A great assortment of gold and jewels lie before you, but a mystical "
      "piece of silver armor calls towards you, you take it.\n",
      !battle, !complete);
  world->num_locations++;
  // End of Castle
  // Start of Cave
  Location *stalacmite = malloc(sizeof(Location));
  location_init(stalacmite, "Stalacmite cave.\n",
                "A small but tall cave with massive stalacmites hanging from "
                "the ceiling, small dragons hang from them staring at you, "
                "ready to pounce. Some of them guard the body of a dead "
                "soldier, his skeletal hand gripping onto a long a rope.\n",
                battle, !complete);
  Location *ravine = malloc(sizeof(Location));
  location_init(
      ravine, "Massive glowing ravine.\n",
      "Lava flows in multiple parts of this ravine, and fiery dragons drink "
      "from the lava, glaring and growling at you between licks.\n",
      battle, !complete);
  Location *passage = malloc(sizeof(Location));
  location_init(passage, "A small passage.\n",
                "A small crack in the walls of the ravine leads you through "
                "this passage, great heat emits from the light at the end.\n",
                !battle, complete);
  Location *dragonLair = malloc(sizeof(Location));
  location_init(
      dragonLair, "The Dragon's Lair.\n",
      "The massive dragon lies ontop of a pile of gold and jewels, snarling a "
      "massive blast of flame exits his mouth as he flies towards you.\n",
      battle, !complete);
  Location *caveT = malloc(sizeof(Location));
  location_init(
      caveT, "Huge treasure pile.\n",
      "With the dragon defeated you step into the massive pile of treasure.\n",
      !battle, complete);

  return world;
};
