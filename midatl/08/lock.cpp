#include <iostream>

using namespace std;

int main()
{
	while(1)
	{
		int n, t1, t2, t3;
		cin >> n >> t1 >> t2 >> t3;
		if( !n ) break;
		cout << 4 * n - 1 + ( ( t2 - t1 + n ) % n ) + ( ( t2 - t3 + n ) % n ) << endl;
	}
	return 0;
}
