#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
 * just compare by bit
 */

string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0)
		return "";
	string r = "";
	for (int p = 0; p < strs[0].size(); ++p) {
		char t = strs[0][p];
		for (int l = 1; l < strs.size(); ++l) {
			if (p == strs[l].size() || strs[l][p] != t) {
				return r;
			}
		}
		r += t;
	}
	return r;
}

int main()
{
	vector <string> strs = {"abc","abcde","abcd"};
	cout << longestCommonPrefix(strs) << endl;
}