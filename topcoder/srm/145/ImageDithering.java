public class ImageDithering
{
	public int count( String dithered, String[] screen )
	{
		int ans = 0;
		for( String s : screen ) for( int i = 0; i < s.length(); i++ ) if( dithered.indexOf( s.charAt(i) ) != -1 ) ans++;
		return ans;
	}
}
