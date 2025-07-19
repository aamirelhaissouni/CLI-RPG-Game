//File to store locations and movement functions



//Location struct
typedef struct Location{
    char name[50];
    char description[250];
    int completed;
    int battle;
    Location *forward;
    Location *backward;
} Location;

typedef struct {
    char name[20];
    char description[50];
    Location forward;
    Location back;
}Passage;

//location initializer
void location_init(Location* location, const char* name, const char* description, int battle, Location* loc1, Location* loc2);

//passage initializer
void passage_init(Passage* Passage, const char* name, const char* description, Location* Loc1, Location* Loc2);