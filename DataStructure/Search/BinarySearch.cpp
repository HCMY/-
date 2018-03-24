#include<iostream>
#include<string>
#include <vector>

using namespace std;


int binarySearch(vector<int> nums, const int key){
   int low = 0,high = nums.size()-1,mid;
   int count = 0;

   while(low <= high){

   		mid = (low + high)/2;

   		if(nums[mid]==key)
   			return mid;
   		else if(nums[mid]>key)
   			high = mid-1;
   		else
   			low = mid+1;
   }

   return -1;
}


int main(int argc, char const *argv[])
{
	int nums[] = {1,2,3,4,5,6,7,8,9};
	vector<int> vec;
	vec.insert(vec.begin(), nums, nums+9);
	cout<<binarySearch(vec, 4)<<endl;
	return 0;
}


