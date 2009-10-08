/*
 * AxiomOfChoice
 */

import java.io.*;
import java.util.*;

public class LaserShooting
{
  static int INF = 0x3fffffff;
  static int MAX;

  public double numberOfHits( int[] x, int[] y1, int[] y2 )
  {
    double res = 0;
    double a, b;
    for( int i = 0; i < x.length; i++ )
    {
      a = Math.atan2( x[i], y1[i] );
      b = Math.atan2( x[i], y2[i] );
      res += Math.abs( a - b );
    }
    return res / Math.PI;
  }
}
