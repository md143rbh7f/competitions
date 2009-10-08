/*
 * Siyang Chen
 * CS 149s
 * 1 October 2008
 */

import java.util.Scanner;

public class Logo
{
  static Scanner in = new Scanner( System.in );
  
  public static void main( String[] args )
  {
    //first line - # of programs
    int cases = in.nextInt();
    //solve each program
    for( int i = 0; i < cases; i++ ) new Logo();
  }
  
  private static final int FD = 3262;
  private static final int BK = 3145;
  private static final int LT = 3464;
  private static final int RT = 3650;
  
  private Logo()
  {
    //# of commands
    int commands = in.nextInt();
    
    //store your position
    double x = 0;
    double y = 0;
    double angle = 0;
    
    //parse each of the move commands
    for( int i = 0; i < commands; i++ )
    {
      int commandCode = in.next().hashCode();
      int number = in.nextInt();
      
      switch( commandCode )
      {
        case FD:
          x += number * Math.cos( angle );
          y += number * Math.sin( angle );
          break;
        case BK:
          x -= number * Math.cos( angle );
          y -= number * Math.sin( angle );
          break;
        case LT: angle += number * Math.PI / 180; break;
        case RT: angle -= number * Math.PI / 180; break;
      }
    }
    
    //output
    System.out.println( Math.round( Math.sqrt( x * x + y * y ) ) );
  }
}