/*
 * Siyang Chen
 * CS 149s
 * 21 September 2008
 */

import java.util.Scanner;

public class Journey
{
  static Scanner in = new Scanner( System.in );
  
  public static void main( String[] args )
  {
    while( !in.hasNextInt() )
    {
      //inputs, parsed as time
      double start = toNumber( in.next() );
      double t2 = toNumber( in.next() ) - start;
      double t3 = toNumber( in.next() ) - start;
      double t4 = toNumber( in.next() ) - start;
      double t5 = toNumber( in.next() ) - start;
      //use the mathematical solution
      System.out.println( toString( (int)Math.round( ( t2 * t4 * ( t5 - t3 ) / ( t2 * ( t4 - t3 ) + t3 * ( t5 - t4 ) ) + start ) ) ) );
    }
  }
  
  //given a String with the format HH:MM:SS, return an number with the time
  private static double toNumber( String time )
  {
    double result = 0;
    char[] timeChars = time.toCharArray();
    result += timeChars[0] * 36000
      + timeChars[1] * 3600
      + timeChars[3] * 600
      + timeChars[4] * 60
      + timeChars[6] * 10
      + timeChars[7]
      - 1933008;
    return result;
  }
  
  //convert an int time back into a String time
  private static String toString( int time )
  {
    int seconds = time % 60;
    time /= 60;
    int minutes = time % 60;
    time /= 60;
    int hours = time;
    return ( hours < 10 ? "0" : "" ) + hours + ":" + ( minutes < 10 ? "0" : "" ) + minutes + ":" + ( seconds < 10 ? "0" : "" ) + seconds;
  }
}
