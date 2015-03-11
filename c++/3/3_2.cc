#include <iostream>
#include <vector>
#include <unordered_map>

using std::string;
using std::max;
using std::unordered_map;
using std::cout;
using std::endl;

/**
 * __a____a____a__
 */

int lengthOfLongestSubstring(string s) {	
	unordered_map<char, int> charlastindex;
	int start = 0, max_len = 0;
	for (int i = 0; i != s.size(); ++i) {
		auto iter = charlastindex.find(s[i]);
		if (iter != charlastindex.end()) {
			max_len = max(i-start, max_len);
			cout << start;
			// the substr from
			start = max(iter->second + 1, start);
			cout << " " << max_len << " " << i <<endl;
		}
		charlastindex[s[i]] = i;
	}
	//if every character in string is not same
	return max((int)s.size() - start, max_len);
}


int main() {
	string s = "abcabcbb";

	cout << s << endl;
	cout << lengthOfLongestSubstring(s) << endl;
}