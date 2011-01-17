#ifndef GRAPH_H
#define GRAPH_H

struct edge
{
    /* An edge is two indices into the graph's vertex array, and a weight */
    int startidx;
    int endidx;
    int weight;
};

struct edge_node
{
    struct edge *edge;
    struct edge_node *next;
};

struct graph
{
    /* A graph is represented as an adjacency list. The vertices array is
     * indexed by vertex number and contains a pointer to a linked list of 
     * edges. Redundantly, the graph also contains a linked list of all of
     * the edges. */
    struct edge_node **vertices;
    struct edge_node *edges;
    int n_vertices;
};

// make_graph populates a given graph struct with n_vertices vertices.
void make_graph(int n_vertices, struct graph *g);
// make_edge dynamically allocates memory for a new edge and adds it to g.
void make_edge(struct graph *g, int u, int v, int weight);
// delete_edge removes the edge from u to v.
void delete_edge(struct graph *g, int u, int v);

void cons_edge_node(struct edge_node **list, struct edge_node *new);

#endif
