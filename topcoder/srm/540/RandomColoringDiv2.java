public class RandomColoringDiv2
{
	public int getCount( int mr, int mg, int mb, int sr, int sg, int sb, int d1, int d2 )
	{
		int ans = 0;
		for( int r = 0; r < mr; r++ ) for( int g = 0; g < mg; g++ ) for( int b = 0; b < mb; b++ )
		if( Math.abs( r - sr ) <= d2 && Math.abs( g - sg ) <= d2 && Math.abs( b - sb ) <= d2 )
		if( Math.abs( r - sr ) >= d1 || Math.abs( g - sg ) >= d1 || Math.abs( b - sb ) >= d1 )
			ans++;
		return ans;
	}
}
