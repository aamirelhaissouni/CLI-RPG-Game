#include "player.h"
#include "enemies.h"
#include "locations.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>



void location_init(Location* location, const char* name, const char* description, int battle, Location* loc1, Location* loc2){
    strcpy(location->name, name);
    strcpy(location->description, description);
    location->completed = 0;
    location->battle = battle;
    location->backward = loc1;
    location->forward = loc2;
};

int main (void){
    //Location array to hold all locations
    Location locs[10];

    //Initialize locations ////////////////////////////////////////////////////////////////////////////////////
    Location lodge;
    //cave
    Location caveE;
    Location cave1;
    Location cave2;
    Location caveB;
    Location CaveT;
    //castle
    Location castleE;
    Location castle1;
    Location castle2;
    Location castle3;
    Location castle4;
    Location castleB;
    Location castleT;
    //inits:
        //lodge
    location_init(&lodge, "Lodge", "Your home where you can rest and regain HP", 0, &castleE, &caveE);
        //cave

        //castle
    location_init(&castleE, "Castle Enternace", "A massive wooden door with stone walling all around it.", 0, &lodge, &castle1);
    location_init(&castle1, "Castle 1st Floor", "A long red rug lays until a staircase dimly lit with torches, menacing figures stand on the stairs.\n", 1, &castleE, &castle2);
    location_init(&castle2, "Castle 2nd floor", "Up the stairs now, an iron barred door lies to your right, a long hallway to lies to your right, with more monster making headfast towards you.\n"
    , 1, &castle1, &castle3);
    location_init(&castle)
    

    
    //end of initialization ////////////////////////////////////////////////////////////////////////////////////////////////
};