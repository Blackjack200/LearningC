#include <stdio.h>
#include <stdlib.h>
#include "ADT/LinkedList.h"
#include "ADT/LinkedMap.h"
typedef const char string[];


void fn(LinkedList *_, void *val) {
    string *e = val;
    printf("%s\n", *e);
}

int main(void) {
    char *test = "Hello My ADT LinkedList";
    char *test2 = "Hello World!!!";
    LinkedList *list = LinkedList_new();
    LinkedList_add(list, test);
    LinkedList_add(list, test2);
    LinkedList_remove(list, 1);
    LinkedList_foreach(list, fn);
    Map *map = LinkedMap_new();
    LinkedMap_insert(map, test, test2);
    printf("E: %s\n", (char *) LinkedMap_get(map, test));
    LinkedMap_remove(map, test);
    LinkedMap_insert(map, test, test);
    printf("E: %s\n", (char *) LinkedMap_get(map, test));
    LinkedMap_insert(map, test, test2);
    LinkedMap_remove(map, test);
    free(map);
    return 0;
}