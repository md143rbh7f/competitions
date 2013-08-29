import java.util.*;

public class TwoBallGame
{
	static Scanner in = new Scanner( System.in );
	static double EPS = 1e-11;

	public static void main( String[] args )
	{
		int N = in.nextInt();
		while( N-- > 0 ) new TwoBallGame().solve();
	}

	void solve()
	{
		int n = in.nextInt();
		double pts[][] = new double[n][2];
		for( int i = 0; i < n; i++ )
		{
			pts[i][0] = in.nextDouble();
			pts[i][1] = in.nextDouble();
		}
		ArrayList<Integer> hull = convex_hull( pts ), special = new ArrayList<Integer>();
		for( int i = 0; i < hull.size(); i++ ) if( hull.get(i) < 4 ) special.add( hull.get(i) < 2 ? 0 : 1 );
		if( special.size() == 4 && ( special.get(0) == special.get(2) ) ) System.out.println( "IMPOSSIBLE" );
		else System.out.println( "POSSIBLE" );
	}

	static ArrayList<Integer> convex_hull( double[][] pts )
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
			a[i] = Math.atan2( pts[i][1]-start[1], pts[i][0]-start[0] );
			d[i] = Math.hypot( start[0] - pts[i][0], start[1] - pts[i][1] );
		}
		Arrays.sort( ptr, 0, n, new AngleComparator( a, d ) );
		ptr[n] = ptr[0];
		// check counterclockwise turning ( turn(a,b,c) > 1 )
		ArrayList<Integer> h = new ArrayList<Integer>();
		h.add(ptr[0]);
		h.add(ptr[1]);
		int last = 1;
		for( int i = 2; i <= n; i++ )
		{
			while( true )
			{
				double t = turn( pts[h.get(last-1)], pts[h.get(last)], pts[ptr[i]] );
				if( t<0 || (t*t)<EPS )
				{
					h.remove(last);
					last--;
				}
				else break;
				if( last==0 ) break;
			}
			last++;
			h.add(ptr[i]);
		}
		h.remove(last);
		// last case: if the entire thing was just a line
		if( h.size()==1 ) h.add(ptr[n-1]);
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
}
