#include <stdlib.h>
#include "union-find.h"

struct uf_node *uf_node_union(struct uf_node *a, struct uf_node *b)
{
    a = uf_node_find(a);
    b = uf_node_find(b);

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

struct uf_node *uf_node_find(struct uf_node *a)
{
    if (a == NULL)
        return NULL;

    if (a->parent == NULL)
        return a;
    else
    {
        a->parent = uf_node_find(a->parent);
        return a->parent;
    }
}

void uf_node_create(int value, struct uf_node *out)
{
    out->value = value;
    out->parent = NULL;
    out->size = 0;
}
