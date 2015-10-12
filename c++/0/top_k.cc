#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void swap(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

/**
  * use heap, build heap : O(nlogn), each node [1..n-1] use pop_up(logn)
  * get the least num from top [0], then put [n-i] in the heap top [0], use sink(logn)
  * loop k times for top k  
  */

vector<int> GetTopK(vector<int> input, int k) {
	int len = input.size();
	if (len == 0 || k == 0 || len < k)
		return {};
	if (len == 1)
		return input;

	for (int i = 1; i < len; ++i) {
		int k = i;
		while (k != 0) {
			if (input[(k-1)/2] < input[k]) {
				swap(input[(k-1)/2],input[k]);
				k = (k-1)/2;
			} else {
				break;
			}
		}
	}

	vector <int> result;
	result.push_back(input[0]);

	for (int i = 1; i < k; ++i) {
		input[0] = input[len-i];
		int k = 0;
		while (2*k+1 < len-i) {
			int tmp = 2*k + 1;
			if (tmp + 1 < len - i && input[tmp] < input [tmp+1])
				++tmp;
			if (input[tmp] > input[k]) {
				swap(input[tmp],input[k]);
				k = tmp;
			} else {
				break;
			}
		}
		result.push_back(input[0]);
	}
	return result;
}

int main()
{
	vector <int> array = {-2,-8,-1,-5,-9};
	for(auto i : GetTopK(array,3)) {
		cout << i << " ";
	}
	cout << endl;
}