#include <stdio.h>
#include "ADT/LinkedList.h"

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
    return 0;
}