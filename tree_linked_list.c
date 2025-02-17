#include <stdio.h>
#include <stdlib.h>
#include "tree_linked_list.h"
#include "tree.h"


// Single element initialization
T_List* create_list(Tree* t) 
{

    T_List* new = malloc(sizeof(T_List));
    T_node* first = malloc(sizeof(T_node));

    first->next = NULL;
    first->value = t;

    new->head = first;

    return new;
}

// Add an element to tail
void append(T_List* l, Tree* t) 
{
    T_node* cur = l->head;

    T_node* new = malloc(sizeof(T_node));
    new->value = t;
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
void prepend(T_List* l, Tree* t)
{
    T_node* new = malloc(sizeof(T_node));

    new->next = l->head;
    new->value = t;

    l->head = new;
}

// Remove and return an element from head
// (Assuming len > 0)
int pre_pop(T_List* l) 
{
    Tree* t = l->head->value;
    T_node* temp = l->head->next;
    free(l->head);
    l->head = temp;

    return t;
}

// Remove and return an element from the tail
// (Assuming len > 0)
int pop(T_List* l) 
{
    T_node* cur = l->head;
    Tree* t = NULL;
    
    while(cur != NULL) 
    {
        if (cur->next->next == NULL)
        {
            t = cur->next->value;
            free(cur->next);
            cur->next = NULL;
            break;
        }
        cur = cur->next;
    }
    return t;
}

// Remove and return an element from an arbitrary index
// (Assuming len > 0, index is positive and less the len and l is zero indexed)
int pop_index(T_List*l, int index) 
{
    T_node* cur = l->head;
    Tree* t = NULL;

    if (index == 0) 
    {
        return pre_pop(l);
    }

    int counter = 1;

    while(cur != NULL)
    {
        if (counter == index) 
        {
            t = cur->next->value;
            T_node* temp = cur->next->next;
            free(cur->next);
            cur->next = temp;
            break;
        }
        cur = cur->next;
        counter++;
    }
    return t;
}