#include <algorithm>
#include <iostream>

using namespace std;

char p[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int main()
{
	for( int i = 1; i < 1000000; i++ ) next_permutation( p, p+10 );
	cout << p << endl;
	return 0;
}
