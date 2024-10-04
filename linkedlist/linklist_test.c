#include <stdio.h>
#include "linklist.h"

int main() {
    struct linkedList list;
    init(&list);

    int index = 1;
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    int data4 = 40;

    add(&list, &data1);
    add(&list, &data2);
    add(&list, &data3);
    add(&list, &data4);

    printf("First node data: %d\n", *getFirst(&list)->data);
    printf("Last node data: %d\n", *getLast(&list)->data);

    printf("Swapping first and last node\n");
    swapNode(&list, getFirst(&list), getLast(&list));

    printf("Testing getIndex\n");
    printf("Data at index %d is %d\n", index, getIndex(&list, &index));

    printf("Index of last node is %d\n", indexOf(&list, getLast(&list)));


    printf("Size of list is %d\n", size(&list));
    printf("Dumping list:\n");
    
    dumplist(&list);
    return 0;
}
