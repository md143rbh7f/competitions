struct ApproximateDivision
{
	double quotient( int a, int b, int terms )
	{
		double t = 1;
		while( t < b ) t *= 2;
		double c = t - b, r = c / t, inv = 0, add = 1 / t;
		for( int i = 0; i < terms; i++ ) inv += add, add *= r;
		return a * inv;
	}
};
