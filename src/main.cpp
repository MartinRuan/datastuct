#include <iostream>
#include "rbtree.h"

using namespace std;

int main()
{
	cout << "ok" << endl;
	const int NEG_INF = -99999;
	RedBlackTree <int> tree(NEG_INF);
	tree.Insert(30);
	tree.Insert(15);
	tree.Insert(70);
	cout << tree.header_->right_->element_ << endl;
	cout << tree.header_->right_->left_->element_ << endl;
	cout << tree.header_->right_->right_->element_ << endl;
	
	return 0;
}

