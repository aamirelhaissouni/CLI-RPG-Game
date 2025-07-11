/*
File to store weapon and armor structs and functions
*/

#define KARMOR 0.75
#define NARMOR 1.0

// Struct to define the type of weapons in the game
// Has name, type (magic or physical), durability, and base damage
struct Weapon{
    char name[12];
    int type;
    float durbaility;
    int damage;
};