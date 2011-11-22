public class TwiceString
{
	public String getShortest( String s )
	{
		String ans = s;
		int i = 1;
		for( ; i < s.length(); i++ )
		{
			boolean ok = true;
			for( int j = 0; i + j < s.length(); j++ ) if( s.charAt(i+j) != s.charAt(j) )
			{
				ok = false;
				break;
			}
			if( ok ) break;
		}
		ans += s.substring( s.length() - i );
		return ans;
	}
}
