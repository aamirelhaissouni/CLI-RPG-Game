//script to test enemy stuff
#include "enemies.h"
#include <stdio.h>


int main(void){
    Enemy *enemies[10];
    printf("I'm a retard");
    int num = 4;
    enemy_gen(num, GOBLIN, *enemies[10]);
    printf("Enemies generated!");
    degen_enemies(*enemies[10]);
    printf("Enemies destroyed!");
    return 0;
}