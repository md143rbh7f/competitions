import java.util.*;

public class Dota
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		HashMap<String,Integer> id = new HashMap<String,Integer>();
		LinkedList<String> sorted = new LinkedList<String>();
		String[] name = new String[100];
		int[][] dep = new int[50][50], have = new int[100][100];
		int k = in.nextInt(), n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
		for( int i = 0; i < n; i++ )
		{
			name[i] = in.next();
			id.put( name[i], i );
			sorted.add( name[i] );
		}
		in.nextLine();
		for( int i = 0; i < m; i++ )
		{
			String[] l = in.nextLine().split( " " );
			name[i+n] = l[0].substring( 0, l[0].length()-1 );
			sorted.add( name[i+n] );
			id.put( name[i+n], i+n );
			for( int j = 1; j < l.length; j += 2 )
			{
				String x = j+1 == l.length-1 ? l[j+1] : l[j+1].substring(0,l[j+1].length()-1);
				dep[i][id.get(l[j])] = Integer.parseInt(x);
			}
		}
		Collections.sort( sorted );
		for( int i = 0; i < q; i++ )
		{
			int p = in.nextInt(), item = id.get( in.next() );
			p--;
			have[p][item]++;
			for( int j = 0; j < m; j++ )
			{
				boolean ok = true;
				for( int l = 0; l < n; l++ ) if( have[p][l] < dep[j][l] ) ok = false;
				if( ok )
				{
					for( int l = 0; l < n; l++ ) have[p][l] -= dep[j][l];
					have[p][j+n]++;
				}
			}
		}
		for( int i = 0; i < k; i++ )
		{
			int tot = 0;
			for( int j = 0; j < n+m; j++ ) if( have[i][j] > 0 ) tot++;
			System.out.println( tot );
			for( String s : sorted )
			{
				int inum = id.get(s);
				if( have[i][inum] > 0 ) System.out.printf( "%s %d\n", s, have[i][inum] );
			}
		}
	}
}
