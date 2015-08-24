#include <iostream>

using std::string;
using std::cout;
using std::endl;

/**
 * to see whether a string is Palindrome
 */
bool isPalindrome(string s) {
  for (int i = 0; i <= s.size() / 2; ++i) {
  	if (s[i] != s[s.size() - 1 - i])
  		return false;
  }
  return true;
}

/**
 * Brute force: O(n^3): traverse the matrix need O(n^2), each examine need O(n)
 * this answer would have: Time Limit Exceeded
 */
string longestPalindrome(string s) {
  string longest = "";
  int maxsize = 0;
  for (int i = 0; i < s.size(); ++i) {
  	for (int j = maxsize; j <= s.size() - i; ++j) {
  		if (isPalindrome(s.substr(i, j))) {
  			maxsize = j;
  			longest = s.substr(i, j);
  		}
  	}
  }
  return longest;
}

int main () {
  string s[3] = {"abcba", "abccba", "abcbd"};
  for (int i = 0; i != 3; ++i) {
  	cout << longestPalindrome(s[i]) << endl;
  }
}