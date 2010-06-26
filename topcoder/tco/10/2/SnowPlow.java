public class SnowPlow
{
	boolean[] seen, hasRoad;
	int n;
	String[] g;

	public int solve( String[] roads )
	{
		n = roads.length;
		seen = new boolean[n];
		g = roads;
		search(0);
		hasRoad = new boolean[n];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) if( g[i].charAt(j)>'0' ) hasRoad[i] = hasRoad[j] = true;
		int c = 0;
		for( int i = 0; i < n; i++  ) if( hasRoad[i] ) c++;
		int can = 0;
		for( int i = 0; i < n; i++ ) if( seen[i] ) can++;
		if( can<c ) return -1;
		int ans = 0;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) ans += g[i].charAt(j)-'0';
		return ans;
	}

	void search( int i )
	{
		if( seen[i] ) return;
		seen[i] = true;
		for( int j = 0; j < n; j++ ) if( g[i].charAt(j)>'0' ) search(j);
	}
}
