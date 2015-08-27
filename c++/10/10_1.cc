#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/*
 * Dynamic Programming method: 
 * (not very straight forward to cover all the possibility, 
 *  but can record state to reduce calculation)
 * basic idea: d[i][j] stands for whether s[0:i-1] matches p[0:j-1] or not 
 * (!!!be careful: in d 0 stands for no charactor, not first charactor, 
 *   s == "" or p == ""  need to be treated specially)
 *   d[i][j] = if (p[j-1] != '*') : (s[i-1] == p[j-1] || p[j-1] == '.') && d[i-1][j-1] 
 *             if (p[j-1] == '*') : d[i][j-2] || ((s[i-1] == p[j-1]||p[j-2] == '.' ) && d[i-1][j]) 
 *             (means p[j-2] mathces 0 or more than 1 times) 
 * 
 *   then traveals the d matirx to caclulate.
 *
 */

bool isMatch(string s, string p) {
	int slen = s.size(), plen = p.size();

	vector < vector <bool> > d(slen+1,vector <bool> (plen+1,false));

	// init d matrix
	d[0][0] = true;
	// p = ""
	for (int i = 1; i <= slen; ++i)
		d[i][0] = false;
	// s = ""
	for (int j = 1; j <= plen; ++j) {
		d[0][j] = p[j-1] == '*' && d[0][j-2];
	}
	
	for (int i = 1; i <= slen; ++i)
		for (int j = 1; j <= plen; ++j) {
			if (p[j-1] != '*') {
				d[i][j] = (s[i-1] == p[j-1] || p[j-1] == '.') && d[i-1][j-1];      
			} else {
				d[i][j] = ( d[i][j-2] || ((s[i-1] == p[j-2]||p[j-2] == '.' ) && d[i-1][j]) );
			}
		}

	return d[slen][plen];
}

int main()
{
	string a,b;
	while(true) {
		cin >> a;
		cin >> b;
		cout << isMatch(a,b) << endl;
		cout << endl;
	}
}