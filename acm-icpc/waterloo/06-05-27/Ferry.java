/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Ferry
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = 0x3fffffff;
  static int MAX;

  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new Ferry().solve();
  }

  void solve()
  {
    // length of barge
    int L = in.nextInt()*100;
    // num cars
    int m = in.nextInt();

    // count
    int lt = 0; int rt = 0;
    int ll = 0; int rl = 0;
    for( int i = 0; i < m; i++ )
    {
      int l = in.nextInt();
      int p = in.next().charAt(0);
      // left
      if( p == 'l' )
      {
        if( ll + l > L )
        {
          lt++;
          ll = l;
        }
        else ll += l;
      }
      // right
      else
      {
        if( rl + l > L )
        {
          rt++;
          rl = l;
        }
        else rl += l;
      }
    }
    if( ll > 0 ) lt++;
    if( rl > 0 ) rt++;

    System.out.println( rt > lt ? 2*rt : 2*lt-1 );
  }
}
