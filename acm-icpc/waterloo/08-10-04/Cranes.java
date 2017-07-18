/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Cranes
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = Integer.MAX_VALUE;
  static int MAX =  105;
  
  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new Cranes().solve();
  }

  void solve()
  {
    int n = in.nextInt();

    // if cranes are possible
    int[] rules = new int[ MAX ];
    int numRules = 0;

    int[] x = new int[n]; int[] y = new int[n]; int[] r = new int[n];
    for( int i = 0; i < n; i++ )
    {
      // read input
      x[i] = in.nextInt(); y[i] = in.nextInt(); r[i] = in.nextInt();
      // check if it's possible with all the previous ones
      for( int j = 0; j < i; j++ )
      {
        int dx = x[i]-x[j];
        int dy = y[i]-y[j];
        if( Math.sqrt( dx*dx + dy*dy ) < r[i]+r[j] )
        {
          rules[numRules] |= 1 << j;
          rules[numRules] |= 1 << i;
          numRules++;
        }
      }
    }

    // now brute force through each of the cases
    int brute = 1 << n;
    int max = 0;
    BRUTE: for( int i = 0; i < brute; i++ )
    {
      // check rules
      for( int j = 0; j < numRules; j++ )
      {
        if( Integer.bitCount( i & rules[j] ) == 2 )
          continue BRUTE;
      }

      // else calculate area
      int a = 0;
      for( int j = 0; j < n; j++ )
        if( ( ( i >> j ) & 1 ) == 1 )
          a += r[j] * r[j];

      if( a > max ) max = a;
    }

    System.out.println( max );
  }
}
