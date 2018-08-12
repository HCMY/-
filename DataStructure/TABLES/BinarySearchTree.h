
#ifndef BinarySearchTree_H
#define BinarySearchTree_H

struct BinaryNode
{
	Object element;
	BinaryNode *left;
	BinaryNode *right;
	
};


class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree &rhs);
	BinarySearchTree(BinarySearchTree && rhs);
	~BinarySearchTree();
	
	
};

#endif