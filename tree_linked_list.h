#ifndef TREE_LINKED_LIST_H
#define TREE_LINKED_LIST_H

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

// Defining the list
typedef struct T_node
{
    struct Tree* value;
    struct T_node* next;
} T_node;

typedef struct T_List
{
    struct T_node* head;
} T_List;

T_List* create_list(Tree* t);
void append(T_List* l, Tree* t);
void prepend(T_List* l, Tree* t);
int pre_pop(T_List* l);
int pop(T_List* l);
int pop_index(T_List*l, int index);

#endif
