//enemies.c file to make and degen enemies

// In here I will make use of dynamic memory allocation to store enemies
// This is so when enemies are defeated, they dissapear and do not take up memory in the heap

#include "player.h"
#include "enemies.h"
#include "locations.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


Enemy *enemy_init(const char *name, int hp, int damage){
    Enemy *enemy = malloc(sizeof(Enemy));
    if (enemy == NULL){
        printf("Enemy malloc failed. \n");
    }

    //assign values ot enemy here
    enemy->damage = damage;
    enemy->hp = hp;
    enemy->name = name;
}

void enemy_gen(int num_enemies, const char enemy_type){
    
}


void degen_enemies(Enemy *enemies[]){
    //i should kill myself
}

void battle(Enemy *enemies[]){
    //im so gay
}




