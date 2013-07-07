#include <iostream>

using namespace std;

#define iter(i,a,b,c) for(__typeof__(a) i=(a);i c(b);i++)
#define range(i,a,b) iter(i,a,b,<)
#define rep(i,n) range(i,0,n)

#define C 26*2
#define YES 1
#define NO 2

bool e[C][C];
int mem[C], id[4];

inline int code( char c, char s )
{
	return c == '0' ? -1 : 2 * ( c - 'A' ) + ( s == '+' );
}

int cycle( int i )
{
	if( mem[i] ) return mem[i];
	mem[i] = YES;
	rep(j,C) if( e[i][j] && cycle( j^1 ) == YES ) return YES;
	return mem[i] = NO;
}

int main()
{
	int n;
	cin >> n;

	string buf;
	rep(i,n)
	{
		cin >> buf;
		rep(j,4) id[j] = code( buf[2*j], buf[2*j+1] );
		range(j,id+0,id+4) range(k,j+1,id+4) if( *j != -1 && *k != -1 )
			e[*j][*k] = e[*k][*j] = true;
	}

	bool ans = false;
	rep(i,C) ans |= cycle(i) == YES;
	cout << ( ans ? "unbounded" : "bounded" ) << endl;

	return 0;
}
