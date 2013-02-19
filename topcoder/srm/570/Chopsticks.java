public class Chopsticks
{
	public int getmax( int[] lens )
	{
		int cnts[] = new int[101], ans = 0;
		for( int len : lens ) cnts[len]++;
		for( int cnt : cnts ) ans += cnt / 2;
		return ans;
	}
}
