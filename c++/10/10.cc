#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
 * 
 */

bool isMatch1(string s, string p) {
	int slen = s.size(), plen = p.size();

	int i = 0, j = 0;
	while(i < slen && j < plen) {
		if (p[j+1] == '*') {
			//s:  s1(i) s2 s3 s4
			//p:  p1(j) *  p3 p4 
			if (p[j] == '.' || s[i] == p[j]) {
				return ( isMatch1(s.substr(i),p.substr(j+2)) || isMatch1(s.substr(i+1),p.substr(j)) );
			}
			else //(s[i] != p[j])
				j += 2;
		} else {
			if (s[i] == p[j] || p[j] == '.') {
				++i;
				++j;
			} else {
				return false;
			}
		}
	}

	if (j == plen) {
		return i == slen;
	} else if ( j <= plen -2 && p[j+1] == '*') {
		if (plen-2 == j) 
			return true;
		else
			return isMatch1("",p.substr(j+2));
	} else {
		return false;
	}
}

// a better summarize
bool isMatch2(string s, string p) {
	if (p.empty())    return s.empty();
    if ('*' == p[1])
 		//s:  s1(i) s2 s3 s4
		//p:  p1(j) *  p3 p4 
       return (isMatch2(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch2(s.substr(1), p));
    else
       return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch2(s.substr(1), p.substr(1));
}

int main()
{
	string a,b;
	while(true) {
		cin >> a;
		cin >> b;
		cout << isMatch1(a,b) << endl;
		cout << isMatch2(a,b) << endl;
		cout << endl;
	}
}