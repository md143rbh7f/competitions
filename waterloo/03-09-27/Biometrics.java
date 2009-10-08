/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Biometrics
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = Integer.MAX_VALUE;
  static double EPS = 0.0000001;

  public static void main( String[] args )
  {
    while( new Biometrics().solve() );
  }

  // number of points
  int n;

  boolean solve()
  {
    // read input
    n = in.nextInt();
    if( n == 0 ) return false;
    double[][] p1 = new double[n][2];
    for( int i = 0; i < n; i++ )
    { p1[i][0] = in.nextInt(); p1[i][1] = in.nextInt(); }
    double[][] p2 = new double[n][2];
    for( int i = 0; i < n; i++ )
    { p2[i][0] = in.nextInt(); p2[i][1] = in.nextInt(); }

    // translate to canonical position
    translate( p1 ); translate( p2 );

    // convert to polar coordinates
    for( int i = 0; i < n; i++ )
    { toPolar( p1[i] ); toPolar( p2[i] ); }

    // rotate
    for( int i = 1; i < n; i++ )
    {
      p1[i][1] = inRange( p1[i][1] - p1[0][1] );
      p2[i][1] = inRange( p2[i][1] - p2[0][1] );
    }
    p1[0][1] = p2[0][1] = 0;

    // scale down the vectors
    for( int i = 1; i < n; i++ )
    { p1[i][0] /= p1[0][0]; p2[i][0] /= p2[0][0]; }
    p1[0][0] = p2[0][0] = 1;

    // try to match p1 and p2
    if( match( p1, p2 ) ) System.out.println( "similar" );
    else System.out.println( "dissimilar" );

    return true;
  }
  
  // translate to the middle of the polygon
  void translate( double[][] p )
  {
    // find average
    double[] avg = new double[2];
    for( int i = 0; i < n; i++ )
      for( int j = 0; j < 2; j++ )
        avg[j] += p[i][j];
    avg[0] /= n; avg[1] /= n;
    // shift so that avg is [0,0]
    for( int i = 0; i < n; i++ )
      for( int j = 0; j < 2; j++ )
        p[i][j] -= avg[j];
  }

  // magnitude of a vector
  double mag( double[] v )
  { return Math.sqrt( v[0]*v[0] + v[1]*v[1] ); }
  
  // convert cartesian vector to polar
  void toPolar( double[] v )
  {
    double r = mag( v );
    v[1] = Math.atan2( v[0], v[1] );
    v[0] = r;
  }

  // put q in the range of -PI to PI
  double inRange( double q )
  {
    if( q > Math.PI ) q -= 2*Math.PI;
    else if( q < -Math.PI ) q += 2*Math.PI;
    return q;
  }

  // try to match the two polygons by checking vector magnitudes and rotational deltas
  boolean match( double[][] p1, double[][] p2 )
  {
    // differences in magnitude and rotation
    for( int i = 0; i < n; i++ )
      if( neq( p1[i][0], p2[i][0] ) || neq( p1[i][1], p2[i][1] ) )
        return false;
    return true;
  }

  // test if two numbers are not within EPS of each other
  boolean neq( double a, double b )
  {
    double d = a - b;
    if( d > EPS || d < -EPS ) return true;
    return false;
  }

}
