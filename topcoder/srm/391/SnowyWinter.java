/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class SnowyWinter
{
	static int max = 10000;
	public int snowyHighwayLength( int[] start, int[] end )
	{
		boolean[] covered = new boolean[max+1];
		for( int i = 0; i < start.length; i++ )
			for( int j = start[i]; j < end[i]; j++ )
				covered[j] = true;
		int count = 0;
		for( int i = 0; i <= max; i++ ) if( covered[i] ) count++;
		return count;
	}
}
