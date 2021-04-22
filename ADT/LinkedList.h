#include "List.h"

typedef struct LinkedList {
    list_node *next;
    int len;
} LinkedList;

LinkedList *LinkedList_new();

void LinkedList_add(LinkedList *list, void *value);

void *LinkedList_get(LinkedList *list, int index);

void *LinkedList_foreach(LinkedList *list, void (*fn)(LinkedList *list, void *val));