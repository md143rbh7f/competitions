public class MissingParentheses
{
	public int countCorrections( String s )
	{
		int n = s.length(), lvl = 0, cnt = 0;
		for( int i = 0; i < n; i++ )
		{
			if( s.charAt(i) == '(' ) lvl++;
			else lvl--;
			if( lvl == -1 )
			{
				cnt++;
				lvl = 0;
			}
		}
		cnt += Math.abs( lvl );
		return cnt;
	}
}
