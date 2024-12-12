#include <stdio.h>
#include <stdlib.h>

// Defining the list
typedef struct node 
{
    int value;
    struct node* next;
} node;

typedef struct list 
{
    node* head;
} list;

// Single element initialization
list* create_list(int n) 
{

    list* new = malloc(sizeof(list));
    node* first = malloc(sizeof(node));

    first->next = NULL;
    first->value = n;

    new->head = first;

    return new;
}

// Add an element to tail
void append(list* l, int n) 
{
    node* cur = l->head;

    node* new = malloc(sizeof(node));
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
}

// Add an element to head
void prepend(list* l, int n)
{
    node* new = malloc(sizeof(node));

    new->next = l->head;
    new->value = n;

    l->head = new;
}

// Remove and return an element from head
// (Assuming len > 0)
int pre_pop(list* l) 
{
    int n = l->head->value;
    node* temp = l->head->next;
    free(l->head);
    l->head = temp;

    return n;
}

// Remove and return an element from tail
// (Assuming len > 0)
int pop(list* l) 
{
    node* cur = l->head;
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
int pop_index(list*l, int index) 
{
    node* cur = l->head;
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
            node* temp = cur->next->next;
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
void printl(list* l)
{
    node* cur = l->head;
    
    while (cur != NULL) {
        printf("%d\n", cur->value);
        cur = cur->next;
    }
}

int main() 
{
    return 0;
}