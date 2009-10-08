/*
 * Siyang Chen
 * CS 149s
 */

import java.io.*;
import java.util.*;

public class Dominos
{
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  static int INF = Integer.MAX_VALUE;
  static int MAX = 10000;

  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new Dominos().solve();
  }

  void solve()
  {
    int n = in.nextInt();
    int m = in.nextInt();
    int l = in.nextInt();

    // adjacency list
    LinkedList<Integer>[] edges = (LinkedList<Integer>[])( new LinkedList[MAX] );
    for( int i = 0; i < m; i++ )
    {
      int from = in.nextInt();
      if( edges[from] == null ) edges[from] = new LinkedList<Integer>();
      edges[from].add( in.nextInt() );
    }

    boolean[] seen = new boolean[MAX];
    int result = 0;
    // knock over dominos
    for( int i = 0; i < l; i++ )
    {
      LinkedList<Integer> q = new LinkedList<Integer>();
      q.add( in.nextInt() );
      while( !q.isEmpty() )
      {
        int next = q.poll();
        if( !seen[next] )
        {
          seen[next] = true;
          result++;
          if( edges[next] != null ) q.addAll( edges[next] );
        }
      }
    }

    System.out.println( result );
  }
}
