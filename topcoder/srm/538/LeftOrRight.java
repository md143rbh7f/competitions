public class LeftOrRight
{
	public int maxDistance( String program )
	{
		int q = 0, x = 0, ans = 0;
		for( int i = 0; i < program.length(); i++ )
		{
			switch( program.charAt(i) )
			{
				case 'L': x++; break;
				case 'R': x--; break;
				case '?': q++; break;
			}
			ans = Math.max( ans, Math.max( Math.abs( x - q ), x + q ) );
		}
		return ans;
	}
}
