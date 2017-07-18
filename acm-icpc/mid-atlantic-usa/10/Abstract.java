import java.io.*;
import java.math.*;
import java.util.*;

public class Abstract
{
	public static void main( String[] args )
	{
		new Abstract().solve();
	}

	Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	char[] para = new char[80000];
	int L = 0;

	void flush( boolean end )
	{
		ArrayList<Integer> sstart = new ArrayList<Integer>(), send = new ArrayList<Integer>();
		boolean started = false;
		for( int i = 0; i < L; i++ )
		{
			if( !started && para[i]!=' ' && para[i]!='\n' )
			{
				sstart.add(i);
				started = true;
			}
			if( started && ( para[i]=='.' || para[i]=='!' || para[i]=='?' ) )
			{
				send.add(i);
				started = false;
			}
		}
		if( send.size()>=3 )
		{
			ArrayList<HashSet<String>> w = new ArrayList<HashSet<String>>();
			int ws = -1;
			for( int i = 0; i < send.size(); i++ )
			{
				w.add( new HashSet<String>() );
				for( int j = sstart.get(i); j <= send.get(i); j++ )
				{
					if( j<send.get(i) && ( ( para[j]>='a' && para[j]<='z' ) || ( para[j]>='A' && para[j]<='Z' ) )  )
					{
						if( ws==-1 ) ws = j;
					}
					else
					{
						if( ws>=0 ) w.get(i).add( new String( para, ws, j-ws ).toLowerCase() );
						ws = -1;
					}
				}
			}
			int best = 0, bestmatch = 0;
			HashSet<String> after = new HashSet<String>();
			for( int i = send.size()-1; i>=0; i-- )
			{
				int match = 0;
				for( String word : w.get(i) ) if( after.contains(word) ) match++;
				if( match>=bestmatch )
				{
					best = i;
					bestmatch = match;
				}
				after.addAll( w.get(i) );
			}
			for( int i = sstart.get(best); i <= send.get(best); i++ ) System.out.print( para[i] );
			System.out.println();
		}
		if(end) System.out.println("======");
		L = 0;
	}

	void solve()
	{
		while(true)
		{
			String l = in.nextLine();
			if( l.equals("***") )
			{
				flush(true);
				continue;
			}
			if( l.equals("******") )
			{
				flush(true);
				return;
			}
			if( l.length()>0 )
			{
				for( int i = 0; i < l.length(); i++ ) para[L++] = l.charAt(i);
				para[L++] = '\n';
			}
			else flush(false);
		}
	}
}
