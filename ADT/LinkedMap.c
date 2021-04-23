#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedMap.h"

MapEntry *map_entry_new() {
    MapEntry *ret = malloc(sizeof(MapEntry));
    ret->key = NULL;
    ret->value = NULL;
    return ret;
}

Map *LinkedMap_new() {
    Map *map = malloc(sizeof(Map));
    map->ls = LinkedList_new();
    return map;
}

void LinkedMap_insert(Map *map, void *key, void *value) {
    LinkedMap_remove(map, key);
    MapEntry *entry = map_entry_new();
    entry->key = key;
    entry->value = value;
    LinkedList_add(map->ls, entry);
}

void LinkedMap_remove(Map *map, void *key) {
    int i = 0;
    list_node *node = map->ls->next;
    while (i++ < map->ls->len) {
        MapEntry *entry = node->value;
        if (entry->key == key) {
            node->next = NULL;
            node->value = NULL;
            map->ls->len--;
            return;
        }
        node = node->next;
    }
}

void *LinkedMap_get(Map *map, void *key) {
    int i = 0;
    list_node *node = map->ls->next;
    while (i++ < map->ls->len) {
        MapEntry *entry = node->value;
        if (entry->key == key) {
            return entry->value;
        }
        node = node->next;
    }
    return NULL;
}