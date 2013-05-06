#include <stdlib.h>
#include "bitree.h"

void bitree_init(bitree_t *tree, void (*destory)(void *data))
{
    if (NULL == tree) {
        return;
    }
    tree->destroy = destory;
    tree->size = 0;
    tree->root = NULL;
}

void bitree_destory(bitree_t *tree)
{
    if (NULL == tree) {
        return;
    }
    bitree_rem_left(tree, NULL);
    memset(tree, 0, sizeof(*tree));
}

void bitree_rem_left(bitree_t *tree, bitree_node_t *node)
{
    bitree_node_t **position;
    
    if (NULL == tree || 0 == BITREE_SIZE(tree)) {
        return;
    }
    
    if (NULL == node) {
        position = &tree->root;
    } else {
        position = &node->left;
    }

    if (NULL != (*position)) {
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);
        if (tree->destroy) {
            tree->destroy((*position)->data);
        }
        free(*position);
        *position = NULL;
        tree->size--;
    }
}

void bitree_rem_right(bitree_t *tree, bitree_node_t *node)
{
    bitree_node_t **position;
    
    if (NULL == tree || 0 == BITREE_SIZE(tree)) {
        return;
    }
    
    if (NULL == node) {
        position = &tree->root;
    } else {
        position = &node->right;
    }

    if (NULL != (*position)) {
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);
        if (tree->destroy) {
            tree->destroy((*position)->data);
        }
        free(*position);
        *position = NULL;
        tree->size--;
    }
}

int bitree_ins_left(bitree_t *tree, bitree_node_t *node, const void *data)
{
    
}
