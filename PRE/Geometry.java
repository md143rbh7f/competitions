	static double dist( double[] x1, double[] x2 )
	{
		double ans = 0;
		for( int i = 0; i < x1.length; i++ ) ans += (x1[i]-x2[i])*(x1[i]-x2[i]);
		return Math.sqrt(ans);
	}

	double cross( double x0, double y0, double x1, double y1 )
	{
		return x0 * y1 - x1 * y0;
	}

	bool intersects( double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3 )
	{
		double a = cross( x1 - x0, y1 - y0, x2 - x0, y2 - y0 );
		double b = cross( x1 - x0, y1 - y0, x3 - x0, y3 - y0 );
		double c = cross( x3 - x2, y3 - y2, x0 - x2, y0 - y2 );
		double d = cross( x3 - x2, y3 - y2, x1 - x2, y1 - y2 );
		return ( ( a >= 0 && b <= 0 ) || ( a <= 0 && b >= 0 ) ) && ( ( c >= 0 && d <= 0 ) || ( c <= 0 && d >= 0 ) );
	}
