/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Traffic
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = 0x3fffffff;
  static int MAX;

  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new Traffic().solve();
  }

  // x, y, velocity, speed squared
  double[] x,y,vx,vy;

  // dist, dist squared
  double r,r2;

  // solve one instance
  void solve()
  {
    // num boats
    int n = in.nextInt();
    // collision distance squared
    r = in.nextDouble(); r2 = r*r;

    // x, y, direction, speed
    x = new double[n]; y = new double[n]; vx = new double[n]; vy = new double[n];
    double q,s;
    for( int i = 0; i < n; i++ )
    {
      // x,y
      x[i] = in.nextDouble(); y[i] = in.nextDouble();
      // convert direction and speed to x/y velocity
      q = Math.toRadians( 90-in.nextDouble() ); s = in.nextDouble();
      vx[i] = Math.cos( q ) * s; vy[i] = Math.sin( q ) * s;
    }

    // calculate the earliest collision
    int max = INF;
    for( int i = 0; i < n; i++ )
      for( int j = i+1; j < n; j++ )
        if( i != j )
          max = (int)Math.min( max, Math.round( time( i, j ) ) );

    System.out.println( max < INF ? max : "No collision." );
  }

  // calculate time
  double time( int i, int j )
  {
    // dif in starting positions
    double dx = x[i]-x[j];
    double dy = y[i]-y[j];

    // special case: they are already intersecting
    if( Math.hypot( dx, dy ) < r ) return 0;

    // difference in velocities
    double dvx = vx[i]-vx[j];
    double dvy = vy[i]-vy[j];

    // solve the quadratic
    double res = INF;
    double a = dvx*dvx + dvy*dvy;
    double b = 2*( dx*dvx + dy*dvy );
    double c = dx*dx + dy*dy - r2;
    double disc = b*b - 4*a*c;
    if( disc >= 0 && a != 0 )
    {
      res = ( -b + Math.sqrt( disc ) ) / ( 2*a );
      double res2 = ( -b - Math.sqrt( disc ) ) / ( 2*a );
      if( res2 >= 0 ) res = Math.min( res, res2 );
    }

    // return time if it is valid
    if( res < 0 ) return INF;
    return res;
  }
}
