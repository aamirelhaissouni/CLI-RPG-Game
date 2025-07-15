//Enemies header file

// In here I will make use of dynamic memory allocation to store enemies
// This is so when enemies are defeated, they dissapear and do not take up memory in the heap
#define MAX_ENEMIES 10

Enemy* enemies[MAX_ENEMIES];
int enemyNum = 0;

typedef struct{
    char* name[12];
    int* hp;
    int* damage;
} Enemy;


