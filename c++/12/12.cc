#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string intToRoman(int num) {
	vector <string> alphabet= 
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
		cout << intToRoman(x) << endl;
	}
}