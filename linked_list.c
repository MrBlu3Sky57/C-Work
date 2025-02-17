#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Update to use void pointers


// Single element initialization
List* create_list(int n) 
{

    List* new = malloc(sizeof(List));
    L_node* first = malloc(sizeof(L_node));

    first->next = NULL;
    first->value = n;

    new->head = first;

    return new;
}

// Add an element to tail
void append(List* l, int n) 
{
    L_node* cur = l->head;

    L_node* new = malloc(sizeof(L_node));
    new->value = n;
    new->next = NULL;

    while (cur != NULL) 
    {
        if (cur->next == NULL) 
        {
            cur->next = new;
            break;
        }

        cur = cur->next;
    }

    if (cur->next == NULL) 
    {
            cur->next = new;
    }
}

// Add an element to head
void prepend(List* l, int n)
{
    L_node* new = malloc(sizeof(L_node));

    new->next = l->head;
    new->value = n;

    l->head = new;
}

// Remove and return an element from head
// (Assuming len > 0)
int pre_pop(List* l) 
{
    int n = l->head->value;
    L_node* temp = l->head->next;
    free(l->head);
    l->head = temp;

    return n;
}

// Remove and return an element from the tail
// (Assuming len > 0)
int pop(List* l) 
{
    L_node* cur = l->head;
    int n = 0;
    
    while(cur != NULL) 
    {
        if (cur->next->next == NULL)
        {
            n = cur->next->value;
            free(cur->next);
            cur->next = NULL;
            break;
        }
        cur = cur->next;
    }
    return n;
}

// Remove and return an element from an arbitrary index
// (Assuming len > 0, index is positive and less the len and l is zero indexed)
int pop_index(List*l, int index) 
{
    L_node* cur = l->head;
    int n = 0;

    if (index == 0) 
    {
        return pre_pop(l);
    }

    int counter = 1;

    while(cur != NULL)
    {
        if (counter == index) 
        {
            n = cur->next->value;
            L_node* temp = cur->next->next;
            free(cur->next);
            cur->next = temp;
            break;
        }
        cur = cur->next;
        counter++;
    }
    return n;
}

// Print out list
void printl(List* l)
{
    L_node* cur = l->head;
    
    while (cur != NULL) {
        printf("%d\n", cur->value);
        cur = cur->next;
    }
}