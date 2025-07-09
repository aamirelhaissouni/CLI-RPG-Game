//Player struct, Holds: Name, HP, Power, Magic Power, Armor, Inventory and Level
typedef struct Player Player;
struct Player{
    char name[12];
    int Class;
    int HP;
    int Power;
    int Magic;
    int Level;
    int Armor;
    char inventory[5][15];
    char Location[30];
};

// Set up player function
void player_init(Player* player);

//Display player stats/inventory:
void player_display(Player* player);