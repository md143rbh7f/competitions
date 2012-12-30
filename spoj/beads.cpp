#include <iostream>
#include <string>

using namespace std;

int min_rot( string & s )
{
	int n = s.size(), ans = 0, cur = 1, len = 0;
	while( cur < n && ans + len + 1 < n )
	{
		if( s[ans+len] < s[(cur+len)%n] )
		{
			cur = cur + len + 1;
			len = 0;
		}
		else if( s[ans+len] > s[(cur+len)%n] )
		{
			ans = max( ans + len + 1, cur );
			cur = ans + 1;
			len = 0;
		}
		else len++;
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		cout << min_rot( s ) + 1 << endl;
	}
	return 0;
}
