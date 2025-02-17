#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Defining the list
typedef struct L_node 
{
    int value;
    struct L_node* next;
} L_node;

typedef struct List 
{
    L_node* head;
} List;

List* create_list(int n);
void append(List* l, int n);
void prepend(List* l, int n);
int pre_pop(List* l);
int pop(List* l);
int pop_index(List*l, int index);
void printl(List* l);

#endif