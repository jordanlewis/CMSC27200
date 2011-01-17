#include <stdlib.h>
#include "union-find.h"

int main(int argc, char **argv)
{
    struct uf_node *nodes = (struct uf_node *) calloc(10, sizeof(struct uf_node));

    int i;
    for (i = 0; i < 10; i++)
    {
        uf_node_create(i, nodes + i);
    }

    struct uf_node *even = nodes;
    struct uf_node *odd = nodes + 1;
    for (i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            even = uf_node_union(even, nodes + i);
        }
        else
        {
            odd = uf_node_union(odd, nodes + i);
        }
    }

    for (i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            if (uf_node_find(nodes + i) != even)
                return -1;
        }
        else
        {
            if (uf_node_find(nodes + i) != odd)
                return -1;
        }
    }

    return 0;
}
