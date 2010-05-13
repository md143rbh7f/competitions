import java.util.ArrayList;

public class Palindromize3
{
	public String getPalindrome( String string )
	{
		char[] s = string.toCharArray();
		ArrayList<Integer> bad = new ArrayList<Integer>();
		int n = 0;
		for( int i = 0; i < s.length/2; i++ )
		if( s[i] != s[s.length-i-1] )
		{
			bad.add(i);
			n++;
		}
		int N = 1<<n, p = 10000;
		String best = "zzzzzzzzzzzzzzzzzzzzzzzz";
		for( int i = 0; i < N; i++ )
		{
			boolean[] used = new boolean[128];
			char[] temp = new char[s.length];
			for( int j = 0; j < s.length; j++ ) temp[j] = s[j];
			for( int j = 0; j < n; j++ )
			{
				int k = bad.get(j);
				if( ((i>>j)&1)==1 ) temp[k] = temp[s.length-1-k];
				else temp[s.length-1-k] = temp[k];
				used[temp[k]] = true;
			}
			int count = 0;
			for( int j = 0; j < 128; j++ ) if( used[j] ) count++;
			String temptemp = new String(temp);
			if( count < p )
			{
				p = count;
				best = temptemp;
			}
			else if( count==p && temptemp.compareTo(best)<0 ) best = temptemp;
		}
		return best;
	}
}
