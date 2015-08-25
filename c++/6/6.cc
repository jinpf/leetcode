#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
 * zigzag means:
 *
 *     a    g     m    0   6    12
 *     b  f h   l n    1 5 7 11 13
 *     c e  i k   o    2 4 8 10 14
 *     d    j     p    3   9    15
 *
 *
 */

string convert(string s, int numRows) 
{
	if (numRows == 1)
		return s;
    int step = numRows * 2 - 2, len = s.length();
    string rs = "";

    // first line
    for (int i = 0; i < len; i += step)
            rs += s[i];

    for (int i = 1; i < numRows - 1; ++i) {
        for (int j = 0; j <= len/step; ++j) {
        	if (j*step + i < len) {
        		rs += s[j*step + i];
        		if (j*step+step-i < len) {
        			rs += s[j*step+step-i];
        		}
        	}
        }
    }

    // last line
    for (int i = numRows - 1; i < len; i += step)
         rs += s[i];
    return rs;
}

int main()
{
	string s;
	int n;
	while (cin >> s >> n)
		cout << convert(s,n) << endl;
	return 0;
}