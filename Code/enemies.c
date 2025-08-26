//enemies.c file to make and degen enemies

// In here I will make use of dynamic memory allocation to store enemies
// This is so when enemies are defeated, they dissapear and do not take up memory in the heap

#include "player.h"
#include "enemies.h"
#include "locations.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


Enemy *enemy_init(const char name[12], int hp, int damage){
    Enemy *enemy = malloc(sizeof(*enemy));
    if (enemy == NULL){
        printf("Enemy malloc failed. \n");
    }

    enemy->damage = damage;
    enemy->hp = hp;
    strcpy(enemy->name, name);
    return enemy;
}

void enemy_gen(int num_enemies, const char enemy_type, Enemy *enemies[]){
    char *enemy_name;
    int enemy_hp;
    int enemy_damage;
    if(enemy_type == GOBLIN){
        enemy_name = "Goblin";
        enemy_hp = 100;
        enemy_damage = 20;
    }else if(enemy_type == DRAGON){
        enemy_name = "Dragon";
        enemy_hp = 120;
        enemy_damage = 15;
    }else if(enemy_type == DRAGON_BOSS){
        enemy_name = "D_Boss";
        enemy_hp = 300;
        enemy_damage = 30;
    }else if(enemy_type == GOBLIN_BOSS){
        enemy_name = "G_Boss";
        enemy_hp = 300;
        enemy_damage = 30;
    }else{
        printf("Error: Improper enemy type char.");
    }

    for(int i = 0; i<num_enemies; i++){
        Enemy *enemy = enemy_init(enemy_name, enemy_hp, enemy_damage);
        enemies[i] = enemy;
    } 
}


void degen_enemies(Enemy *enemies[]){
    size_t array_length = sizeof(enemies) / sizeof(enemies[0]);
    for(int i = 0; i<array_length; i++){
        free(enemies[i]);
    }
}

void battle(Enemy *enemies[]){
    //should have a while loop that keeps in you battle
    //based on the player status
    
    //while(player->status>0){
        //battle stuff
    //}   
    //
    // battle stuff:
    // gives players three options: attack, use item in inventory, or flee
    // 
    printf("You are in a battle fella");

}




