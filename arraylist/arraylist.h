#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList* alst_arraylist();
void alst_add(ArrayList *list, void *element);
void* alst_get(ArrayList *list, int index);
int alst_size(ArrayList *list);
void alst_remove(ArrayList *list);
void alst_removeIndex(ArrayList *list, int index);
void alst_insertIndex(ArrayList *list, int index, void *element);
void alst_set(ArrayList *list, int index, void *element);
void alst_clear(ArrayList *list);

#endif // ARRAYLIST_H