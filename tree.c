#include "tree_linked_list.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Tree* create_tree(int root, T_List* subtrees)
{
    Tree* new = malloc(sizeof(Tree));
    new->root = root;
    new->subtrees = subtrees;

    return new;
}

void insert(Tree* t, int n) 
{
    Tree* new = create_tree(n, NULL);
    if (t == NULL)
    {
        t = new;
    }

    else if (t->subtrees == NULL)
    {
        append(t->subtrees, new);
    }

    else {
        insert(t->subtrees->head->value, n);
    }    
}