public class MinCostPalindrome
{
	public int getMinimum( String s, int oc, int xc )
	{
		int l = 0, r = s.length()-1, ans = 0;
		while( l < r )
		{
			if( s.charAt(l) == '?' && s.charAt(r) == '?' ) ans += 2 * Math.min( oc, xc );
			else if( s.charAt(l) == '?' && s.charAt(r) == 'x' ) ans += xc;
			else if( s.charAt(l) == '?' && s.charAt(r) == 'o' ) ans += oc;
			else if( s.charAt(l) == 'x' && s.charAt(r) == '?' ) ans += xc;
			else if( s.charAt(l) == 'o' && s.charAt(r) == '?' ) ans += oc;
			else if( s.charAt(l) != s.charAt(r) ) return -1;
			l++;
			r--;
		}
		return ans;
	}
}
