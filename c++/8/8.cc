#include <iostream>
#include <limits.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int myAtoi(string str) {
	long long result = 0;
	bool sign = true;
	bool valid = false;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == ' ' && !valid)
			continue;
		else if (str[i] == '+' && !valid) {
			sign = true;
			valid = true;
		}
		else if (str[i] == '-' && !valid) {
			sign = false;
			valid = true;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			result = result * 10 + (str[i] - '0');
			valid = true;
			if (result > INT_MAX)
				break;
		}
		else
			break;
	}
	if (!sign) 
		result = -result;
	if (result > INT_MAX)
		return INT_MAX;
	if (result < INT_MIN)
		return INT_MIN;
	return (int) result;
}

int main()
{
	string s;
	while(cin >> s) {
		cout << myAtoi(s) << endl;
		cout << endl;
	}
}