#ifndef _BITREE_H_
#define _BITREE_H_

#define BITREE_SIZE(tree) (tree->size)


typedef struct bitree_node_s {
    void *data;
    struct bitree_node_s *left;
    struct bitree_node_s *right;
} bitree_node_t;

typedef struct bitree_s {
    int size;
    int (*compare)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    bitree_node_t *root;
} bitree_t;

void bitree_init(bitree_t *tree, void (*destory)(void *data));
void bitree_destory(bitree_t *tree);
void bitree_rem_left(bitree_t *tree, bitree_node_t *node);
void bitree_rem_right(bitree_t *tree, bitree_node_t *node);

#endif

