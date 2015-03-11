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

	int max = 1, pos = 0;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 1; j < s.size() - i; ++j) {
			if (s.substr(i,j).find(s[i + j]) == string::npos) {
				if (max < j +1) {
					max = j + 1;
					pos = i;
				}
			}
			else {
				break;
			}
		}
	}

	cout << pos  << " " << endl;
	return max;
}


int main() {
	string s = "aax";

	cout << s << endl;
	cout << lengthOfLongestSubstring(s) << endl;
}