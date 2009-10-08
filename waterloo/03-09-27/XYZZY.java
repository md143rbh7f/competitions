/*
 * Siyang Chen
 * CS 149s
 * NOT DONE!
 */

import java.io.*;
import java.util.*;

public class XYZZY
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = 1000000;
  static int MAX;

  public static void main( String[] args )
  {
    while( new XYZZY().solve() );
  }

  // number of rooms
  int n;
  // energy for each room
  int[] e;
  // adjacency lists
  int[][] out;
  // max energy value for each room
  int[] m;
  // the last time a vertex was visited in the algorithm
  int[] seen;
  // whether or not a node was updated
  boolean updated;

  boolean solve()
  {
    // read input
    n = in.nextInt();
    if( n == -1 ) return false;
    e = new int[n+1];
    out = new int[n+1][];
    for( int i = 1; i <= n; i++ )
    {
      e[i] = in.nextInt();
      out[i] = new int[ in.nextInt() ];
      for( int j = 0; j < out[i].length; j++ )
        out[i][j] = in.nextInt();
    }

    // variation of Bellman-Ford?
    seen = new int[n+1];
    m = new int[n+1];
    m[1] = 100;
    // starting condition: set 'max' to negative infinity
    for( int i = 2; i < n; i++ ) m[i] = -INF;
    // run n times
    for( int i = 0; i <= n; i++ )
    {
      updated = false;
      for( int j = 1; j <= n; j++ )
      {
        for( int k : out[j] )
        {
          // update the 'max' value if it's better than before
          if( m[j]>0 && m[j]+e[k]>0 && m[j]+e[k]>m[k] )
          {
            seen[j] = i;
            m[k] = m[j] + e[k];
            updated = true;
          }
        }
      }
      // if you didn't update anything or you reach the end, then quit
      if( !updated || m[n] > 0 ) break;
      
      // at i == n, all the vertices that were updated are just infinitely looping elements positive elements
      // thus, start a NEW search with all the ones that you just updated
      if( i == n )
      {
        for( int j = 1; j <= n; j++ )
          if( seen[j] != i )
            m[j] = -INF;
        // since infinite loop elements can reach everything, we can just make everything cost 0 energy
        for( int j = 1; j <= n; j++ )
          e[j] = 0;
        // restart the search
        i = 0;
      }
    }
    if( m[n] > 0 ) System.out.println( "winnable" );
    else System.out.println( "hopeless" );

    return true;
  }

}
