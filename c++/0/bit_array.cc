#include <iostream>
using std::cout;
using std::endl;

/*
 * For C++ better refer to bitset
 */

/** set mask: 
 *      num=0: 0000 0001 
 *      num=1: 0000 0010
 *      num=2: 0000 0100
 *      num=3: 0000 1000 
 */
char bitmask(int num) {
	int pos = num % (sizeof(char) * 8);
	return 1 << pos;
}

/** insert num into bit array
 *      0010 0000
 *    | 0000 1101
 *      0010 1101
 */

void insert(char* a, int num) {
	int pos = num / (sizeof(char) * 8);
	a[pos] |= bitmask(num);
}

/** find num into bit array
 *      0010 0000
 *    & 0010 1101
 *      0010 0000
 */

bool find(char* a, int num) {
	int pos = num / (sizeof(char) * 8);
	return a[pos] & bitmask(num);
}

/** remove num into bit array
 *      1101 1111
 *    & 0010 1101
 *      0000 1101
 */

void remove(char* a, int num) {
	int pos = num / (sizeof(char) * 8);
	a[pos] &= ~ bitmask(num); 
}

int main()
{
	char a[100] = {0};
	insert(a,11);
	cout << find(a,11) << endl;
	remove(a,11);
	cout << find(a,11) << endl;

	return 1;
}