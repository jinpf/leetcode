#include <iostream>

using std::cout;
using std::endl;
using std::min;

// O( log(m+n) )

int find_kth(int A[], int m, int B[], int n, int k) {
	//always assume that m is equal or smaller than n
	if (m > n) return find_kth(B, n, A, m, k);
	if (m == 0) return B[k - 1];
	if (k == 1) return min(A[0], B[0]);
	//divide k into two parts
	int ia = min(k / 2, m), ib = k - ia;
	if (A[ia - 1] < B[ib - 1])
		return find_kth(A + ia, m - ia, B, n, k - ia);
	else if (A[ia - 1] > B[ib - 1])
		return find_kth(A, m, B + ib, n - ib, k - ib);
	else
		return A[ia - 1];
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	int total = m + n;
	if (total & 0x1)
		return find_kth(A, m, B, n, total / 2 + 1);
	else
	return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2.0;
}

// O(m+n)

double findMedianSortedArrays1(int A[], int m, int B[], int n) {	
	int ka = 0 , kb = 0, i = 0, j = 0;
	for (int p = 1; p <= (m + n) / 2 + 1; ++p) {
		ka = kb;
		if (i != m && j != n) {
			if (A[i] < B[j]) {
				kb = A[i];
				++i;
			}
			else {
				kb = B[j];
				++j;
			}
		}
		else if (i == m) {
			kb = B[j];
			++j;
		}
		else {
			kb = A[i];
			++i;
		}
	}
	if ((m + n) & 0x1)
		return kb;
	else
		return (ka + kb) / 2.0;
}

void compare(int A[], int m, int B[], int n) {

	cout << findMedianSortedArrays(A,m,B,n) << " " << findMedianSortedArrays1(A,m,B,n) << endl;

}

void coutarry(int A[], int n) {
	cout << "{";
	if (n == 0)
		cout << "}";
	else {
		for (int i= 0; i < n; ++i) {
			cout << A[i] << ",";
		}
		cout << "\b}  ";
	}
}

int main() {
	int A[7][7] = {
		{},
		{0},
		{55,74},
		{2,50,63},
		{5,35,70,80},
		{2,55,56,70,79},
		{0,59,71,76,90,100}
	};

	// cout << find_kth1(A[4],4,A[5],5,5) << endl;

	for (int i = 0; i < 7; ++i ) {
		for (int j = 0; j < 7; ++j) {
			coutarry(A[i],i);
			coutarry(A[j],j);
			cout << endl;
			compare(A[i],i,A[j],j);
			cout << endl;
		}
	}

	return 0;
}