import java.io.*;
import java.util.*;

public class Escape
{
  
  static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
  
  // main creates and solves instances of the problem
  public static void main( String[] args )
  {
    int c = in.nextInt();
    for( int i = 0; i < c; i++ ) new Escape().solve();
  }
  
  // search around a given map position
  int[] DX = { 0, 1, 0, -1 };
  int[] DY = { 1, 0, -1, 0 };
  
  //
  // solve one instance
  //
  
  int[][] map;  // the map of bases
  
  void solve()
  {
    // read # bases and map size
    int N = in.nextInt(); int X = in.nextInt(); int Y = in.nextInt();
    
    // read start and end positions
    int x1 = in.nextInt(); int y1 = in.nextInt(); int x2 = in.nextInt(); int y2 = in.nextInt();    
        
    // read coord for each base
    int[] x = new int[N]; int[] y = new int[N];
    for( int i = 0; i < N; i++ )
    { x[i] = in.nextInt(); y[i] = in.nextInt(); }
    
    // BFS from each of the bases and fill out the min distances
    map = new int[X][Y]; for( int i = 0; i < X; i++ ) for( int j = 0; j < Y; j++ ) map[i][j] = Integer.MAX_VALUE;
    LinkedList<int[]> queue = new LinkedList<int[]>();
    for( int i = 0; i < N; i++ )
    {
      int sx = x[i];
      int sy = y[i];
      if( sx < X && sx >= 0 && sy < Y && sy >= 0 )
      {
        map[sx][sy] = 0;
        int[] base = { sx, sy };
        queue.add( base );
      }
    }
    while( queue.size() > 0 )
    {
      int[] pos = queue.poll();
      int sd = map[ pos[0] ][ pos[1] ] + 1;
      // search around each position
      for( int i = 0; i < 4; i++ )
      {
        int sx = pos[0] + DX[i];
        int sy = pos[1] + DY[i];
        if( sx < X && sx >= 0 && sy < Y && sy >= 0 && map[sx][sy] > sd )
        {
          map[sx][sy] = sd;
          int[] next = { sx, sy };
          queue.add( next );
        }
      }
    }
    
    // now, starting from the beginning, DFS to the end, finding the minimum separation from any enemy base (using a priority queue)
    boolean[][] seen = new boolean[X][Y];
    PriorityQueue<int[]> pq = new PriorityQueue<int[]>( X * Y, new MaxMinComparator() );
    int[] start = { x1, y1, 0 };
    pq.add( start );
    while( true )
    {
      // grab the position that has the maximum min value
      int[] pos = pq.poll();
      
      // if you are at the end, print and return
      if( pos[0] == x2 && pos[1] == y2 )
      {
        System.out.println( map[ pos[0] ][ pos[1] ] + " " + pos[2] );
        return;
      }
      
      // else search around
      for( int i = 0; i < 4; i++ )
      {
        int sx = pos[0] + DX[i];
        int sy = pos[1] + DY[i];
        if( sx < X && sx >= 0 && sy < Y && sy >= 0 && !seen[sx][sy] )
        {
          map[sx][sy] = map[ pos[0] ][ pos[1] ] < map[sx][sy] ? map[ pos[0] ][ pos[1] ] : map[sx][sy];
          seen[sx][sy] = true;
          int[] next = { sx, sy, pos[2] + 1 };
          pq.add( next );
        }
      }
    }
  }
  
  
  // evaluate two points by checking which one has the farthest separation from an enemy base
  class MaxMinComparator implements Comparator<int[]>
  {
    public int compare( int[] a, int[] b )
    {
      int d = map[ b[0] ][ b[1] ] - map[ a[0] ][ a[1] ];
      if( d != 0 ) return d;
      return b[2] - a[2];
    }
  }
  
}