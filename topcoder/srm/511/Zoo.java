public class Zoo
{
	public long theCount( int[] h )
	{
		int n = h.length, cnt[] = new int[41];
		for( int i = 0; i < n; i++ ) cnt[h[i]]++;
		int x = 0;
		while( x <= 40 && cnt[x] == 2 ) x++;
		int y = x;
		while( y <= 40 && cnt[y] == 1 ) y++;
		for( int z = y; z <= 40; z++ ) if( cnt[z] > 0 ) return 0;
		return 1l << ( x + ( y > x ? 1 : 0 ) );
	}
}
