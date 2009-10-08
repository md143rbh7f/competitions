/*
 * AxiomOfChoice
 */

import java.io.*;
import java.util.*;

public class PouringWater
{
  static int INF = 0x3fffffff;
  static int MAX;

  public int getMinBottles( int N, int K )
  {
    int have = Integer.bitCount( N );
    if( have < K ) return 0;

    int nextLargest = N;
    while( Integer.bitCount( nextLargest ) > K )
      nextLargest = getNext( nextLargest );

    return nextLargest - N;
  }

  int getNext( int num )
  {
    int i;
    for( i = 0; i < 31; i++ )
      if( ( 1 & ( num >> i ) ) == 1 )
        break;
    return num + ( 1 << i );
  }

}
