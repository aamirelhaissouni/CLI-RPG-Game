//File to store locations and movement functions



//Location struct
typedef struct Location{
    const char *name;
    const char *description;
    int completed;
    int battle;
    Location *north, *south, *east, *west;
} Location;

typedef struct {
    char name[20];
    char description[50];
    Location forward;
    Location back;
}Passage;

//location initializer
void location_init(Location* location, const char* name, const char* description, int battle);

//link locations function only bidirectional, have to do north and south at once, and east and west at once
void link_loc(Location* location, char dir);

//fucntion to allow player ot move to different locations
void move(Player* player, char dir);