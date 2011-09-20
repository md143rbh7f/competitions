public class BinaryCards
{
	public long largestNumber( long a, long b )
	{
		int max = 0;
		for( max = 62; max > 0; max-- ) if( ( ( b >> max ) & 1 ) == 1 && ( ( a >> max ) & 1 ) == 0 ) break;
		return b | ( ( 1L << max ) - 1 );
	}
}
