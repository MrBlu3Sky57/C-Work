#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "tree_linked_list.h"
#include "tree.c"

// Defining the N-ary tree
typedef struct Tree 
{
    int root;
    struct T_list* subtrees;
} Tree;

Tree* create_tree(int root, T_List* subtrees);

#endif