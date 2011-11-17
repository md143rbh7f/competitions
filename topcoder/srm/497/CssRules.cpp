#include <map>
#include <string>
#include <vector>

using namespace std;

#define MAX 80
#define NT 3
#define NC 8
#define OVER_NINE_THOUSAND 9001

string colours[] = { "", "black", "blue", "gray", "green", "red", "white", "yellow" };

map<string,int> colourM;
vector<int> g[MAX];
int p[MAX], colour[MAX], mem[MAX][8][8][8];
char tag[MAX];
bool seen[MAX];

int rec( int x, int a, int b, int c )
{
	int & ret = mem[x][a][b][c];
	if( ret > -1 ) return ret;
	seen[x] = true;
	ret = OVER_NINE_THOUSAND;
	if( g[x].size() )
	for( int d = 0; d < NC; d++ )
	for( int e = 0; e < NC; e++ )
	for( int f = 0; f < NC; f++ )
	{
		int sum = ( d > 0 ) + ( e > 0 ) + ( f > 0 );
		for( int i = 0; i < g[x].size(); i++ ) sum += rec( g[x][i], d ? d : a, e ? e : b, f ? f : c );
		if( sum < ret ) ret = sum;
	}
	else ret = 0;
	switch( tag[x] )
	{
		case 'b': if( a != colour[x] ) ret++; break;
		case 'u': if( b != colour[x] ) ret++; break;
		case 'i': if( c != colour[x] ) ret++; break;
	}
	return ret;
}

struct CssRules
{
	int getMinimalCssRuleCount( vector<string> xhtml )
	{
		for( int i = 0; i < NC; i++ ) colourM[colours[i]] = i;
		for( int i = 0; i < MAX; i++ )
		for( int j = 0; j < NC; j++ )
		for( int k = 0; k < NC; k++ )
		for( int l = 0; l < NC; l++ )
			mem[i][j][k][l] = -1;

		string s = "";
		for( int i = 0; i < xhtml.size(); i++ ) s += xhtml[i];
		int ptr = -1, a = 0, n = 0;
		while( a < s.size() )
		{
			if( s[a+1]=='/' ) a += 4, ptr = p[ptr];
			else
			{
				int i = a;
				while( s[i] != ':' ) i++;
				int j = i;
				while( s[j] != '\'' ) j++;
				tag[n] = s[a+1];
				colour[n] = colourM[s.substr(i+1,j-i-1)];
				p[n] = ptr;
				if( ptr > -1 ) g[ptr].push_back(n);
				ptr = n;
				n++;
				a = j+2;
			}
		}
		int ans = 0;
		for( int i = 0; i < n; i++ ) if( !seen[i] ) ans += rec(i,0,0,0);
		return ans;
	}
};
