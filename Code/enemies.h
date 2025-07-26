//Enemies header file

// In here I will make use of dynamic memory allocation to store enemies
// This is so when enemies are defeated, they dissapear and do not take up memory in the heap

#ifndef ENEMIES_H
#define ENEMIES_H

typedef struct Enemy Enemy;

struct Enemy{
    char* name[12];
    int* hp;
    int* damage;
};

void gen_enemy(const char* name, int hp, int damage, int numE);

void degen_enemies(Enemy* enemies[]);

void battle(Enemy* enemies);

#endif
