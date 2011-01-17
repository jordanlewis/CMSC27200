#include <stdlib.h>
#include "graph.h"

static void append_edge_node(struct edge_node **list, struct edge_node *new)
{
    if (*list == NULL)
    {
        *list = new;
    }
    else
    {
        struct edge_node *cur = *list;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = new;
    }
}

void make_graph(int n_vertices, struct graph *g)
{
    g->n_vertices = n_vertices;
    g->vertices = (struct edge_node **) calloc(n_vertices, sizeof(struct edge_node *));
    g->edges = NULL;
}

void make_edge(struct graph *g, int u, int v)
{
    struct edge *edge = (struct edge *) calloc(1, sizeof(struct edge));


    struct edge_node *new_nodes[3];

    int i;
    for (i = 0; i < 3; i++)
    {
        new_nodes[i] = (struct edge_node *) calloc(1, sizeof(struct edge_node));
        new_nodes[i]->edge = edge;
    }

    append_edge_node(&g->edges, new_nodes[0]);
    append_edge_node(&g->vertices[u], new_nodes[1]);
    append_edge_node(&g->vertices[v], new_nodes[2]);

}
