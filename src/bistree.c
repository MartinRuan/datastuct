#include "bistree.h"


static void destory_right(bistree_t *tree, bitree_node_t *node);

static void rotate_left(bitree_node_t **node)
{
    bitree_node_t *left, *grandchild;

    left = BITREE_LEFT(*node);
    if (((avl_node_t *)BITREE_DATA(left))->factor == AVL_LFT_HEAVY) {
        /* perform an LL rotation */
        BITREE_LEFT(*node) = BITREE_RIGHT(node);
        BITREE_RIGHT(left) = *node;
        ((avl_node_t *)BITREE_DATA(*node))->factor = AVL_BALANCED;
        ((avl_node_t *)BITREE_DATA(left))->factor = AVL_BALANCED;
        *node = left;
    } else {
        /* perform an LR rotation */
        grandchild = BITREE_RIGHT(left);
        BITREE_RIGHT(left) = BITREE_LEFT(grandchild);
        BITREE_LEFT(grandchild) = left;
        BITREE_LEFT(*node) = BITREE_RIGHT(grandchild);
        BITREE_RIGHT(grandchild) = *node;

        switch (((avl_node_t *)BITREE_DATA(grandchild))->factor) {
        case AVL_LFT_HEAVY:
            (((avl_node_t *)BITREE_DATA(*node))->factor) = AVL_RGT_HEAVY;
            (((avl_node_t *)BITREE_DATA(left))->factor) = AVL_BALANCED;
            break;
        case AVL_BALANCED:
            (((avl_node_t *)BITREE_DATA(*node))->factor) = AVL_BALANCED;
            (((avl_node_t *)BITREE_DATA(left))->factor) = AVL_BALANCED;
            break;
        case AVL_RGT_HEAVY:
            (((avl_node_t *)BITREE_DATA(*node))->factor) = AVL_BALANCED;
            (((avl_node_t *)BITREE_DATA(left))->factor) = AVL_LFT_HEAVY;
            break;
        default:
            break;
        }
        (((avl_node_t *)BITREE_DATA(grandchild))->factor) = AVL_BALANCED;
        *node = grandchild;
    }
}

static void rotate_right(bitree_node_t **node)
{

}

void bistree_init(bistree_t *tree, int(*compare)(const void *key1, const void *key2), 
    void (*destory)(bistree_t *tree))
{
    bitree_init(tree, destory);
    tree->compare = compare;
}

void bistree_destory(bistree_t *tree)
{
    distroy_letf(tree, NULL);
}

int bistree_insert(bistree_t *tree, const void *data)
{

}

int bistree_remove(bistree_t *tree, const void *data)
{

}

int bistree_lookup(bistree_t *tree, void **data)
{

}
