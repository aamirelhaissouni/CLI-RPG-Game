// Enemies header file

// In here I will make use of dynamic memory allocation to store enemies
// This is so when enemies are defeated, they dissapear and do not take up
// memory in the heap

#ifndef ENEMIES_H
#define ENEMIES_H

#define GOBLIN 'g'
#define DRAGON 'd'
#define GOBLIN_BOSS 'x'
#define DRAGON_BOSS 'y'

#pragma once


typedef struct Enemy Enemy;

struct Enemy {
  const char name[12];
  int hp;
  int damage;
};

//enemy initializer 
Enemy *enemy_init(const char name[12], int hp, int damage); 

void enemy_gen(int num_enemies, const char enemy_type, Enemy *enemies[]);

//removes and frees memory of enemies in enemy array
void degen_enemies(Enemy *enemies[]);

//starts battle with current enemies in the enemy array
void battle(Enemy *enemies[]);

#endif
