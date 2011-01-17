#include <stdlib.h>
#include "union-find.h"

int main(int argc, char **argv)
{
    struct node *nodes = (struct node *) calloc(10, sizeof(struct node));

    int i;
    for (i = 0; i < 10; i++)
    {
        node_create(i, nodes + i);
    }

    struct node *even = nodes;
    struct node *odd = nodes + 1;
    for (i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            even = node_union(even, nodes + i);
        }
        else
        {
            odd = node_union(odd, nodes + i);
        }
    }

    for (i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            if (node_find(nodes + i) != even)
                return -1;
        }
        else
        {
            if (node_find(nodes + i) != odd)
                return -1;
        }
    }

    return 0;
}
