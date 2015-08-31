#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;


/*
 * 3 sum 0
 *
 * normal brute force way would cost O(n^3).
 * two pointer:
 * sort the nums (nlogn) and then traverse by 1 number
 * adjust the other 2 number to fet the target 0 from 
 * 2 side: O(n*n)
 */


vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ans;
	int len = nums.size();
	if (len < 3)
		return ans;

	sort(nums.begin(),nums.end());

	for (int i = 0; i < len-2;) {
		int l = i + 1, r = len - 1;
		while (l < r) {
			if (nums[i] + nums[l] + nums[r] < 0) {
				++l;
			} else if (nums[i] + nums[l] + nums[r] > 0) {
				--r;
			} else {
				ans.push_back({nums[i],nums[l],nums[r]});
				++l;
				--r;
				// avoid duplicate
				while (l < r && nums[l] == nums[l-1])
					++l;
				while (l < r && nums[r] == nums[r+1])
					--r;
			}
		}
		++i;
		while (i < len-2 && nums[i] == nums[i-1])
			++i;
	}

	return ans;
}

int main()
{
	vector <vector <int>> test = 
	{{-1,0,1,2,-1,-4},
     {1},
     {1,-1},
     {1,0,-1}};

     for (auto &i: test) {
     	// question
     	cout << "q:" << " ";
     	for (auto &q: i)
     		cout << q << " ";
     	cout << endl;

     	// answer
     	for (auto &j: threeSum(i)) {
     		for (auto &k: j)
     			cout << k << " ";
     		cout << endl;
     	}
     	cout << endl;
     }
}
