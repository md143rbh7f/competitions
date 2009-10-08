/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Mobile
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = Integer.MAX_VALUE;
  static int MAX;

  public static void main( String[] args )
  {
    int c = in.nextInt();
    in.nextLine();
    for( int i = 0; i < c; i++ ) new Mobile().solve();
  }

  void solve()
  {
    String line = in.nextLine();

    // solution: everything in the same level must be equal;
    //   then just evaluate what the total weight of the tree would be if everything was of that weight at that level; put this in a HashMap

    HashMap<Long,Integer> freq = new HashMap<Long,Integer>();
    // read input
    int level = 0;
    int i = 0;
    int len = line.length();
    while( i < len )
    {
      char c = line.charAt( i );
      // parse number
      if( c >= '0' && c <= '9' )
      {
        int j = i + 1;
        while( j < len && line.charAt(j) >= '0' && line.charAt(j) <= '9' ) j++;
        long num = Long.parseLong( line.substring( i, j ) ) << level;
        if( !freq.containsKey( num ) ) freq.put( num, 1 );
        else freq.put( num, freq.get( num ) + 1 );
        i = j;
      }
      else
      {
        if( c == '[' ) level++;
        else if( c == ']' ) level--;
        i++;
      }
    }

    // now find the max of the counts
    int max = 0;
    int sum = 0;
    for( long key : freq.keySet() )
    {
      int count = freq.get( key );
      sum += count;
      if( count > max ) max = count;
    }

    System.out.println( sum - max );
  }
}
