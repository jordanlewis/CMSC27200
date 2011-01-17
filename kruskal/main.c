#include <stdlib.h>
#include <stdio.h>
#include "kruskal.h"
#include "../graph/graph.h"

int main(int argc, char **argv)
{
    struct graph graph;
    struct graph *g = &graph;
    make_graph(6, g);

    /* Copying the first graph on the following example picture on wikipedia's
     * minimum spanning tree page:
     * http://upload.wikimedia.org/wikipedia/commons/5/54/Msp1.jpg */
    make_edge(g, 0, 1, 1);
    make_edge(g, 0, 3, 4);
    make_edge(g, 0, 4, 3);

    make_edge(g, 1, 3, 4);
    make_edge(g, 1, 4, 2);

    make_edge(g, 2, 4, 4);
    make_edge(g, 2, 5, 5);

    make_edge(g, 3, 4, 4);

    make_edge(g, 4, 5, 7);


    struct edge_node *mst = minimum_spanning_tree(g);

    for (; mst != NULL; mst = mst->next)
    {
        printf("%d <-- %d --> %d\n", mst->edge->startidx, mst->edge->weight, mst->edge->endidx);
    }

    return 0;
}
