/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Wifi
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = Integer.MAX_VALUE;
  static int MAX = 1 << 20;

  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new Wifi().solve();
  }

  // number of routers, houses
  int n, m;
  int[] pos;
  void solve()
  {
    n = in.nextInt(); m = in.nextInt();

    pos = new int[m];
    for( int i = 0; i < m; i++ ) pos[i] = in.nextInt();
    Arrays.sort( pos );

    // binary search
    int result = MAX; int jump = MAX;
    while( jump != 0 )
    {
      if( works( result - jump ) ) result -= jump;
      jump >>= 1;
    }

    System.out.println( ( result >> 1 ) + "." + ( ( result & 1 ) == 1 ? "5" : "0" ) );
  }

  boolean works( int dist )
  {
    if( dist < 0 ) return false;
    // just place things at the specified interval
    int r = n;
    int last = pos[0];
    for( int i = 1; i < m; i++ )
    {
      if( pos[i] - last > dist )
      {
        if( --r == 0 ) return false;
        last = pos[i];
      }
    }
    return true;
  }
}
