//Enemies header file

// In here I will make use of dynamic memory allocation to store enemies
// This is so when enemies are defeated, they dissapear and do not take up memory in the heap



typedef struct{
    char* name[12];
    int* hp;
    int* damage;
} Enemy;

void gen_enemy(const char* name, int hp, int damage, int numE);

void degen_enemies(Enemy* enemies[]);

void battle(Enemy* enemies);


