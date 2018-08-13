

#ifndef BinarySearchTree_H
#define BinarySearchTree_H

#include <algorithm>
#include <iostream>

templete <typename Comparable>




class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree &rhs);
	BinarySearchTree(BinarySearchTree && rhs);
	~BinarySearchTree();

	const Comparable &findMin() const; //read only
	const Comparable &findMax() const;
	
	bool contains(const Comparable &x) const{
		return contains(x, root);
	}

	bool isEmpty() const;
	void printTree(ostream &out=cout) const;

	void makeEmpty();

	void insert(const Comparable &x){
		insert(x, root);
	}

	void insert(Comparable && x);

	void remove(const Comparable &x){
		remove(x, root);
	}
	
	BinarySearchTree &operator=(const BinarySearchTree &rhs);
	BinarySearchTree &operator=(BinarySearchTree &&rhs);

private:
	struct BinaryNode{	
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;	
	
		BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt):
			element{theElement}, left{lt}, right{rt} {}
		BinaryNode(const Comparable &&theElement, BinaryNode *lt, BinaryNode *rt):
			element{std::move(theElement)}, left(lt), right(rt){}
	};

	BinaryNode *root;

	void insert(const Comparable &x, BinaryNode *&t);
	void insert(const Comparable &&x, BinaryNode *&t);
	void remove(const Comparable &x, BinaryNode *&t);
	BinaryNode *findMin(BinaryNode *t) const;
	BinaryNode *findMax(BinaryNode *&t) const;
	
	bool contains(const Comparable &x, BinaryNode *t) const{
		if(t == nullptr)
			return false;
		else if(x < t->element)
			return contains(x, t->left);
		else if(x > t->element)
			return contains(x, t-right);
		else
			return true;
	}

	void makeEmpty(BinaryNode *&t);
	void printTree(BinaryNode *t, ostream &out);
	BinaryNode *clone(BinaryNode *t) const;
};

#endif