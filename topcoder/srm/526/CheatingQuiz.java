public class CheatingQuiz
{
	public int[] howMany( String answers )
	{
		int n = answers.length(), ans[] = new int[n];
		boolean[] ok = new boolean[3];
		for( int i = n-1; i >= 0; i-- )
		{
			ok[answers.charAt(i)-'A'] = true;
			for( int j = 0; j < 3; j++ ) if( ok[j] ) ans[i]++;
		}
		return ans;
	}
}
