const int SearchSequence(int *arr,const int key){
	const int length = arr[0];
	arr[0] = key;

	for(int i=1;i<=length;i++){
		if(arr[i]==key)
			return i;
	}
	return -1;

}
