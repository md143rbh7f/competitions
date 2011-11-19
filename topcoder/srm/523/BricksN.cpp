typedef long long ll;
#define L 55
#define MOD 1000000007
#define M( x ) ( ( x ) % MOD )

ll fill[L], ways[L][L];

struct BricksN
{
	int countStructures( int W, int H, int K )
	{
		fill[0] = 1;
		for( int w = 1; w <= W; w++ )
		for( int k = 1; k <= K && k <= w; k++ )
			fill[w] = M( fill[w] + fill[w-k] );

		for( int w = 0; w <= W; w++ )
			ways[0][w] = 1;
		for( int h = 1; h <= H; h++ )
		{
			ways[h][0] = 1;
			for( int w = 1; w <= W; w++ )
			{
				ways[h][w] = M( fill[w] * ways[h-1][w] );
				for( int k = 0; k < w; k++ )
					ways[h][w] = M( ways[h][w] + M( ways[h][w-k-1] * M( fill[k] * ways[h-1][k] ) ) );
			}
		}
		
		return ways[H][W];
	}
};
