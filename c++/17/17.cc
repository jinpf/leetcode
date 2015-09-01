#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

/*
 * backtracking
 */

string getChar(char &num)
{
	switch(num)
	{
		case '1': return "1";
		case '2': return "abc";
		case '3': return "def";
		case '4': return "ghi";
		case '5': return "jkl";
		case '6': return "mno";
		case '7': return "pqrs";
		case '8': return "tuv";
		case '9': return "wxyz";
		default : return "";
	}
}

void FormLetter(string digits, string &result, vector<string> &v) {
	if (digits.size() == 0)
		v.push_back(result);
	string p = getChar(digits[0]);
	for (int i = 0; i < p.size(); ++i) {
		string tmp = result + p[i];
		FormLetter(digits.substr(1), tmp, v);
	}
}

vector<string> letterCombinations(string digits) {
	string r = "";
	vector<string> v;
	// fit leetcode test ...
	if (digits.size() == 0)
		return v;
	FormLetter(digits,r,v);
	return v;
}

int main()
{
	string a = "23";
	for (auto i: letterCombinations(a))
		cout << i << endl;
}