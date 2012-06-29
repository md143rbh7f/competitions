#include <set>
#include <string>
#include <vector>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

set<int> ok[2];
bool contains[8];

struct AmoebaCode
{
	int find( string s, int K )
	{
		int n = s.size(), p = 1;
		for( int i = 0; i < K; i++ ) p *= 10;
		for( int d = K; d > 1; d--, p /= 10 )
		{
			ok[0].clear();
			ok[1].clear();
			ok[0].insert(0);
			for( int I = 0; I < n; I++ )
			{
				int i = I%2;
				foreach( str, ok[i] )
				{
					int prev = ( (*str) * 10 ) % p;
					for( int j = 0; j <= K; j++ ) contains[j] = false;
					for( int j = prev; j; j /= 10 ) contains[j%10] = true;
					if( s[I] == '0' )
					{
						for( int j = 1; j <= K; j++ ) if( !contains[j] ) ok[1-i].insert( prev + j );
					}
					else if( !contains[s[I]-'0'] ) ok[1-i].insert( prev + s[I] - '0'  );
				}
				ok[i].clear();
			}
			if( !ok[n%2].empty() ) return d;
		}
		return 1;
	}
};
