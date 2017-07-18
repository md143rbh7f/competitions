#include <stdio.h>

int C, m, L, u[31], v[31], i, x, y, d, c, r[4][2][2] =
{
	{
		{ 1, 0 },
		{ 0, 1 },
	},
	{
		{ 0, -1 },
		{ 1, 0 },
	},
	{
		{ -1, 0 },
		{ 0, -1 },
	},
	{
		{ 0, 1 },
		{ -1, 0 },
	},
};
char s[31];

int main()
{
	scanf( "%d", &C );
	u[0] = 1;
	while(C--)
	{
		scanf( "%s%d", s, &m );
		for( L = 0; s[L]; L++ ) s[L] = s[L] == 'U' ? -1 : 1;
		for( i = 1; i <= L; i++ )
		{
			u[i] = u[i-1] + s[L-i] * v[i-1];
			v[i] = v[i-1] - s[L-i] * u[i-1];
		}
		x = y = d = 0;
		for( i = L; i > 0; i-- ) if( (1<<(i-1)) < m )
		{
			m = (1<<i)-m;
			x += r[d][0][0] * u[i] + r[d][0][1] * v[i];
			y += r[d][1][0] * u[i] + r[d][1][1] * v[i];
			d = ( d + s[L-i] + 4 ) % 4;
		}
		if(m)
		{
			x += r[d][0][0];
			y += r[d][1][0];
		}
		printf( "(%d,%d)\n", x, y );
	}
	return 0;
}
