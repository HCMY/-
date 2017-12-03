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
