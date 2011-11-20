#include <cstdio>

using namespace std;

#define B 505
#define C 2505

int b, c, index[B][C], tmp;

int main()
{
	for( int case_num = 1; ; case_num++ )
	{
		scanf( "%d%d", &b, &c );
		if( !b && !c ) break;
		for( int i = 0; i < b; i++ ) for( int j = 0; j < c; j++ )
		{
			scanf( "%d", &tmp );
			index[i][tmp] = j;
		}
		
		int winner = 0;
		bool tie = false;
		for( int j = 1; j < c; j++ )
		{
			int wins = 0;
			for( int i = 0; i < b; i++ ) if( index[i][winner] < index[i][j] ) wins++;
			if( 2 * wins < b )
			{
				winner = j;
				tie = false;
			}
			else if( 2 * wins == b ) tie = true;
		}

		if( tie )
		{
			printf( "Case %d: No Condorcet winner\n", case_num );
			continue;
		}

		bool ok = true;
		for( int j = 0; j < c; j++ ) if( j != winner )
		{
			int wins = 0;
			for( int i = 0; i < b; i++ ) if( index[i][winner] < index[i][j] ) wins++;
			if( 2 * wins <= b )
			{
				ok = false;
				break;
			}
		}
		
		if( !ok ) printf( "Case %d: No Condorcet winner\n", case_num );
		else printf( "Case %d: %d\n", case_num, winner );
	}
	return 0;
}
