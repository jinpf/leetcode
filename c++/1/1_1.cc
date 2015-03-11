#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

/**
 * use hashmap, C++ type : unordered_map, to keep the index-value pair
 * to make the search faster
 */

vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> result;
	unordered_map<int, int> indexmap;
	for (int i = 0; i != numbers.size(); ++i) {
		indexmap[numbers[i]] = i;
	}

	for (int i = 0; i != numbers.size(); ++i) {
		int gap = target - numbers[i];
		if (indexmap.find(gap) != indexmap.end() && indexmap[gap] > i) {
			result.push_back(i + 1);
			result.push_back(indexmap[gap] + 1);
			return result;
		}
	}
}

int main() {
	vector<int> numbers{2, 7, 11, 15};
	int target = 9;
	vector<int> result = twoSum(numbers, target);
	cout << result[0] << " " << result[1] << endl;
}