#include <iostream>
#include <vector>

int getLow(std::vector<int> &vec, int low, int high){
	const int key = vec[low];
	while(low<high){

        while(low<high && vec[high]>=key) high--;
		vec[low] = vec[high];
		while(low<high && vec[low]<=key) low++;
		vec[high] = vec[low];

	}
    vec[low] = key;
	return low;
}


void qsort(std::vector<int> &vec, int low, int high){
	if(low<high){
		int mid = getLow(vec, low, high);
		qsort(vec, low, mid-1);
		qsort(vec, mid+1, high);
	}
}


int main(int argc, char const *argv[])
{
	int arr[] = {1,5,3,19,2,44,5,7,9};
	std::vector<int> v;
	v.insert(v.begin(), arr, arr+9);
	qsort(v, 0, 8);

	for(int i=0; i<v.size(); i++)
		std::cout<<v[i]<<" ";
	std::cout<<std::endl;
	return 0;
}
