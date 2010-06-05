#include <iostream>

using namespace std;

int n, i, j, m, c;
double win[18][18], live[1<<18];

int main()
{
	cin >> n;
	for( i = 0; i < n; i++ ) for( j = 0; j < n; j++ ) cin >> win[i][j];
	live[(1<<n)-1] = 1;
	for( m = (1<<n)-1; m > 0; m-- )
	{
		c = 0;
		for( i = 0; i < n; i++ ) if( (m>>i)&1 ) c++;
		for( i = 0; i < n; i++ ) if( (m>>i)&1 )
		for( j = 0; j < n; j++ ) if( (m>>j)&1 )
			if( i!=j )
				live[m-(1<<i)] += live[m]*win[j][i]*2/c/(c-1);
	}
	for( i = 0; i < n; i++ ) cout << live[1<<i] << " ";
	return 0;
}
