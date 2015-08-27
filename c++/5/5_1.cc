#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

/**
 * dynamic programming method:
 * basic idea: if d[i][j] is Palindromic, then s[i]=s[j] and d[i+1][j-1] is Palindromic
 *
 * then traverse the d matrix to caculate d[i][j] to see whether it`s Palindromic
 * cost: O(n^2)
 *
 * traverse by the distance between i and j, if you want to know d[3][8], you need d[4][7]
 * distance lower then 2 must be known, d[3][3] = 1, d[3][4] ? 
 */

string longestPalindrome(string s) {
  int len = s.size();
  vector < vector<bool> > d(len, vector<bool>(len, false));
  int mstart = 0;
  int mlen = 1;

  for (int i = 0; i < len; ++i) {
  	d[i][i] = true;
  }

  for (int i = 0; i < len -1; ++i ) {
  	if (s[i] == s[i+1]) {
  		d[i][i+1] = true;
  		if (mlen < 2) {
  			mlen = 2;
  			mstart = i;
  		}
  	}
  }

  for (int l = 2; l < len; ++l) {
  	for (int i = 0; i < len-l; ++i) {
  		// d[i][i+l] : d[i+1][i+l-1] && s[i] == s[i+l]
  		if ((s[i] == s[i+l]) && (d[i+1][i+l-1])) {
  			d[i][i+l] = true;
  			if (mlen < l+1) {
  				mlen = l+1;
  				mstart = i;
  			}
  		}
  	}
  }

  return s.substr(mstart,mlen);

}

int main () {
  string s[3] = {"abcba", "abccba", "abcbd"};
  for (int i = 0; i != 3; ++i) {
  	cout << longestPalindrome(s[i]) << endl;
  }
}