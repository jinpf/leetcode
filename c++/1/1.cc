#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

/**
 *the basic idea for finding the target, use two level loop
 *using this methord would have: Time Limit Exceeded!
 */

vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> result;
	for (auto item1 = numbers.begin(); item1 != numbers.end() - 1; ++item1) {
		for (auto item2 = item1 + 1; item2 != numbers.end(); ++item2) {
			if (*item1 + *item2 == target) {
				result.push_back(item1 - numbers.begin() + 1);
				result.push_back(item2 - numbers.begin() + 1);
				return result;
			}
		}
	}
}

int main() {
	vector<int> numbers{2, 7, 11, 15};
	int target = 9;
	vector<int> result = twoSum(numbers, target);
	cout << result[0] << " " << result[1] << endl;
}