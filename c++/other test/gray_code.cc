#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;

/* 
 * gray code : 
 *
 */


void print(int *a, int len)
{
	for (int i = 0; i < len ; ++i) {
		cout << a[i] ;
	}
	cout << endl;
}

void gray(int p, int *a, int len, int tag)
{
	if (p == len) {
		print(a,len);
	} else {
		a[p] = tag;
		gray(p+1,a,len,0);
		a[p] = 1 - tag;
		gray(p+1,a,len,1);
	}
}

// void gray1(vector v, int n)

int main()
{
	int n; 
	cout<<"Please input n:\t"; 
	cin>>n; 

	int* a = new int[n]; 
	for (int i = 0; i < n; i ++) { 
		a[i] = 0; 
	}

	gray(0,a,n,0);

}