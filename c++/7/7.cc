#include <iostream>
#include <limits.h>

using std::cout;
using std::cin;
using std::endl;

int reverse(int x) {
	long long result = 0;
	long long tmp;
	// attention here!
	if (x < 0)
		tmp = - (long long)x;
	else
		tmp = (long long)x;

	while (tmp) {
		result = result * 10 + tmp % 10;
		if (result > INT_MAX)
			return 0;
		tmp /= 10;
	}
	if (x > 0)
		return (int)result;
	else
		return (int)-result;
}

int main()
{
	int a;
	// cout << reverse(-2147483648) << endl;
	while(cin >> a) {
		cout << reverse(a) << endl;
	}
}