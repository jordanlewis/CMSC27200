#ifndef UNION_FIND_H
#define UNION_FIND_H
struct node
{
    int value;
    int size;
    struct node *parent;
};

struct node *node_union(struct node *a, struct node *b);
struct node *node_find(struct node *a);
void node_create(int value, struct node *out);

#endif
