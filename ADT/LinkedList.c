#include "LinkedList.h"
#include <stdlib.h>
#include <strings.h>

list_node *list_node_new() {
    list_node *node = malloc(sizeof(list_node));
    node->next = NULL;
    node->value = NULL;

    return node;
}

LinkedList *LinkedList_new() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->len = 0;
    list->next = list_node_new();
    return list;
}

void LinkedList_add(LinkedList *list, void *value) {
    list_node *node = list->next;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = list_node_new();
    node->value = value;
    list->len++;
}


void *LinkedList_get(LinkedList *list, int index) {
    int i = 0;
    list_node *node = list->next;
    while (i++ < index) {
        node = node->next;
    }
    return node->value;
}

void LinkedList_remove(LinkedList *list, int index) {
    int i = 0;
    index -= 1;
    list_node *node = list->next;
    while (i++ < index) {
        node = node->next;
    }
    node->next = NULL;
    list->len--;
}

void LinkedList_foreach(LinkedList *list, void (*fn)(LinkedList *list, void *val)) {
    int i = 0;
    list_node *node = list->next;
    while (i++ < list->len) {
        fn(list, node->value);
        node = node->next;
    }
}