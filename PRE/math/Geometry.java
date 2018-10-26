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

	boolean intersects( double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3 )
	{
		double a = cross( x1 - x0, y1 - y0, x2 - x0, y2 - y0 );
		double b = cross( x1 - x0, y1 - y0, x3 - x0, y3 - y0 );
		double c = cross( x3 - x2, y3 - y2, x0 - x2, y0 - y2 );
		double d = cross( x3 - x2, y3 - y2, x1 - x2, y1 - y2 );
		return ( ( a >= 0 && b <= 0 ) || ( a <= 0 && b >= 0 ) ) && ( ( c >= 0 && d <= 0 ) || ( c <= 0 && d >= 0 ) );
	}

	/*
		implements Graham scan for a set of points;
		outputs points on convex hull in counterclockwise order,
		starting with the point in the leftmost, lowest point, e.g.,
		the point with lowest y coord, then lowest x coord
	*/

	static ArrayList<double[]> convex_hull( double[][] pts )
	{
		int n = pts.length;
		// find starting pt
		double[] start = pts[0];
		for( int i = 0; i < n; i++ )
			if( (pts[i][1]<start[1]) || (pts[i][1]==start[1]&&pts[i][0]<start[0]) )
				start = pts[i];
		// sort by angle, then by distance, against starting point
		Integer[] ptr = new Integer[n+1];
		for( int i = 0; i < n; i++ ) ptr[i] = i;
		double[] a = new double[n], d = new double[n];
		for( int i = 0; i < n; i++ )
		{
			a[i] = Math.atan2( pts[i][1] - start[1], pts[i][0] - start[0] );
			d[i] = Math.hypot( start[0] - pts[i][0], start[1] - pts[i][1] );
		}
		Arrays.sort( ptr, 0, n, new AngleComparator( a, d ) );
		ptr[n] = ptr[0];
		// check counterclockwise turning ( turn(a,b,c) > 1 )
		ArrayList<double[]> h = new ArrayList<double[]>();
		h.add(pts[ptr[0]]);
		h.add(pts[ptr[1]]);
		int last = 1;
		for( int i = 2; i <= n; i++ )
		{
			while( true )
			{
				double t = turn( h.get(last-1), h.get(last), pts[ptr[i]] );
				if( t<0 || (t*t)<EPS )
				{
					h.remove(last);
					last--;
				}
				else break;
				if( last==0 ) break;
			}
			last++;
			h.add(pts[ptr[i]]);
		}
		h.remove(last);
		// last case: if the entire thing was just a line
		if( h.size()==1 ) h.add(pts[ptr[n-1]]);
		return h;
	}

	static class AngleComparator implements Comparator<Integer>
	{
		double[] a, d;
		AngleComparator( double[] _a, double[] _d )
		{ a = _a; d = _d; }
		public int compare( Integer x, Integer y )
		{
			if( a[x] > a[y] ) return 1;
			if( a[x] < a[y] ) return -1;
			if( d[x] > d[y] ) return 1;
			if( d[x] < d[y] ) return -1;
			return 0;
		}
	}

	static double turn( double[] a, double[] b, double[] c )
	{ return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]); }


/*
	Calculates the area and centroid of the polygon given by x, y.
*/

	static double polygon_area( double[] x, double[] y )
	{
		double a = 0;
		for( int i = 1; i < x.length; i++ ) a += x[i-1]*y[i] - x[i]*y[i-1];
		a += x[x.length-1]*y[0] - x[0]*y[x.length-1];
		a /= 2;
		if( a < 0 ) a = -a;
		return a;
	}

	static double[] polygon_area_centroid( double[] x, double[] y )
	{
		double[] a = new double[3];
		int n = x.length;
		double cross;
		for( int i = 1; i < x.length; i++ )
		{
			cross = x[i-1]*y[i] - x[i]*y[i-1];
			a[0] += cross;
			a[1] += cross*(x[i-1]+x[i]); a[2] += cross*(y[i-1]+y[i]);
		}
		cross = x[n-1]*y[0] - x[0]*y[n-1];
		a[0] += cross;
		a[0] /= 2;
		if( a[0] < 0 ) a[0] *= -1;
		a[1] += cross*(x[n]+x[0]); a[2] += cross*(y[n]+y[0]);
		a[1] /= 6*a[0]; a[2] /= 6*a[0];

		return a;
	}
