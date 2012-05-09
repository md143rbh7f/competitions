public class WorkingRabbits
{
	public double getEfficiency( String[] profit )
	{
		int n = profit.length, tot = 0;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < i; j++ ) tot += profit[i].charAt(j) - '0';
		return 2.0 * tot / n / ( n - 1 );
	}
}
