import java.math.*;
import java.util.*;

public class PlanarGraphShop
{
	int maxv = 36, pre[] = { 8, 9 };
	public int bestCount( int n )
	{
		int[] min = new int[n+1];
		for( int i = 1; i <= n; i++ ) min[i] = i;
		for( int c : pre ) for( int j = c; j <= n; j++ ) if( min[j]>min[j-c]+1 ) min[j] = min[j-c]+1;
		for( int v = 3; v <= maxv; v++ )
		for( int e = 0; e <= 3*v-6; e++ )
		{
			int c = v*v*v+e*e;
			for( int j = c; j <= n; j++ ) if( min[j]>min[j-c]+1 ) min[j] = min[j-c]+1;
		}
		return min[n];
	}
}
