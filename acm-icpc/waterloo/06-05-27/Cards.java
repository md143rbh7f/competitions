/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Cards
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = 0x3fffffff;
  static int MAX;

  public static void main( String[] args )
  {
    while( new Cards().solve() );
  }

  boolean solve()
  {
    // num hands
    int h = in.nextInt();
    if( h == 0 ) return false;

    // counter
    int n = 0;
    Node root = new Node();

    // each hand
    for( int i = 0; i < h; i++ )
    {
      String[] hand = new String[in.nextInt()];
      Node ptr = root;
      for( int j = hand.length-1; j >= 0; j-- ) hand[j] = in.next();
      for( int j = 0; j < hand.length; j++ )
      {
        if( !ptr.deti.containsKey( hand[j] ) )
        {
          ptr.deti.put( hand[j], new Node() );
          n++;
        }
        ptr = ptr.deti.get( hand[j] );
      }
    }

    System.out.println( n );

    return true;
  }

  // trie node
  class Node
  { HashMap<String,Node> deti = new HashMap<String,Node>(); }
}
