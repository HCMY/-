#include <string>
#include <iostream>
#include <queue>
#include<vector>

using namespace std;


void radixSort(vector<int> &a, int n)
{
	const int radix = 10;
	std::queue<long> queues[radix];
	for(int i = 0, factor = 1; i <a.size(); factor *= radix, i++)
	{
		for(int j = 0; j < n; j++)
			queues[((a[j]/factor)%radix)].push(a[j]);
		int k = 0;
		for(int j = 0; j < radix; j++)
		{
			while(!queues[j].empty())
			{
				a[k] = queues[j].front();
				queues[j].pop();
				k++;
			}
		}
	}
}

int main()
{
	int a[] = {0,2,3,2,1};
	vector<int> v(a, a+5);

	radixSort(v, 5);
	///for test
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}
