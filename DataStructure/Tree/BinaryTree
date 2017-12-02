#include<iostream>
#include <stdlib.h>
#include <stdio.h>


#include<stack>
#include<queue>



typedef struct Node
{
	char data;
	struct Node *left,*right;

}Node,*Tree;

std::stack<Node *> my_stack_a;


void PreCreateTree(Tree &T){
	char input;
	scanf("%c",&input);

	if(input==' ')
		T = NULL;
	else{
        T = new Node;
        if(!T)exit(0);

		T->data = input;
		PreCreateTree(T->left);
		PreCreateTree(T->right);
	}

}


void PreOrder(const Tree T){
	if(T){
		std::cout<<T->data<<" ";
		PreOrder(T->left);
		PreOrder(T->right);
	}

}

void InOrder(const Tree T){
    if(T){
        InOrder(T->left);
        std::cout<<T->data<<" ";
        InOrder(T->right);
    }

}

void PostOrder(const Tree T){
    if(T){
        PostOrder(T->left);
        PostOrder(T->right);
        std::cout<<T->data<<" ";
    }

}

void LevelOrder(const Tree T){
    std::queue<Tree> my_queue;
    Tree p;

    my_queue.push(T);
    while(!my_queue.empty()){
        p = my_queue.front();
        my_queue.pop();
        std::cout<<p->data<<" ";
        if(p->left!=NULL)
            my_queue.push(p->left);
        if(p->right!=NULL)
            my_queue.push(p->right);

    }
    std::cout<<std::endl;
}

/*
void InOrder2(Tree &T){
    Tree p = T;
    my_stack_a.push(p);
    while(!my_stack_a.empty()){
        while(p=)
    }
}*/


int main(int argc, char const *argv[])
{
	Tree T;

	PreCreateTree(T);
	PreOrder(T);
	std::cout<<std::endl;
	InOrder(T);
	std::cout<<std::endl;
	PostOrder(T);
	std::cout<<std::endl;
    LevelOrder(T);


	return 0;
}

