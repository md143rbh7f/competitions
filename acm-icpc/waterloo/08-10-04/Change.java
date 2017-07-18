/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Change
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int MAX = 20000;
  static int INF = Integer.MAX_VALUE;

  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new Change().solve();
  }

  void solve()
  {
    int goal = in.nextInt();
    int n = in.nextInt();

    int[] bills = new int[n];
    for( int i = 0; i < n; i++ ) bills[i] = in.nextInt();

    // DP knapsack solution
    int[] min = new int[ MAX ];
    for( int i = 0; i < MAX; i++ ) min[i] = INF;
    min[0] = 0;
    for( int i = 0; i < n; i++ )
    {
      int bill = bills[i];
      for( int j = MAX - 1 - bill; j >= 0; j-- )
        if( min[j] < INF )
          min[j+bill] = ( min[j+bill] < min[j]+1 ? min[j+bill] : min[j]+1 );
    }

    for( int i = goal; i < MAX; i++ )
    {
      if( min[i] < INF )
      {
        System.out.println( i + " " + min[i] );
        break;
      }
    }
  }
}
