#include <stdlib.h>
#include "kruskal.h"
#include "../graph/graph.h"
#include "../union-find/union-find.h"

struct edge_node *minimum_spanning_tree(struct graph *g)
{
    struct edge_node *tree = NULL;

    /* As we're building the tree, we need to maintain information about what
     * vertices are currently connected. We do this by using a union find data
     * structure that will allow us to quickly decide whether two vertices are
     * in the same connected component. We need to first initialize our data
     * by adding all of the vertices to their own separate islands. */

    struct uf_node *uf_nodes = (struct uf_node *) calloc(g->n_vertices, sizeof(struct uf_node));
    int i;
    for (i = 0; i < g->n_vertices; i++)
    {
        uf_node_create(i, uf_nodes + i);
    }

    /* Now, we look at each edge in cost order. If the two vertices that the
     * edge connects are in the same connected component, we continue. Otherwise
     * we add the edge to the tree. */
    struct edge_node *cur = g->edges;
    for (cur = g->edges; cur != NULL; cur = cur->next)
    {
        if (uf_node_find(uf_nodes + cur->edge->startidx) ==
            uf_node_find(uf_nodes + cur->edge->endidx))
            continue;

        struct edge_node *new = (struct edge_node *) calloc(1, sizeof(struct edge_node));
        new->edge = cur->edge;
        cons_edge_node(&tree, new);
        uf_node_union(uf_nodes + cur->edge->startidx, uf_nodes + cur->edge->endidx);
    }

    return tree;
}
