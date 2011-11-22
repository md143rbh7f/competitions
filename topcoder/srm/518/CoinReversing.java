public class CoinReversing
{
	public double expectedHeads( int n, int[] a )
	{
		double heads = n;
		for( int i = 0; i < a.length; i++ )
			heads = heads * ( n - a[i] ) / n + ( n - heads ) * a[i] / n;
		return heads;
	}
}
