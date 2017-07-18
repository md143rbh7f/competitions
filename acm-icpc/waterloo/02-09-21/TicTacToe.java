/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class TicTacToe
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = Integer.MAX_VALUE;
  static char X = 'X'; static char O = 'O';
  static String NO = "no"; static String YES = "yes";
  static String[] winString =
  {
    "111000000",
    "000111000",
    "000000111",
    "100100100",
    "010010010",
    "001001001",
    "100010001",
    "001010100",
  };
  static int[] win = new int[ winString.length ];
  static
  {
    for( int i = 0; i < winString.length; i++ )
      win[i] = Integer.parseInt( winString[i], 2 );
  }

  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ )
    {
      in.nextLine();
      new TicTacToe().solve();
    }
  }

  void solve()
  {
    // brute force all the cases
    char[][] grid = new char[3][3];
    for( int i = 0; i < 3; i++ )
      grid[i] = in.nextLine().toCharArray();

    int oSum = 0; int xSum = 0;
    int oMask = 0; int xMask = 0;

    // check sums
    for( int i = 0; i < 3; i++ )
    {
      for( int j = 0; j < 3; j++ )
      {
        if( grid[i][j] == X )
        {
          xSum++;
          xMask |= 1 << ( i * 3 + j );
        }
        else if( grid[i][j] == O )
        {
          oSum++;
          oMask |= 1 << ( i * 3 + j );
        }
      }
    }
    if( oSum > xSum || xSum > oSum + 1 )
    {
      System.out.println( NO );
      return;
    }

    // check wins by using bitmasks
    boolean xWin = false; boolean oWin = false;
    for( int i = 0; i < win.length; i++ )
    {
      if( ( xMask & win[i] ) == win[i] ) xWin = true;
      if( ( oMask & win[i] ) == win[i] ) oWin = true;
    }
    if( ( xWin && oWin ) ||
        ( xWin && ( xSum == oSum ) ) ||
        ( oWin && ( xSum != oSum ) ) )
    {
      System.out.println( NO );
      return;
    }

    System.out.println( YES );
  }
}
