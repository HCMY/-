#include<iostream>
using namespace std;

template <typename Object>



class List
{

private:
	struct Node
	{
		Object data;
		Node *prev;
		Node *next;

	Node(const Object &d=Object{}, Node *p=nullptr, Node *n=nullptr)
	:data(d), prev(p), next(n) { }

	};

public:
	List();
	~List();


};


