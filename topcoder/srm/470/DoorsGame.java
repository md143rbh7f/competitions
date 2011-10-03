public class DoorsGame
{
	public int determineOutcome( String doors, int t )
	{
		int n = doors.length(), d[] = new int[n], J = 0, G = 0;
		for( int i = 0; i < n; i++ ) d[i] = doors.charAt(i)-'A';
		for( int i = 0; i < t; i++ ) J |= 1<<d[i];
		for( int i = t; i < n; i++ ) G |= 1<<d[i];
		int C = J&G, cc = Integer.bitCount(C), cj = Integer.bitCount(J), cg = Integer.bitCount(G);
		if( cc==0 )
		{
			if( cj<=cg ) return Math.min( 2*cj-1, 16 );
			return -Math.min( 2*cg, 16 );
		}
		if( cj<cg )
		{
			if( cg-cj<cc ) return 0;
			return Math.min( 2*cj-1, 16 );
		}
		if( cj>cg )
		{
			if( cj-cg<=cc ) return 0;
			return -Math.min( 2*cg, 16 );
		}
		return 0;
	}
}
