/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class TheQuestionsAndAnswersDivOne
{
	static int max = 10;
	static long[][][] dp = new long[max][max][max];
	static
	{
		int choose;
		dp[0][0][0] = 1;
		for( int i = 1; i < max; i++ )
		for( int Y = 0; Y < max; Y++ )
		for( int N = 0; N < max; N++ )
		if( Y+N >= i )
		{
			choose = Y;
			for( int y = 1; y <= Y; y++ )
			{
				dp[i][Y][N] += choose*dp[i-1][Y-y][N];
				choose = choose*(Y-y)/(y+1);
			}
			choose = N;
			for( int n = 1; n <= N; n++ )
			{
				dp[i][Y][N] += choose*dp[i-1][Y][N-n];
				choose = choose*(N-n)/(n+1);
			}
		}
	}

	public int find( int q, String[] ans )
	{
		int y = 0, n = 0;
		for( int i = 0; i < ans.length; i++ )
			if( ans[i].equals("Yes") ) y++;
		n = ans.length-y;
		return (int)dp[q][y][n];
	}
}
