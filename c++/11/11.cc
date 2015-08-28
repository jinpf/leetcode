#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::min;

/*
 * brute force way to solve this problem O(n^2) Time Limit Exceeded
 */

int maxArea(vector<int>& height) {
	int max = 0, len = height.size();
	for (int i = 0; i < len; ++i)
		for (int j = i+1; j < len; ++j) {
			int t = (j-i) * min(height[i],height[j]);
			if (t > max)
				max = t;
		}
	return max;
}

int main()
{
	vector<int> d= {4,5,7,3,9};
	cout << maxArea(d) << endl;
}