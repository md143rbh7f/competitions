import static java.lang.Math.*;

public class CorrectMultiplicationTwo
{
	long MAX_A = 1L<<10;

	long search( int a, int b, int c )
	{
		long best = 1L<<42;
		for( long A = 1; A < MAX_A; A++ )
		for( long B = c / A - 1; B <= c / A + 1; B++ )
		if( B > 0 )
			best = min( best, abs( A - a ) + abs( B - b ) + abs( A * B - c ) );
		return best;
	}

	public long getMinimum( int a, int b, int c )
	{
		return min( search( a, b, c ), search( b, a, c ) );
	}
}
