#include <iostream>

using namespace std;

int n, last = -1, t, h, m, count, i, ans = 1;
char buf[50];

int main()
{
	cin >> n;
	cin.getline( buf, 50 );
	for( i = 0; i < n; i++ )
	{
		cin.getline( buf, 50 );
		m = 10*(buf[4]-'0')+buf[5]-'0';
		h = (10*(buf[1]-'0')+buf[2]-'0')%12;
		if( buf[7]=='p' ) h += 12;
		t = 60*h+m;
		if( t==last )
		{
			count++;
			if( count>10 )
			{
				count = 1;
				ans++;
			}
		}
		else count = 1;
		if( t<last ) ans++;
		last = t;
	}
	cout << ans << endl;
	return 0;
}
