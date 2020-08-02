
#include <iostream>
#include <vector>

using namespace std;


struct Node{
	int val;
	Node *next;
};


class LinkedList{
private:
	Node *head;
	Node *root;

public:
	LinkedList(){
		head = new Node();
		root=head;
	}

	~LinkedList(){
		Node *next = root->next;
		while(next){
			Node *delete_node = next;
			next = next->next;
			delete delete_node;
		}
	}

	void append(int val){
		Node *new_node = new Node();
		new_node->val = val;
		new_node->next = NULL;

		head->next = new_node;
		head = new_node;
	}

	Node *get_head(){
		return root;
	}

};


void print_list(Node *root){
	Node *curr_head = root->next;
		while(curr_head){
			cout<<curr_head->val<<" ";
			curr_head = curr_head->next;
		}
		cout<<endl;
}





int main(int argc, char const *argv[])
{
	LinkedList list;
	vector<int> arr = {1,6,3,4,5,2,7};
	for(auto item:arr)
		list.append(item);

	//list.print_list();
	Node *root = list.get_head();
	print_list(root);
	return 0;
}





/**
单链表奇数递增偶数递减，重排使其升序
*/


#include <iostream>
#include <vector>

using namespace std;


struct Node{
	int val;
	Node *next;
};


class LinkedList{
private:
	Node *head;
	Node *root;

public:
	LinkedList(){
		head = new Node();
		root=head;
	}

	~LinkedList(){
		Node *next = root->next;
		while(next){
			Node *delete_node = next;
			next = next->next;
			delete delete_node;
		}
	}

	void append(int val){
		Node *new_node = new Node();
		new_node->val = val;
		new_node->next = NULL;

		head->next = new_node;
		head = new_node;
	}

	Node *get_head(){
		return root;
	}

};


void print_list(Node *root){
	Node *curr_head = root->next;
		while(curr_head){
			cout<<curr_head->val<<" ";
			curr_head = curr_head->next;
		}
		cout<<endl;
}


Node *reverse_list(Node *head){
	Node *first_node = NULL;
	Node *second_node = NULL;
	head = head->next;

	while(head){
		second_node = head->next;
		head->next = first_node;
		first_node = head;
		head = second_node;
	}

	return first_node;
}

Node *merge_list(Node *head1, Node *head2){
	Node *new_head = new Node();
	Node *tmp_node = new_head;

	while(head1 && head2){
		if(head1->val<head2->val){
			new_head->next = head1;
			head1 = head1->next;
		}else{
			new_head->next = head2;
			head2 = head2->next;
		}

		new_head = new_head->next;
	}

	if(head1)
		new_head->next = head1;
	if(head2)
		new_head->next = head2;

	return tmp_node;

}


void re_sort(Node *head){
	Node *odd_head = new Node();
	Node *even_head = new Node();
	Node *tmp_odd_head = odd_head;
	Node *tmp_even_head = even_head;
	Node *pre_odd_node = NULL;
	Node *pre_even_node = NULL;

	int index = 1;

	while(head){
		if(index%2==0){
			tmp_even_head->next = head;
			tmp_even_head = tmp_even_head->next;
			pre_even_node = tmp_even_head;
		}else{
			tmp_odd_head->next = head;
			tmp_odd_head = tmp_odd_head->next;
			pre_odd_node = tmp_odd_head;
		}

		head = head->next;
		index++;
	}

	if(index%2==0)
		pre_even_node->next = nullptr;
	else
		pre_odd_node->next = nullptr;
	

	print_list(merge_list(odd_head->next, reverse_list(even_head)));

}






int main(int argc, char const *argv[])
{
	LinkedList list;
	vector<int> arr = {1,6,3,4,5,2,7};
	for(auto item:arr)
		list.append(item);

	//list.print_list();
	Node *root = list.get_head();
		
	re_sort(root->next);

	return 0;
}
