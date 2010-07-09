#include <cstdio>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int T, N;

int main()
{
        scanf( "%d", &T );
        rep(i,T)
        {
                scanf( "%d", &N );
                if( N==1 ) printf( "0\n" );
                else printf( "%d\n", N-2 );
        }
        return 0;
}
