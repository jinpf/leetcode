#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;

/**
  * for Roman: sepecial case: 4,9
  * s1 s2
  * if s1 >= s2 : r = s1 + s2
  * if s1 < s2 : r = s2 - s1
  * 
  */

int romanToInt(string s) {
	unordered_map <char,int> alphabet = 
		{{'I',1}, {'V',5}, {'X',10}, {'L',50}, 
		 {'C',100}, {'D',500}, {'M',1000}};

	int len = s.size(), r = 0, index = 0;
	while(index < len-1) {
		int s1 = alphabet[s[index]], s2 = alphabet[s[index+1]];
		if (s1 >= s2)
			r += s1;
		else
			r -= s1;
		++index;
	}
	r += alphabet[s[index]];
	return r;
}

string intToRoman(int num) {
	vector <string> alphabet = 
		{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
		 "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
		 "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
		 "", "M", "MM", "MMM"};

	string r = "";
	for (int i = 0; i < 4 && num != 0; ++i) {
		r = alphabet[i*10 + num%10] + r;
		num /= 10; 
	}
	return r;
}

int main()
{
	int x;
	while (cin >> x) {
		cout << intToRoman(x) << ":"  << romanToInt(intToRoman(x)) << endl;

	}
}