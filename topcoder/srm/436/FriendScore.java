/*
 * AxiomOfChoice
 */

import java.io.*;
import java.util.*;

public class FriendScore
{
  static int INF = 0x3fffffff;
  static int MAX;

  public int highestScore( String[] friends )
  {
    int N = friends.length;
    long[] f1 = new long[N];
    for( int i = 0; i < N; i++ )
      for( int j = 0; j < N; j++ )
        if( friends[i].charAt(j) == 'Y' )
          f1[i] |= 1l << j;

    long[] f2 = new long[N];
    int max = 0;
    for( int i = 0; i < N; i++ )
    {
      f2[i] = f1[i];
      for( int j = 0; j < N; j++ )
        if( ( ( f1[i] >> j ) & 1 ) == 1 )
          f2[i] |= f1[j];
      f2[i] &= ~( 1l << i );
      max = Math.max( Long.bitCount( f2[i] ), max );
    }

    return max;
  }
}
