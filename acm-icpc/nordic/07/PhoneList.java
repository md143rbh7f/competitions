import java.util.*;

public class PhoneList
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		int T = in.nextInt();
		while( T-- > 0 )
		{
			Trie nums = new Trie();
			int n = in.nextInt();
			boolean ok = true;
			while( n-- > 0 )
			{
				String s = in.next();
				if( !ok ) continue;
				Trie ptr = nums;
				boolean ok2 = false;
				for( int j = 0; j < s.length(); j++ )
				{
					int c = s.charAt(j)-'0';
					if( ptr.next[c] == null )
					{
						ptr.next[c] = new Trie();
						ok2 = true;
					}
					if(ptr.end) ok = false;
					ptr = ptr.next[c];
				}
				ptr.end = true;
				ok &= ok2;
			}
			System.out.println( ok ? "YES" : "NO" );
		}
	}
}

class Trie
{
	Trie[] next = new Trie[10];
	boolean end = false;
}
