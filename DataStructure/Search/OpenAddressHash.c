#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define INIT_SIZE 16

typedef struct
{
	int *base;
	int element_count;
	int temporary_length;
}HashTable;

void InitTable(HashTable *T){
	T->base = (int *)malloc(INIT_SIZE*sizeof(int));
	T->element_count = 0;
	T->temporary_length = INIT_SIZE;
}


int Hash(int key,HashTable T){
	int pos = key%13;
	return pos;
}

int EQ(int key,int table_exist_key){
	return key==table_exist_key;
}

void Collusion(int *p,int *c){
    *p = *p+1;
    *c = *c+1;
}

int SearchHash(HashTable T,int key,int *p,int *c){
	*p = Hash(key,T);
	while(T.base[*p]!=NULL && EQ(key,*p)){
		Collusion(p,c);
	}
	if(EQ(key,*p))
		return 1;
	else
		return 0;
}

int Insert(HashTable *T,int key){
	int c = 0;
	int p = 0;
	if(SearchHash(*T,key,&p,&c)){
		return -1;
	}
	else if(c<T->temporary_length/2){
		T->base[p] = key;
		T->element_count++;
		printf("loc= %d,data= %d\n",p,T->base[p]);
		return 0;
	}

}



int main(int argc, char const *argv[])
{
	HashTable *T;
	InitTable(&T);
	Insert(&T,19);
	Insert(&T,14);
    Insert(&T,23);
    Insert(&T,01);
    Insert(&T,68);

	return 0;
}


