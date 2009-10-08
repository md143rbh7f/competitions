import java.io.*;
import java.util.*;

public class March
{
  
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  
  // main creates and solves instances of the problem
  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new March().solve();
  }
  
  
  //
  // solve one instance
  //
  
  int N;           // # icebergs
  double d2;       // jump distance squared
  
  int peng;        // # penguins
  
  int[] x;         // x coords
  int[] y;         // y coords
  int[] n;         // # penguins on iceberg (initially)
  int[] m;         // max # jumps
  
  int[][] cap;     // graph of capacities (from index 1 to index 2)
  boolean[] seen;  // keep track of where you have already searched (to help with DFS'ing)
  
  void solve()
  {
    N = in.nextInt();
    d2 = in.nextDouble(); d2 *= d2;
    
    // read data for each iceberg
    x = new int[N]; y = new int[N]; n = new int[N]; m = new int[N]; peng = 0;
    for( int i = 0; i < N; i++ )
    { x[i] = in.nextInt(); y[i] = in.nextInt(); n[i] = in.nextInt(); m[i] = in.nextInt(); peng += n[i]; }
    
    // build capacity graph (let index 2N be the 'superstart' node)
    cap = new int[ 2 * N + 1 ][ 2 * N + 1 ];
    for( int i = 0; i < N; i++ )
    {
      cap[ 2 * N ][i] = n[i];       // from superstart to the node (this would be the initial # of penguins on i)
      cap[i][ N + i ] = m[i];       // from 'on' the node to 'off' the node (this is the # of times you can jump off i)
      for( int j = 0; j < N; j++ )  // from 'off' the node to another node (this is infinite, if you can jump from i to j)
      {
        if( i != j )
        {
          int dx = x[i] - x[j];
          int dy = y[i] - y[j];
          if( dx * dx + dy * dy <= d2 ) cap[ N + i ][j] = Integer.MAX_VALUE / 2;
        }
      }
    }
    
    // for each node, try to see if you can gather all the penguins there
    boolean possible = false;
    for( int i = 0; i < N; i++ )
    {
      if( maxFlow( i ) == peng )
      {
        if( possible ) System.out.print( " " );
        System.out.print( i );
        possible = true;
      }
    }
    if( !possible ) System.out.print( "-1" );
    System.out.println();
  }
  
  
  
  // calculate the max flow to node 'end'
  int maxFlow( int end )
  {
    // copy the capacity array
    int[][] copy = new int[ cap.length ][ cap.length ];
    for( int i = 0; i < cap.length; i++ )
      for( int j = 0; j < cap.length; j++ )
      copy[i][j] = cap[i][j];
    
    // now try sending flow from 2 * N to end until you can no longer
    int result = 0;
    int sent = 0;
    do
    {
      seen = new boolean[ cap.length ];
      sent = sendFlow( 2 * N, end, Integer.MAX_VALUE );
      result += sent;
    }
    while( sent > 0 );
    
    // replace the old capacity array with the copy
    cap = copy;
    
    return result;
  }
  
  
  // recursively dfs till you find the intended node
  int sendFlow( int from, int to, int min )
  {
    // if you reached it, then return
    if( from == to ) return min;
    
    // else continue searching
    seen[from] = true;
    for( int i = 0; i < cap.length; i++ )
    {
      // if you can jump, try jumping
      if( !seen[i] && cap[from][i] > 0 )
      {
        // send the minimum amount you find
        int sent = sendFlow( i, to, min < cap[from][i] ? min : cap[from][i] );
        // if you manage to reach the end, decrement each capacity in the path by the min amount
        if( sent > 0 )
        {
          cap[from][i] -= sent;
          cap[i][from] += sent;
          return sent;
        }
      }
    }
    
    return 0;
  }
  
}
