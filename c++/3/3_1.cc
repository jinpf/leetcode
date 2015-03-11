#include <iostream>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;


int lengthOfLongestSubstring(string s) {
	if (s.size() == 0) {
		return 0;
	}

	int max = 1, start = 0;

	for (int i = start; i < s.size(); ++i) {
		for (int j = 1; j < s.size() - i; ++j) {
			int pos = s.substr(i,j).find(s[i + j]);
			if (pos == -1) {
				if (max < j +1) {
					max = j + 1;
				}
			}
			else {
				start = pos + 1;
				break;
			}
		}
	}

	return max;
}


int main() {
	string s = "abcabcbb";

	cout << s << endl;
	cout << lengthOfLongestSubstring(s) << endl;
}