int X1, Y1, X2, Y2, dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

bool ok( double x1, double y1, double x2, double y2 )
{
	return x1 >= X1 && x1 <= X2 && y1 >= Y1 && y1 <= Y2 && x2 >= X1 && x2 <= X2 && y2 >= Y1 && y2 <= Y2;
}

int rec( int x1, int y1, int d, int l )
{
	if( l == 1 )
	{
		if( ok( x1, y1, x1+dx[d], y1+dy[d] ) )
		{
			int c = 0;
			double x2 = x1 + 0.5*dx[d], y2 = y1 + 0.5*dy[d];
			if( ok( x2, y2, x2 + 0.5*dx[(d+3)%4], y2 + 0.5*dy[(d+3)%4] ) ) c++;
			if( ok( x2, y2, x2 + 0.5*dx[(d+5)%4], y2 + 0.5*dy[(d+5)%4] ) ) c++;
			return 1 + c*165;
		}
		return 0;
	}
	int ans = 0;
	for( int i = 0; i < l*2/3; i++ )
	{
		if( ok( x1, y1, x1+dx[d], y1+dy[d] ) ) ans++;
		x1 += dx[d], y1 += dy[d];
	}
	for( int i = 3; i <= 5; i++ ) ans += rec( x1, y1, (d+i)%4, l/3 );
	return ans;
}

struct FractalPicture
{
	double getLength( int x1, int y1, int x2, int y2 )
	{
		X1 = x1, Y1 = y1, X2 = x2, Y2 = y2;
		return rec( 0, 0, 0, 81 );
	}
};
