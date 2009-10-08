/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Sequence
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = 0x3fffffff;
  static int MAX = 11000000;

  public static void main( String[] args )
  {
    while( new Sequence().solve() );
  }

  boolean solve()
  {
    // mod base
    N = in.nextInt(); if( N == 0 ) return false;
    // first argument
    int n = in.nextInt();

    // read in
    String next;
    do { func.add( next = in.next() ); }
    while( !next.equals( "%" ) );

    // count
    int[] last = new int[MAX];
    int x = n;
    for( int i = 1; true; i++ )
    {
      x = func(x);
      if( last[x] > 0 || x == n )
      {
        System.out.println( i - last[x] );
        break;
      }
      last[x] = i;
    }
    
    return true;
  }

  // evaluate the function
  int N;
  ArrayList<String> func = new ArrayList<String>( 50 );
  long[] stack = new long[50];
  int func( int x )
  {
    int ptr = -1;
    for( String tok : func )
    {
      switch( tok.charAt(0) )
      {
        case '+': stack[ptr-1] += stack[ptr--]; if( stack[ptr] >= N ) stack[ptr] -= N; break;
        case '*': stack[ptr-1] *= stack[ptr--]; stack[ptr] %= N; break;
        case 'x': stack[++ptr] = x; break;
        case 'N': stack[++ptr] = N; break;
        case '%': stack[ptr-1] %= stack[ptr--]; break;
        default: stack[++ptr] = Integer.parseInt( tok ); break;
      }
    }
    return (int)stack[0];
  }
}
