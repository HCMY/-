
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
