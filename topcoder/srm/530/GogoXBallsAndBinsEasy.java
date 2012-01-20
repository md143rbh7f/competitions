public class GogoXBallsAndBinsEasy
{
	public int solve( int[] T )
	{
		int ans = 0;
		for( int i = 0; i * 2 < T.length; i++ ) ans += T[T.length-i-1] - T[i];
		return ans;
	}
}
