public class ANDEquation
{
	public int restoreY( int[] a )
	{
		int n = a.length;
		for( int i = 0; i < n; i++ )
		{
			int and = -1;
			for( int j = 0; j < n; j++ ) if( j != i ) and &= a[j];
			if( a[i] == and ) return a[i];
		}
		return -1;
	}
}
