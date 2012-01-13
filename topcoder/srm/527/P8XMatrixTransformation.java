public class P8XMatrixTransformation
{
	public String solve( String[] original, String[] target )
	{
		int c1 = 0, c2 = 0;
		for( int i = 0; i < original.length; i++ ) for( int j = 0; j < original[0].length(); j++ )
		{
			if( original[i].charAt(j) == '1' ) c1++;
			if( target[i].charAt(j) == '1' ) c2++;
		}
		return c1 == c2 ? "YES" : "NO";
	}
}
