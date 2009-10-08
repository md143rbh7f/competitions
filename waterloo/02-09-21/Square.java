/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Square
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int MAX = 20000;
  static int INF = Integer.MAX_VALUE;

  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new Square().solve();
  }

  void solve()
  {
    // num sticks
    n = in.nextInt();

    // stick lengths
    sticks = new int[n];
    int sum = 0;
    for( int i = 0; i < n; i++ )
    {
      sticks[i] = in.nextInt();
      sum += sticks[i];
    }
    // goal = total lengths / 4
    goal = sum >> 2;
    // if sum isn't a multiple of 4, return no
    if( ( goal << 2 ) != sum )
    {
      System.out.println( "no" );
      return;
    }

    // brute force solution with memoization
    seen = new boolean[ 1 << n ];
    if( search( 0, 0, 0 ) ) System.out.println( "yes" );
    else System.out.println( "no" );
  }

  // lengths of sticks
  int[] sticks;
  // memoization array
  boolean[] seen;
  int n;
  int goal;

  // memoization with brute force
  boolean search( int sum, int mask, int used )
  {
    // only test if you've not seen this case before, or if your sum is less than the goal
    if( seen[mask] || sum > goal ) return false;
    if( sum == goal ) sum = 0;
    if( sum == 0 && used == n ) return true;
    seen[mask] = true;
    for( int i = 0; i < n; i++ )
    {
      int stickMask = 1 << i;
      // if you haven't used this stick yet, try using it
      if( ( stickMask & mask ) == 0 )
        // if it works, then hooray
        if( search( sum + sticks[i], mask | stickMask, used + 1 ) )
          return true;
    }
    return false;
  }
}
