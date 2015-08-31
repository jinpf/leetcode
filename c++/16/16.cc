#include <iostream>
#include <vector>
#include <algorithm> // sort abs

using std::cout;
using std::endl;
using std::vector;

int threeSumClosest(vector<int>& nums, int target) {
	int len = nums.size(), ans = 0, min_dis = 0x7FFFFFFF;

	sort(nums.begin(),nums.end());

	for (int i = 0; i < len-2; ++i) {
		int l = i + 1, r = len - 1;
		while (l < r) {
			int sum = nums[i] + nums[l] + nums[r];
			int dis = abs(sum - target);
			if (dis < min_dis) {
				ans = sum;
				min_dis = dis; 
			}
			if (sum < target)
				++l;
			else if (sum > target)
				--r;
			else
				return target;
		}
	}

	return ans;
}

int main()
{
	vector <vector <int>> test = 
	{{-1,0,1,2,-1,-4},
	 {-1,2,1,-4},
     {1},
     {1,-1},
     {1,0,-1}};

     for (auto &i: test) {
     	// question
     	cout << "q:" << " ";
     	for (auto &q: i)
     		cout << q << " ";
     	cout << endl;

     	cout << "ans:" << threeSumClosest(i,0) << endl;
     }
}