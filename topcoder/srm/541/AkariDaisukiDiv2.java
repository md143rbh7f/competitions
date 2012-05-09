public class AkariDaisukiDiv2
{
	public int countTuples( String s )
	{
		int ans = 0;
		for( int i = 1; i + 2 < s.length(); i++ )
		for( int j = i + 2; j + 1 < s.length(); j++ )
		for( int k = 1; i + k < j && j + k < s.length(); k++ )
		if( s.substring( i, i + k ).equals( s.substring( j, j + k ) ) )
			ans++;
		return ans;
	}
}
