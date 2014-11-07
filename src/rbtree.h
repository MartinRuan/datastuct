#ifndef __RBTREE_H__
#define __RBTREE_H__

#include "except.h"

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
    void Insert(const T &x);
public:
//private:
    Node *header_;
    Node *null_node_;

    Node *current_;
    Node *parent_;
    Node *grand_;
    Node *great_;
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
public:
//private:
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

template <typename T>
void RedBlackTree < T >::Insert(const T &x)
{
    current_ = parent_ = grand_ = header_;
    null_node_->element_ = x;

    while (current_->element_ !=x) {
        great_ = grand_;
        grand_ = parent_;
        parent_ = current_;

        current_= x < current_->element_ ? current_->left_ : current_->right_;
    }

    if (current_ != null_node_) {
        throw DuplicateItemException();
    }

    current_ = new Node(x, null_node_, null_node_);
    if (x < parent_->element_) {
        parent_->left_ = current_;    
    } else {
        parent_->right_ = current_;
    }
    
}
#endif

