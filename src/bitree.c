#include <stdlib.h>
#include "bitree.h"

/*
 * @tree:
 * @destroy:
 */
void bitree_init(bitree_t *tree, void (*destory)(void *data))
{
    if (NULL == tree) {
        return;
    }
    tree->destroy = destory;
    tree->size = 0;
    tree->root = NULL;
}

/*
 * @tree:
 */
void bitree_destory(bitree_t *tree)
{
    if (NULL == tree) {
        return;
    }
    bitree_rem_left(tree, NULL);
    memset(tree, 0, sizeof(*tree));
}

/*
 * @tree:
 * @node:
 */
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

/*
 * @tree:
 * @node:
 */
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

/*
 * @tree:
 * @node:
 * @data:
 */
int bitree_ins_left(bitree_t *tree, bitree_node_t *node, const void *data)
{
    bitree_node_t *new_node, **position;
    if (NULL == tree || NULL == data) {
        return -1;
    }

    if (NULL == node) {
        if (BITREE_SIZE(tree) != 0) {
            return -1;
        }
        position = &tree->root;
    } else {
        if (NULL != BITREE_LEFT(node)) {
            return -1;
        }
        position = &node->left;
    }

    new_node = (bitree_node_t *)malloc(sizeof(*new_node));
    if (NULL == new_node) {
        return -1;
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;
    tree->size++;
    
    return 0;
}

/*
 * @tree:
 * @node:
 * @data:
 */
int bitree_ins_right(bitree_t *tree, bitree_node_t *node, const void *data)
{
    bitree_node_t *new_node, **position;
    if (NULL == tree || NULL == data) {
        return -1;
    }

    if (NULL == node) {
        if (BITREE_SIZE(tree) != 0) {
            return -1;
        }
        position = &tree->root;
    } else {
        if (NULL != BITREE_RIGHT(node)) {
            return -1;
        }
        position = &node->right;
    }

    new_node = (bitree_node_t *)malloc(sizeof(*new_node));
    if (NULL == new_node) {
        return -1;
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;
    tree->size++;
    
    return 0;
}

/*
 * @merge:
 * @right:
 * @left:
 * @data:
 */
int bitree_merge(bitree_t *merge, bitree_t *right, bitree_t *left, const void *data)
{
    if (NULL == merge || NULL == right || NULL == left) {
        return -1;
    }
    bitree_init(merge, left->destroy);

    if (bitree_ins_left(merge, NULL, data) != 0) {
        bitree_destory(merge);
        return -1;
    }

    BITREE_ROOT(merge)->left = BITREE_ROOT(left);
    BITREE_ROOT(merge)->right = BITREE_ROOT(right);

    merge->size = merge->size + BITREE_SIZE(left) + BITREE_SIZE(right);

    left->root = NULL;
    left->size = 0;
    right->root = NULL;
    right->size = 0;

    return 0;
}

int bitree_preorder(const bitree_t *tree, list_t *list)
{
    return 1;
}

int bitree_inorder(const bitree_t *tree, list_t *list)
{
    return 1;
}

int bitree_postorder(const bitree_t *tree, list_t *list)
{
    return 1;
}
