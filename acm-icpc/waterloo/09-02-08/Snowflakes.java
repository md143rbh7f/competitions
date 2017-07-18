/*
 * Siyang Chen
 * CS 149s
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Scanner;

public class Snowflakes
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = 0x3fffffff;
  static int MAX;

  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new Snowflakes().solve();
  }

  void solve()
  {
    int n = in.nextInt();

    // seen numbers
    HashSet<Integer> seen = new HashSet<Integer>();
    // max so far
    int max = 0;
    // start of current sequence
    int start = 0;

    // read sequence
    int[] seq = new int[n];
    for( int i = 0; i < n; i++ ) seq[i] = in.nextInt();
    for( int i = 0; i < n; i++ )
    {
      while( seen.contains( seq[i] ) ) seen.remove( seq[start++] );
      int len = i - start + 1;
      if( len > max ) max = len;
      seen.add( seq[i] );
    }

    System.out.println( max );
  }
}
