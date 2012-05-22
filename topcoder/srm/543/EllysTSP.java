public class EllysTSP
{
	public int getMax( String s )
	{
		int c = 0, v = 0;
		for( int i = 0; i < s.length(); i++ )
		{
			if( s.charAt(i) == 'C' ) c++;
			else v++;
		}
		return 2 * Math.min( c, v ) + ( c == v ? 0 : 1 );
	}
}
