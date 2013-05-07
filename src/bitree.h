#ifndef _BITREE_H_
#define _BITREE_H_

#define BITREE_SIZE(tree)   ((tree)->size)
#define BITREE_LEFT(node)   ((node)->left)
#define BITREE_RIGHT(node)  ((node)->right)
#define BITREE_ROOT(tree)   ((tree)->root)
#define BITREE_IS_LEFT(node) ((node)->left == NULL && (node)->right == NULL)
#define BITREE_IS_EOB(node) ((node) == NULL)

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
int bitree_ins_left(bitree_t *tree, bitree_node_t *node, void *data);
int bitree_ins_right(bitree_t *tree, bitree_node_t *node, void *data);
int bitree_merge(bitree_t *merge, bitree_node_t *right, const void *data);
void bitree_rem_left(bitree_t *tree, bitree_node_t *node);
void bitree_rem_right(bitree_t *tree, bitree_node_t *node);

#endif

