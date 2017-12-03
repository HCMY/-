#include <iostream>

int BinarySearch(const int *arr,const int length,const int key){
	int low = 0;
	int high = length-1;
	int mid;

	while(low<=high){
		mid = (low+high)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]>key)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}


void InsertSort(int *arr){//elements' index start from 1, index '0' is length of the array
	const int length = arr[0];
	int j,i;

	for(i=2;i<=length;i++){
		if(arr[i]<arr[i-1]){
            arr[0] = arr[i];
        arr[i] = arr[i-1];
        for(j=i-2;arr[j]>arr[0];j--)
            arr[j+1] = arr[j];
		arr[j+1] = arr[0];
        }
	}
}

void ShellSort(int *arr){
    const int length = arr[0];
    int dk;
    int i,j;

    for(dk=length/2;dk>=1;dk/=2){
    	for(i=dk+1;i<=length;i++){
    		if(arr[i]<arr[i-dk]){
    			arr[0] = arr[i];
    		for(j=i-dk;j>0&&arr[0]<arr[j];j-=dk)
    			arr[j+dk] = arr[j];
    		arr[j+dk] = arr[0];
    		}
    	}
    }
}


/**
*Quick Sort
*/

int Partition(int *arr,int low,int high){
	int pivot = arr[low];
	while(low<high){
		while(low<high && arr[high]>=pivot) high--;
		arr[low] = arr[high];
		while(low<high && arr[low]<=pivot) low++;
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
}


void QuickSort(int *arr,int low,int high){
	int pos;
	if(low<high){
        pos = Partition(arr,low,high);
        QuickSort(arr,low,pos-1);
        QuickSort(arr,pos+1,high);
	}
}


/** Select Sort*/
void Swap(int *a,int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void NormalSelect(int *arr,int length){
	int min,i;
	for(i=0;i<length;i++){
		min = i;
		for(int j=i+1;j<length;j++)
			if(arr[j]<arr[min])
				min = j;
		if(min!=i)
			Swap(&arr[min],&arr[i]);
	}
}
