public class Mosquitoes
{
	public int getMaximum( int[] x, int[] v, int r )
	{
		int n = x.length;
		int best = 1;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ )
		{
			int t_num = x[i] - x[j] + 2 * r;
			int t_denom = v[j] - v[i];
			if( t_denom == 0 ) continue;
			if( t_denom < 0 )
			{
				t_denom *= -1;
				t_num *= -1;
			}
			if( t_num < 0 ) continue;
			int hit = 0;
			int left = x[i] * t_denom + v[i] * t_num;
			int right = x[j] * t_denom + v[j] * t_num;
			for( int k = 0; k < n; k++ )
			{
				int test = x[k] * t_denom + v[k] * t_num;
				if( left <= test && test <= right ) hit++;
			}
			if( hit > best ) best = hit;
		}
		return best;
	}
}
