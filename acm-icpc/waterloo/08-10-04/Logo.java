/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Logo
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = Integer.MAX_VALUE;
  static int MAX;

  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new Logo().solve();
  }
  
  // commands and stuff
  enum Cmd { FD, BK, LT, RT }
  static HashMap<String,Cmd> getCmd = new HashMap<String,Cmd>();
  static
  {
    getCmd.put( "fd", Cmd.FD );
    getCmd.put( "bk", Cmd.BK );
    getCmd.put( "lt", Cmd.LT );
    getCmd.put( "rt", Cmd.RT );
  }

  // num lines
  int l;
  // xpos, ypos, theta, command
  double x, y, q;
  String cmdStr; Cmd cmd;
  void solve()
  {
    l = in.nextInt();
    
    // move until you get to the first question mark
    move();

    // store stuff
    double tx = x; double ty = y; double tq = q;
    Cmd tcmd = getCmd.get( cmdStr );

    // move again
    move();

    // solve FD/BK
    double r = Math.sqrt( x*x + y*y );
    int p = (int) Math.round( Math.toDegrees( Math.atan2( y, x ) ) );
    if( p == tq ) r = -r;
    // solve LT/RT
    int dq = (int) Math.round( Math.toDegrees( Math.atan2( -ty, -tx ) - Math.atan2( y-ty, x-tx ) ) );
    switch( tcmd )
    {
      case FD:
        System.out.println( Math.round(r) );
        break;
      case BK:
        System.out.println( Math.round(-r) );
        break;
      case LT:
        if( dq < 0 ) dq += 360;
        else if( dq > 360 ) dq -= 360;
        System.out.println( dq );
        break;
      case RT:
        if( dq < -360 ) dq += 360;
        else if( dq > 0 ) dq -= 360;
        System.out.println( -dq );
        break;
    }

  }

  // move until you reach the question mark or run out of lines
  void move()
  {
    while( l-- > 0 )
    {
      cmdStr = in.next();
      String numStr = in.next();
      if( numStr.charAt(0) == '?' ) return;
      cmd = getCmd.get( cmdStr );
      int num = Integer.parseInt( numStr );
      switch( cmd )
      {
        case FD:
          x += num * Math.cos( Math.toRadians( q ) );
          y += num * Math.sin( Math.toRadians( q ) );
          break;
        case BK:
          x -= num * Math.cos( Math.toRadians( q ) );
          y -= num * Math.sin( Math.toRadians( q ) );
          break;
        case LT:
          q += num;
          if( q > 180 ) q -= 360;
          break;
        case RT:
          q -= num;
          if( q < -180 ) q += 360;
          break;
      }
    }
  }
}
