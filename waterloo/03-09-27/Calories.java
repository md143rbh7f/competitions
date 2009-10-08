/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Calories
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = Integer.MAX_VALUE;
  static int MAX;

  public static void main( String[] args )
  {
    while( new Calories().solve() );
  }

  boolean solve()
  {
    // read stuff
    String line;
    boolean firstLine = true;
    
    // records by calorie
    double[] sums = new double[5];
    while( (line = in.nextLine()).charAt(0) != '-' )
    {
      // the first line was valid
      firstLine = false;
      double[] lineResult = toCal( line );
      for( int i = 0; i < 5; i++ )
        sums[i] += lineResult[i];
    }
    if( firstLine ) return false;

    // process the stuff
    double tot = 0;
    for( int i = 0; i < 5; i++ )
      tot += sums[i];
    for( int i = 0; i < 5; i++ )
      sums[i] = 100 * sums[i] / tot;
    
    System.out.println( Math.round( sums[0] ) + "%" );

    return true;
  }

  // parse by line and return caloric values
  double[] toCal( String lineStr )
  {
    // 0 - cals
    // 1 - grams
    // 2 - percents
    double[][] values = new double[3][5];
    for( int i = 0; i < 3; i++ )
      for( int j = 0; j < 5; j++ )
        values[i][j] = -1;
    String[] line = lineStr.split( " " );
    for( int i = 0; i < 5; i++ )
    {
      int len = line[i].length() - 1;
      int val = Integer.parseInt( line[i].substring( 0, len ) );
      int level = -1;
      switch( line[i].charAt( len ) )
      {
        case 'C': level = 0; break;
        case 'g': level = 1; break;
        case '%': level = 2; break;
      }
      values[level][i] = val;
    }

    // convert grams to calories
    if( values[1][0] != -1 ) values[0][0] = values[1][0]*9;
    if( values[1][4] != -1 ) values[0][4] = values[1][4]*7;
    for( int i = 1; i < 4; i++ )
      if( values[1][i] != -1 )
        values[0][i] = values[1][i]*4;

    // convert percentages to calories
    double sum = 0;
    double pctSum = 0;
    for( int i = 0; i < 5; i++ )
    {
      if( values[0][i] != -1 ) sum += values[0][i];
      if( values[2][i] != -1 ) pctSum += ( values[2][i] /= 100 );
    }
    double tot = sum / ( 1 - pctSum );
    for( int i = 0; i < 5; i++ )
      if( values[2][i] != -1 )
        values[0][i] = values[2][i] * tot;

    return values[0];
  }
}
