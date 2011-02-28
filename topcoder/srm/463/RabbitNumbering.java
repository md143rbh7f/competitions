/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class RabbitNumbering
{
	static int mod = 1000000007;

	public int theCount( int[] m )
	{
		Arrays.sort( m );
		long res = 1;
		for( int i = 0; i < m.length; i++ )
		{
			if( m[i] < i ) return 0;
			res = (res*(m[i]-i))%mod;
		}
		return (int)res;
	}

}
