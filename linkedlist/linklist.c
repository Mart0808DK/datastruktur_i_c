#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

void init(struct linkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void add(struct linkedList *list, int *data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->prevNode = list->tail;

    if (list->size == 0)
    {
        list->head = newNode;
    }
    else
    {
        list->tail->nextNode = newNode;
    }

    list->tail = newNode;
    list->size++;
}

void removeNode(struct linkedList *list, struct node *node)
{
    if (node->prevNode != NULL)
    {
        node->prevNode->nextNode = node->nextNode;
    }
    else
    {
        list->head = node->nextNode;
    }

    if (node->nextNode != NULL)
    {
        node->nextNode->prevNode = node->prevNode;
    }
    else
    {
        list->tail = node->prevNode;
    }

    free(node);
    list->size--;
}

void swapNode(struct linkedList *list, struct node *node1, struct node *node2)
{
    if (node1 == node2)
    {
        return;
    }

    struct node *temp = node1->nextNode;
    node1->nextNode = node2->nextNode;
    node2->nextNode = temp;

    if (node1->nextNode != NULL)
    {
        node1->nextNode->prevNode = node1;
    }
    else
    {
        list->tail = node1;
    }

    if (node2->nextNode != NULL)
    {
        node2->nextNode->prevNode = node2;
    }
    else
    {
        list->tail = node2;
    }

    temp = node1->prevNode;
    node1->prevNode = node2->prevNode;
    node2->prevNode = temp;

    if (node1->prevNode != NULL)
    {
        node1->prevNode->nextNode = node1;
    }
    else
    {
        list->head = node1;
    }

    if (node2->prevNode != NULL)
    {
        node2->prevNode->nextNode = node2;
    }
    else
    {
        list->head = node2;
    }
}

void removeFirst(struct linkedList *list)
{
    if (list->size == 0)
    {
        return;
    }

    struct node *node = list->head;
    list->head = node->nextNode;

    if (list->head != NULL)
    {
        list->head->prevNode = NULL;
    }
    else
    {
        list->tail = NULL;
    }

    free(node);
    list->size--;
}

void removeLast(struct linkedList *list)
{
    if (list->size == 0)
    {
        return;
    }

    struct node *node = list->tail;
    list->tail = node->prevNode;

    if (list->tail != NULL)
    {
        list->tail->nextNode = NULL;
    }
    else
    {
        list->head = NULL;
    }

    free(node);
    list->size--;
}

void insertAfter(struct linkedList *list, struct node *node, int *data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->nextNode = node->nextNode;
    newNode->prevNode = node;

    if (node->nextNode != NULL)
    {
        node->nextNode->prevNode = newNode;
    }
    else
    {
        list->tail = newNode;
    }

    node->nextNode = newNode;
    list->size++;
}

void insertBefore(struct linkedList *list, struct node *node, int *data) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prevNode = node->prevNode;
    newNode->nextNode = node;

    if (node->prevNode != NULL)
    {
        node->prevNode->nextNode = newNode;
    }
    else
    {
        list->head = newNode;
    }
    
    node->prevNode = newNode;
    list->size++;
    

}

int indexOf(struct linkedList *list, struct node *node) 
{
    int index = 0;
    struct node *currentNode = list->head;
    while (currentNode != NULL)
    {
        if (currentNode == node)
        {
            return index;
        }
        currentNode = currentNode->nextNode;
        index++;
    }
    return -1;
}

int getIndex(struct linkedList *list, int *index)
{
    struct node *currentNode = list->head;
    int count = 0;
    while (currentNode)
    {
        if (count == *index)
        {
            return *currentNode->data;
        }
        count++;
        currentNode = currentNode->nextNode;
    }
    return -1;
    
}

struct node *getFirst(struct linkedList *list)
{
    return list->head;
}

struct node *getLast(struct linkedList *list)
{
    return list->tail;
}

int size(struct linkedList *list)
{
    return list->size;
}

void dumplist(struct linkedList *list)
{
    struct node *currentNode = list->head;
    while (currentNode != NULL)
    {
        printf("%d\n", *currentNode->data);
        currentNode = currentNode->nextNode;
    }
}

void clear(struct linkedList *list)
{
    struct node *currentNode = list->head;
    while (currentNode != NULL)
    {
        struct node *nextNode = currentNode->nextNode;
        free(currentNode);
        currentNode = nextNode;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}