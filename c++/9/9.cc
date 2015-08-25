#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int mypow(int x) {
	int r = 1;
	for (int i = 0; i < x; ++i) {
		r *= 10;
	}
	return r;
}

bool isPalindrome(int x) {
	
	if (x < 0) 
		return false;

	int tmp = x, len = 0;
	while (tmp) {
		tmp /= 10;
		++len;
	}

	for (int i = 0; i < len/2; ++i) {
		if ( (x/mypow(i)%10) != (x/mypow(len-1-i)%10) ) {
			return false;
		}
	}
	return true;
}


int main()
{
	int a;
	while(cin >> a) {
		cout << isPalindrome(a) << endl;
		cout << endl;
	}
}