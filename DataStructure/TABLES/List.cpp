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
	class const_iterator
	{
	public:
		const_iterator():current(nullptr) {}

		const Object & opetator* () const
            {return retrieve();}

		const_iterator &opetator++() {
			current = current->next;
			return *this;
		}

		const_iterator opetator++(int){
			const_iterator old = *this;
			++(*this);
			return old;
		}

		bool opetator==(const const_iterator &rhs) const {return current==rhs.current;}
		bool opetator!=(const const_iterator &rhs) const {return !(*this==rhs);}


		~const_iterator();

	protected:
		Node *current;

		Object &retrieve() const
            {return current->data;}

		const_iterator(Node *p):current(p) {}

		friend class List<Object>;
	};

public:
	List();
	~List();


};


