#ifndef UNION_FIND_H
#define UNION_FIND_H
struct uf_node
{
    int value;
    int size;
    struct uf_node *parent;
};

struct uf_node *uf_node_union(struct uf_node *a, struct uf_node *b);
struct uf_node *uf_node_find(struct uf_node *a);
void uf_node_create(int value, struct uf_node *out);

#endif
