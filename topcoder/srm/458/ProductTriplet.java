/*
	AxiomOfChoice
 */

import java.math.*;
import java.util.*;

public class ProductTriplet
{
	public long countTriplets( int x0, int x1, int y0, int y1, int z0, int z1 )
	{
		int[] x = { x0-1, x1 }, y = { y0-1, y1 }, z = { z0-1, z1 };
		long res = 0;
		// PIE
		for( int i = 0; i < 8; i++ )
			res += (Integer.bitCount(i)%2==1?1:-1)*triplets( x[i&1], y[(i>>1)&1], z[(i>>2)&1] );
		return res;
	}

	// triplets less than x,y,z
	long triplets( int x, int y, int z )
	{
		long res = 0;
		int sqrt = (int)Math.sqrt(z);
		for( int i = 1; i<=x && i<=sqrt; i++ ) res += Math.min(z/i,y);
		for( int i = 1; i<=y && i<=sqrt; i++ ) res += Math.max( 0, Math.min(z/i,x)-sqrt );
		return res;
	}
}
