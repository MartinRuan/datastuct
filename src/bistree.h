#ifndef _BISTREE_H_
#define _BISTREE_H_
#include "bitree.h"

#define AVL_LFT_HEAVY   1
#define AVL_BALANCED    0
#define AVL_RGT_HEAVY   -1
#define BISTREE_SIZE(tree) ((tree)->size)

typedef struct avl_node_s {
    void *data;
    int hidden;
    int factor;
} avl_node_t;

typedef bitree_t bistree_t;

void bistree_init(bistree_t *tree, int(*compare)(const void *key1, const void *key2), 
    void (*destory)(bistree_t *tree;));
void bistree_destory(bistree_t *tree);
int bistree_insert(bistree_t *tree, const void *data);
int bistree_remove(bistree_t *tree, const void *data);
int bistree_lookup(bistree_t *tree, void **data);

#endif

