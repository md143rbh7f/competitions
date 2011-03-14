public class Inequalities
{
	public int maximumSubset( String[] ineq )
	{
		int n = ineq.length, ans = 0, x[] = new int[n];
		for( int i = 0; i < n; i++ ) x[i] = 2*Integer.parseInt( ineq[i].split(" ")[2] );
		for( int i = -1; i <= 2001; i++ )
		{
			int res = 0;
			for( int j = 0; j < n; j++ ) switch( ineq[j].charAt(2) )
			{
				case '<':
					if( ineq[j].charAt(3) == ' ' && i < x[j] ) res++;
					if( ineq[j].charAt(3) == '=' && i <= x[j] ) res++;
					break;
				case '=':
					if( i == x[j] ) res++;
					break;
				case '>':
					if( ineq[j].charAt(3) == ' ' && i > x[j] ) res++;
					if( ineq[j].charAt(3) == '=' && i >= x[j] ) res++;
					break;
			}
			ans = res > ans ? res : ans;
		}
		return ans;
	}
}
