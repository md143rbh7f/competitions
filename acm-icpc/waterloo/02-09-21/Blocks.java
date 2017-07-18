/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Blocks
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = Integer.MAX_VALUE;
  static int MAX;

  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new Blocks().solve();
  }

  void solve()
  {
    // brute force!
    int n = in.nextInt();

    int[] factors = new int[10];
    int numFactors = 0;
    for( int i = 2; i <= n / 2; i++ )
    {
      while( n > 2 && ( n / i ) * i == n )
      {
        factors[numFactors++] = i;
        n /= i;
      }
    }
    factors[numFactors++] = n;

    // look at factors
    int min = INF;
    int[] mask = new int[ numFactors ];
    int[] dim = new int[3];
    BRUTE: while( true )
    {
      for( int i = 0; i < 3; i++ ) dim[i] = 1;
      for( int i = 0; i < mask.length; i++ ) dim[mask[i]] *= factors[i];
      int area = 2*( dim[0]*dim[1] + dim[0]*dim[2] + dim[1]*dim[2] );
      if( area < min ) min = area;
      
      int increment = 0;
      mask[increment]++;
      while( mask[increment] == 3 )
      {
        mask[increment] = 0;
        increment++;
        if( increment == mask.length )
          break BRUTE;
        mask[increment]++;
      }
    }

    System.out.println( min );
  }

}
