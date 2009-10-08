/*
 * AxiomOfChoice
 */

import java.io.*;
import java.util.*;

public class CorporationSalary
{
  static int INF = 0x3fffffff;
  static int MAX;

  public long totalSalary( String[] relations )
  {
    int N = relations.length;

    ArrayList<Integer>[] children = (ArrayList<Integer>[])(new ArrayList[N]);
    int[] parentCount = new int[N];
    for( int i = 0; i < N; i++ )
    {
      children[i] = new ArrayList<Integer>();
      for( int j = 0; j < N; j++ )
      {
        if( relations[i].charAt(j) == 'Y' )
        {
          children[i].add( j );
          parentCount[j]++;
        }
      }
    }

    int[] sorted = new int[N];
    int qptr = 0;
    for( int i = 0; i < N; i++ )
      if( parentCount[i] == 0 )
        sorted[qptr++] = i;

    for( int i = 0; i < N; i++ )
    {
      for( Integer j : children[sorted[i]] )
      {
        parentCount[j]--;
        if( parentCount[j] == 0 )
          sorted[qptr++] = j;
      }
    }
    
    long tot = 0;
    long[] sal = new long[N];
    for( int k = N-1; k >= 0; k-- )
    {
      int i = sorted[k];
      if( children[i].size() == 0 ) sal[i] = 1;
      else for( Integer j : children[i] )
        sal[i] += sal[j];
      tot += sal[i];
    }

    return tot;
  }

}
