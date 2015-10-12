#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

vector <int> buildnext(string pat)
{
	int plen = pat.size();
	vector <int> v(plen,0);
	for (int i = 1; i < plen; ++i) {
		for (int j = 1; j <= i; ++j) {
			if(pat.substr(0,j) == pat.substr(i+1-j,j) && j > v[i]) {
				v[i] = j;
			}
		}
	}
	return v;
}

vector <int> getnext(string pat)
{
	int plen = pat.size();
	if (1 == plen) {
		return {-1};
	}
	vector <int> next(plen);
	next[0] = -1; next[1] = 0;
	//pos stands for calculate positon, front=next[pos]
	int pos = 2, front = next[1]; 
	while (pos < plen) {
		if (pat[front] == pat[pos-1]) {
			next[pos] = next[pos-1] + 1;
			front = next[pos];
			++pos;
		} else if (front > 0) {
			front = next[front];
		} else {
			next[pos] = 0;
			pos++;
		}
	}
	return next;
}

int search(string txt, string pat)
{
	int tlen = txt.size(), plen = pat.size();
	if (plen == 0 || tlen < plen)
		return -1;
	vector <int> next = getnext(pat);
	int i = 0, j = 0;
	while(i < tlen && j < plen) {
		if (txt[i] == pat[j]) {
			++i; ++j;
		} else if (next[j] == -1) {
			++i;
		} else {
			j = next[j];
		}
	}
	if (j == plen)
		return i-j;
	else
		return -1;
}

int main()
{
	// for (auto i:getnext("abcabcd")) {
	// 	cout << i << " ";
	// }
	// cout << endl;
	cout << search("abcabcde","bcd") << endl;
}



