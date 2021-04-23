
struct Map__ {
    LinkedList *ls;
} Map__;

struct MapEntry__ {
    void *key;
    void *value;
} MapEntry___;
typedef struct Map__ Map;
typedef struct MapEntry__ MapEntry;

Map *LinkedMap_new();

void LinkedMap_remove(Map *map, void *key);

void LinkedMap_insert(Map *map, void *key, void *value);

void *LinkedMap_get(Map *map, void *key);