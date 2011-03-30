#define FNORD 1e23
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

double lo[51][51], hi[51][51];

struct FoxPlayingGame
{
	double theMax( int na, int nb, int para, int parb )
	{
		double sa = 0.001*para, sb = 0.001*parb;
		for( int a = 1; a <= na; a++ ) for( int b = 0; b <= nb; b++ )
		{
			lo[a][b] = min( lo[a-1][b] + sa, b ? min( lo[a][b-1] * sb, hi[a][b-1] * sb ) : FNORD );
			hi[a][b] = max( hi[a-1][b] + sa, b ? max( hi[a][b-1] * sb, lo[a][b-1] * sb ) : -FNORD );
		}
		return hi[na][nb];
	}
};
