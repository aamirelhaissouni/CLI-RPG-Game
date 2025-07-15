//Player struct, Holds: Name, HP, Power, Magic Power, Armor, 
// Inventory, and Location 

#define MAX 12
#define LOW 1
#define UP 1.5
#define BOOK "Guide Book"
#define KARMOR 0.75
#define NARMOR 1.0



typedef struct Player Player;
struct Player{
    char name[MAX];
    char class;
    int hp;
    float power;
    float magic;
    int level;
    float armor;
    char inventory[6][15];
    int status;
};


// Set up player function
void player_init(Player* player);

//Display player stats/inventory:
void player_display(Player* player);