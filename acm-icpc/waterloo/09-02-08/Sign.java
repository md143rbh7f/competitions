/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Sign
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = 0x3fffffff;
  static int MAX;

  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new Sign().solve();
  }

  void solve()
  {
    // size of sign
    int k = in.nextInt();
    // num words
    int w = in.nextInt();

    // word buffer
    char[] buffer = new char[k*w];
    int len = k;

    // process first word
    char[] word = in.next().toCharArray();
    for( int i = 0; i < k; i++ ) buffer[i] = word[i];
    for( int i = 1; i < w; i++ )
    {
      // next word
      word = in.next().toCharArray();
      // try matching m characters
      int m;
      MATCH: for( m = k; m > 0; m-- )
      {
        for( int j = 0; j < m; j++ )
          if( word[j] != buffer[len-m+j] )
            continue MATCH;
        break MATCH;
      }
      // fill the buffer
      for( int j = m; j < k; j++ )
        buffer[len++] = word[j];
    }

    System.out.println( len );
  }
}
