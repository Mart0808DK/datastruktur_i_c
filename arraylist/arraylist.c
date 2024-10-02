#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

#define INITIAL_CAPACITY 10

static void resize_if_needed(ArrayList *list) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = realloc(list->data, list->capacity * sizeof(void *));
    } else if (list->size < list->capacity / 2 && list->capacity > INITIAL_CAPACITY) {
        list->capacity /= 2;
        list->data = realloc(list->data, list->capacity * sizeof(void *));
    }
}

ArrayList* alst_arraylist() {
    ArrayList *list = malloc(sizeof(ArrayList));
    list->data = malloc(INITIAL_CAPACITY * sizeof(void *));
    list->capacity = INITIAL_CAPACITY;
    list->size = 0;
    return list;
}

void alst_add(ArrayList *list, void *element) {
    resize_if_needed(list);
    list->data[list->size++] = element;
}

void* alst_get(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return list->data[index];
}

int alst_size(ArrayList *list) {
    return list->size;
}

void alst_remove(ArrayList *list) {
    if (list->size > 0) {
        list->size--;
        resize_if_needed(list);
    }
}

void alst_removeIndex(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    memmove(&list->data[index], &list->data[index + 1], (list->size - index - 1) * sizeof(void *));
    list->size--;
    resize_if_needed(list);
}

void alst_insertIndex(ArrayList *list, int index, void *element) {
    if (index < 0 || index > list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    resize_if_needed(list);
    memmove(&list->data[index + 1], &list->data[index], (list->size - index) * sizeof(void *));
    list->data[index] = element;
    list->size++;
}

void alst_set(ArrayList *list, int index, void *element) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    list->data[index] = element;
}

void alst_clear(ArrayList *list) {
    list->size = 0;
    resize_if_needed(list);
}

