#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <utility>

using namespace std;

#define mp(a,b) make_pair((a),(b))

char buf[101];
int T, n;
map< pair< char, char >, char > combine;
map< char, vector< char > > oppose;
map< char, int > cnt;
vector< char > stack;

int main()
{
	scanf( "%d", &T );
	for( int t = 1; t <= T; t++ )
	{
		combine.clear();
		scanf( "%d", &n );
		while(n--)
		{
			scanf( "%s", buf );
			combine[mp(buf[0],buf[1])] = combine[mp(buf[1],buf[0])] = buf[2];
		}
		scanf( "%d", &n );
		oppose.clear();
		while(n--)
		{
			scanf( "%s", buf );
			oppose[buf[0]].push_back(buf[1]);
			oppose[buf[1]].push_back(buf[0]);
		}
		scanf( "%d%s", &n, buf );
		stack.clear();
		cnt.clear();
		for( int i = 0; i < n; i++ )
		{
			char c = buf[i];
			if(stack.size())
			{
				char p = stack[stack.size()-1];
				if( combine.count(mp(p,c)) )
				{
					cnt[p]--;
					stack[stack.size()-1] = combine[mp(p,c)];
					cnt[combine[mp(p,c)]]++;
				}
				else
				{
					bool ok = true;
					for( int j = 0; j < oppose[c].size(); j++ )
					if( cnt[oppose[c][j]] )
					{
						cnt.clear();
						stack.clear();
						ok = false;
						break;
					}
					if(ok)
					{
						stack.push_back(c);
						cnt[c]++;
					}
				}
			}
			else
			{
				stack.push_back(c);
				cnt[c]++;
			}
		}
		printf( "Case #%d: [", t );
		if(stack.size()) printf( "%c", stack[0] );
		for( int i = 1; i < stack.size(); i++ ) printf( ", %c", stack[i] );
		printf( "]\n" );
	}
	return 0;
}
