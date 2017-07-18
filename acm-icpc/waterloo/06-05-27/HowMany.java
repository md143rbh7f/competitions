/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class HowMany
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = 0x3fffffff;
  static int MAX;

  public static void main( String[] args )
  {
    while( new HowMany().solve() );
  }

  boolean solve()
  {
    long m = in.nextLong();
    long n = in.nextLong();

    if( m < 0 ) return false;

    System.out.println( count( n ) - count( m-1 ) + ( m == 0 ? 1 : 0 ) );

    return true;
  }

  long count( long a )
  {
    if( a < 10 ) return 1;

    long d = a%10;
    long r = a/10;

    long ans = 10*(count(r-1)-1) + r + 1;

    d++;
    while( r != 0 )
    {
      if( r%10 == 0 ) ans += d;
      r /= 10;
    }

    return ans;
  }
}
