//File to store locations and movement functions

#define BASE "Home Base"

typedef struct {
    //location name
    char name[20];
    // enemy type (0 for goblins, 1 for ghouls)
    int enemyType;
    // forgiveness value, the higher the less likely a boss will spawn as you traverse
    int forgiveness;
} Location;

void location_init(Location* location, char name, int enemyType, int forgiveness);