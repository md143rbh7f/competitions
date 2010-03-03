/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class BunnyPuzzle
{
	public int theCount( int[] s )
	{
		Arrays.sort( s );
		int count = 0, n = s.length;
		for( int i = 0; i < n-1; i++ )
		{
			int j = i+1;
			int c = 2*s[j]-s[i], d = 2*s[i]-s[j];
			if( j+1>=n || s[j+1]>c ) count++;
			if( i-1<0 || s[i-1]<d ) count++;
		}
		return count;
	}
}
