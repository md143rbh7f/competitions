public class DivisorInc
{
	int MAX = 100001, d[] = new int[MAX];

	public int countOperations( int n, int m )
	{
		for( int i = 0; i < MAX; i++ ) d[i] = MAX;
		d[n] = 0;
		for( int i = n; i <= m; i++ ) if( d[i] < MAX ) for( int j = 2; j * j <= i; j++ ) if( i % j == 0 )
		{
			if( i + j < MAX && d[i+j] > d[i] + 1 ) d[i+j] = d[i] + 1;
			if( i + i/j < MAX && d[i+i/j] > d[i] + 1 ) d[i+i/j] = d[i] + 1;
		}
		return d[m] < MAX ? d[m] : -1;
	}
}
