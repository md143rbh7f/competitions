/*
 * AxiomOfChoice
 */

import java.io.*;
import java.util.*;

public class SolitaireSimulation
{
  static int INF = 0x3fffffff;
  static int MAX;

  public int periodLength( int[] heaps )
  {
    int count = heaps.length;
    int[] can = new int[51];

    for( int i = 0; i < heaps.length; i++ ) can[heaps[i]]++;

    HashMap<State,Integer> last = new HashMap<State,Integer>();
    State cur = new State( count, can );
    last.put( cur, 1 );

    for( int i = 2; true; i++ )
    {
      cur = cur.next();
      if( last.containsKey( cur ) ) return i - last.get( cur );
      last.put( cur, i );
    }

  }

  class State
  {
    int count;
    int[] can;
    int hash;

    public State( int _count, int[] _can )
    {
      count = _count;
      can = _can;
      getHash();
    }

    State next()
    {
      int[] can2 = new int[51];
      int count2 = count + 1 - can[1];

      for( int i = 1; i < 51; i++ ) can2[i-1] = can[i];
      can2[count]++;

      return new State( count2, can2 );
    }

    void getHash()
    {
      hash = 0;
      for( int i = 1; i < 51; i++ ) hash += can[i] * i;
    }

    public int hashCode()
    { return hash; }

    public boolean equals( Object obj )
    {
      State o = (State)obj;
      for( int i = 1; i < 51; i++ ) if( can[i] != o.can[i] ) return false;
      return true;
    }
  }
}
