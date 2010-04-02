/*
	AxiomOfChoice
 */

import java.math.*;
import java.util.*;

public class TheSquareDivTwo
{
	public String[] solve( String[] board )
	{
		int n = board.length, r[] = new int[n];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) if( board[i].charAt(j)=='C' ) r[i]++;
		char[][] b = new char[n][n];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) b[j][i] = j<r[i]?'C':'.';
		String[] ret = new String[n];
		for( int i = 0; i < n; i++ ) ret[i] = new String( b[n-1-i] );
		return ret;
	}
}
