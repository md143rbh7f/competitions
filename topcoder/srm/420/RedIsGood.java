/*
 * AxiomOfChoice
 */

import java.io.*;
import java.util.*;

public class RedIsGood
{
  static int INF = 0x3fffffff;
  static int MAX;

  public double getProfit( int r, int b )
  {
    double[][] dp = new double[2][b+1];

    for( int i = 1; i <= r; i++ )
    {
      dp[1][0] = i;
      for( int j = 1; j <= b; j++ )
      {
        dp[1][j] = ((double)i)/(i+j)*(1+dp[0][j]) + ((double)j)/(i+j)*(-1+dp[1][j-1]);
        if( dp[1][j] < 0 ) dp[1][j] = 0;
      }
      dp[0] = dp[1];
      dp[1] = new double[b+1];
    }

    return dp[0][b];
  }
}
