#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::min;
using std::max;

/*
 * Greedy Method:
 * basic idea:
 * i stands for the left side, j stands for the right side, k between i and j
 * capacity(i,j) = (j-i) * min([i],[j])
 * so if ([i] < [j]) then [i,k] must less then [i,j]
 *
 * 
 */

int maxArea(vector<int>& height) {
	int r = 0, i = 0, j = height.size()-1;
	while (i < j) {
		int t = (j-i) * min(height[i],height[j]);
		r = max(r,t);
		if (height[i] < height[j])
			++i;
		else
			--j;
	}
	return r;
}

int main()
{
	vector<int> d= {4,5,7,3,9};
	cout << maxArea(d) << endl;
}