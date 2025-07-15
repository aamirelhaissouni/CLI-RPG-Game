#include "player.h"
#include "enemies.h"
#include "locations.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void location_init(Location* location, char name, int enemyType, int forgiveness){
    strcpy(location->name, name);
    location->enemyType = enemyType;
    location->forgiveness = forgiveness;
};