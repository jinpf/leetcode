#include <iostream>

using std::cout;
using std::endl;

double findMedianSortedArrays(int A[], int m, int B[], int n) {

	// make sure m <= n
	if (m > n) {
		return findMedianSortedArrays(B, n, A, m);
	}

	if (m = 0) {
		return n & 0x1 ? B[n / 2] : (B[(n - 1) / 2] + B[n / 2]) / 2.0 ;
	}

	if (A[m] < B[0]) {
		if (m == n)
			return (A[m] + B[0]) / 2.0;

		// return (m + n) & 0x1 ? B[(m + n) / 2 - m] : B[()];
	}


	int sa = 0, ea = m -1 , ma, sb = 0, eb = n - 1, mb;
	while (sa != ea || sb != eb) {
		ma = (sa + ea) / 2;
		mb = (sb + eb) / 2;
		if (A[ma] < B[mb] ) {
			sa = ma;
			eb = mb;
		}
		else {
			ea = ma;
			sb = mb;
		}
	}
}

// O(log(m + n))
int find_kth1(int A[], int m, int B[], int n, int k) {
	int ka = 0 ,i = 0, j = 0;
	for (int p = 1; p <= k; ++p) {
		if (i != m && j != n) {
			if (A[i] < B[j]) {
				ka = A[i];
				++i;
			}
			else {
				ka = B[j];
				++j;
			}
		}
		else if (i == m) {
			ka = B[k - m - 1];
			break;
		}
		else {
			ka = A[k - n - 1];
			break;
		}
	}
	return ka;
}

double findMedianSortedArrays1(int A[], int m, int B[], int n) {	
	if ((m + n) & 0x1)
		return find_kth1(A, m, B, n, (m+n)/2+1);
	else
		return (find_kth1(A, m, B, n, (m+n)/2) + find_kth1(A, m, B, n, (m+n)/2+1)) / 2.0;
}


int main() {
	int A[7] = {2,3,4,5,6,7,8};
	int B[1] = {0};

	cout << findMedianSortedArrays1(A,7,B,1) << endl;

	return 0;
}