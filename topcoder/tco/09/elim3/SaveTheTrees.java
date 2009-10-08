/*
 * AxiomOfChoice
 */

import java.io.*;
import java.util.*;

public class SaveTheTrees
{
  static int INF = 0x3fffffff;
  static int MAX;

  public int minimumCut( int[] x, int[] y, int[] h )
  {
    int n = x.length;
    for( int i = 0; i < n; i++ )
    {
      for( int j = i + 1; j < n; j++ )
      {
        if( h[i] < h[j] )
        {
          x[i] ^= x[j]; x[j] ^= x[i]; x[i] ^= x[j];
          y[i] ^= y[j]; y[j] ^= y[i]; y[i] ^= y[j];
          h[i] ^= h[j]; h[j] ^= h[i]; h[i] ^= h[j];
        }
      }
    }

    int best = INF;

    for( int x1 : x )
    {
      for( int x2 : x )
      {
        for( int y1 : y )
        {
          for( int y2 : y )
          {
            if( x1 > x2 || y1 > y2 ) continue;

            int need = 2 * ( x2 - x1 + y2 - y1 );
            int have = 0;
            int cut = 0;

            for( int i = 0; i < n; i++ )
            {
              if( x[i] < x1 || x[i] > x2 || y[i] < y1 || y[i] > y2 )
              {
                cut++;
                have += h[i];
              }
            }

            for( int i = 0; i < n && have < need; i++ )
            {
              if( x[i] >= x1 && x[i] <= x2 && y[i] >= y1 && y[i] <= y2 )
              {
                cut++;
                have += h[i];
              }
            }

            if( cut < best ) best = cut;
          }
        }
      }
    }
    return best;
  }
}
