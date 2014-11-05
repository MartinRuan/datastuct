#ifndef __RBTREE_H__
#define __RBTREE_H__

template <typename T>
class RedBlackTree;

template <typename T>
class RedBlackNode;

template <typename T>
class RedBlackTree
{
public:
    enum {RED, BLACK};
    typedef RedBlackNode<T> Node;
    RedBlackTree(const T &neg_inf);
    ~RedBlackTree();
private:
    Node *header_;
    Node *null_node_;
};

template <typename T>
class RedBlackNode
{
    friend class RedBlackTree<T>;
    RedBlackNode(const T &element = T(), RedBlackNode *left = NULL, 
        RedBlackNode *right = NULL, int color = RedBlackTree<T>::BLACK):
        element_(element), left_(left), right_(right), color_(color)
    {

    }
private:
    T element_;
    RedBlackNode *left_;
    RedBlackNode *right_;
    int color_;
};

template <typename T>
RedBlackTree<T>::RedBlackTree(const T &neg_inf)
{
    null_node_ = new Node();
    null_node_->left_ = null_node_->right_ = null_node_;
    header_ = new Node(neg_inf);
    header_->left_ = header_->right_ = null_node_;
}

template <typename T>
RedBlackTree<T>::~RedBlackTree()
{
    delete null_node_;
    delete header_;
}
#endif

