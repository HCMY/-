#include<iostream>

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

		const Object & operator*() const
            { return retrieve();}

		const_iterator &operator++() {
			current = current->next;
			return *this;
		}

		const_iterator operator++(int){
			const_iterator old = *this;
			++(*this);
			return old;
		}

		bool operator==(const const_iterator &rhs) const {return current==rhs.current;}
		bool operator!=(const const_iterator &rhs) const {return !(*this==rhs);}


		~const_iterator();

	protected:
		Node *current;

		Object &retrieve() const
            {return current->data;}

		const_iterator(Node *p):current(p) {}

		friend class List<Object>;
	};

	class iterator: public const_iterator
	{
	public:
		iterator() {};
		~iterator() {};

		Object &operator*()
		{return const_iterator::retrieve();}

		const Object &operator*() const
		{return const_iterator::operator*();}

		iterator &operator++(){
			this->current = this->current->next;
			return *this;
		}

		iterator operator++(int){
			iterator old = *this;
			++(*this);
			return old;
		}

	protected:
		iterator(Node *p):const_iterator(p) {}
		friend class List<Object>;

	};

public:
	List() { init();}
	List(const List &rhs){
		init();
		for(auto &x:rhs)
			push_back(x);
	}

	~List(){
		clear();
		delete head;
		delete tail;
	}


	int size() const{ return the_size;}
	bool empty() const{return size()==0;}

	void clear(){
		while(!empty())
			pop_front();
	}


	List &operator=(const List &rhs){
		List copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	iterator begin() {return head->next;}
	const_iterator begin() const {return head->next;}
	iterator end() {return tail;}
	const_iterator end() const {return tail;}

	iterator erase(iterator itr){}
	iterator erase(iterator from, iterator to){}
	
	void pop_front() {return 0;}
	void push_back() {return 0;}









private:
	int the_size;
	Node *head;
	Node *tail;

	void init(){
		the_size = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}

};

