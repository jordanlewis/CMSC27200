#include <stdlib.h>
#include "union-find.h"

struct node *node_union(struct node *a, struct node *b)
{
    a = node_find(a);
    b = node_find(b);

    if (a == b)
        return a;

    if (a->size > b->size)
    {
        b->parent = a;
        a->size += b->size;
    }
    else
    {
        a->parent = b;
        b->size += a->size;
    }
}

struct node *node_find(struct node *a)
{
    if (a == NULL)
        return NULL;

    if (a->parent == NULL)
        return a;
    else
    {
        a->parent = node_find(a->parent);
        return a->parent;
    }
}

void node_create(int value, struct node *out)
{
    out->value = value;
    out->parent = NULL;
    out->size = 0;
}
