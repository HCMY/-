#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;


struct TreeNode
{
	int key;
	SearchTree left;
	SearchTree right;
	
};


SearchTree MakeEmpty(SearchTree T){
	if(T){
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
}

Position Find(SearchTree T,int key){
	if(!T)
		return NULL;
	if(key<T->key)
		return Find(T->left,key);
	else if (key>T->key)
		return Find(T->right,key);
	else
		return T;
}


Position FindMin(SearchTree T){
	if(T==NULL)
		return NULL;
	else if(T->left==NULL)
		return T;
	else
		return FindMin(T->left);

}


Position FindMax(SearchTree T){
	if(T==NULL)
		return T;
	else if(T->right==NULL)
		return T;
	else
		return FindMax(T->right);
}


SearchTree Insert(SearchTree T,int data){
	if(T==NULL){
		T = malloc(sizeof(struct TreeNode));
		if(!T)exit(0);
		else{
			T->key = data;
			T->left = T->right = NULL;
		}
	}
	else if(data<T->key)
		T->left = Insert(T->left,data);
	else if(data>T->key)
		T->right = Insert(T->right,data);
	return T;
}

SearchTree Delete(SearchTree T,int data){
	Position tmp_cell;

	if(!T)exit(0);
	else if(data<T->key)
		T->left = Delete(T->left,data);
	else if(data>T->key)
		T->right = Delete(T->right,data);
	else if(T->left && T->right){
		tmp_cell = FindMin(T->right);
		T->key = tmp_cell->key;
		T->right = Delete(T->right,T->key);
	}else{
		tmp_cell = T;
		if(T->left==NULL)
			T = T->right;
		else if(T->right==NULL)
			T = T->left;
		free(tmp_cell);
	}
	return T;
}









