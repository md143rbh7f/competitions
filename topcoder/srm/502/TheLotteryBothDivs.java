public class TheLotteryBothDivs
{
	public double find( String[] s )
	{
		int n = s.length;
		for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
		if( i != j && s[i] != null && s[j] != null && s[i].endsWith( s[j] ) )
			s[i] = null;
		int count = 0;
		for( int i = 0; i < n; i++ ) if(s[i]!=null)
		{
			int pow = 1;
			for( int j = 0; j < 9-s[i].length(); j++ ) pow *= 10;
			count += pow;
		}
		return 1.0*count/1000000000;
	}
}
