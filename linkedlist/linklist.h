#ifndef LINKLIST_H
#define LINKLIST_H

struct node
{
    int *data;
    struct node *nextNode;
    struct node *prevNode;
};

struct linkedList
{
    struct node *head;
    struct node *tail;
    int size;
};

void init(struct linkedList *list);
void add(struct linkedList *list, int *data);
struct node *getFirst(struct linkedList *list);
struct node *getLast(struct linkedList *list);
void dumplist(struct linkedList *list);
void swapNode(struct linkedList *list, struct node *node1, struct node *node2);
void removeNode(struct linkedList *list, struct node *node);
void removeFirst(struct linkedList *list);
void removeLast(struct linkedList *list);
void insertAfter(struct linkedList *list, struct node *node, int *data);
void insertBefore(struct linkedList *list, struct node *node, int *data);
int size(struct linkedList *list);
void clear(struct linkedList *list);
int indexOf(struct linkedList *list, struct node *node);
int getIndex(struct linkedList *list, int *index);

#endif // LINKLIST_H