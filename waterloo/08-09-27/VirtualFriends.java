/*
 * Siyang Chen
 * CS 149s
 * 1 October 2008
 */

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class VirtualFriends
{
  static Scanner in = new Scanner( System.in );
  
  public static void main( String[] args )
  {
    //first line - # of programs
    int cases = in.nextInt();
    //solve each program
    for( int i = 0; i < cases; i++ ) new VirtualFriends();
  }
  
  private VirtualFriends()
  {
    //# of commands
    int commands = in.nextInt();
    
    //initialize the union-join structure
    int size = 0;
    lookup = new HashMap<String,Integer>();
    parent = new int[ commands * 2 ];
    Arrays.fill( parent, -1 );
    
    //parse each of the friend commands
    for( int i = 0; i < commands; i++ )
    {
      String xString = in.next();
      String yString = in.next();
      
      //get the ID values for each friend
      int x;
      int y;
      if( !lookup.containsKey( xString ) )
      {
        x = size++;
        lookup.put( xString, x );
      }
      else x = lookup.get( xString );
      if( !lookup.containsKey( yString ) )
      {
        y = size++;
        lookup.put( yString, y );
      }
      else y = lookup.get( yString );
      
      //output
      System.out.println( merge( x, y ) );
    }
    
  }
  
  
  //use a union-join data structure to build the algorithm
  private HashMap<String,Integer> lookup;
  //this array stores the 'parent set' of each set; if you are the root node, store the negated size of your set
  //initialize to -1
  private int[] parent;
  
  //find what set x is in
  private int find( int x )
  {
    //search 'recursively' up the parents, until you find the root of the node
    int ptr = x;
    while( parent[ptr] > -1 ) ptr = parent[ptr];
    
    //path compression - for each recursive step you take, just 'hardlink' it to the final result
    while( x != ptr )
    {
      int old = x;
      x = parent[x];
      parent[old] = ptr;
    }
    return ptr;
  }
  
  //merge two sets
  private int merge( int x, int y )
  {
    //get roots
    x = find( x );
    y = find( y );
    
    if( x != y )
    {
      //place the smaller set in the larger set (parent[root] is the negated size of the set of [root])
      if( parent[x] > parent[y] )
      {
        //swap x and y if x is smaller than y, so that x is always the root of the largest set
        int temp = x;
        x = y;
        y = temp;
      }
      //now add y's into x, and then link y to x
      parent[x] += parent[y];
      parent[y] = x;
    }
    
    //return the combined size
    return -parent[x];
  }
}