import java.math.*;
import java.util.*;

public class TheSoccerDivTwo
{
	public int find( int[] pts )
	{
		pts[0] += 3;
		int x = pts[0], n = pts.length, g = 0, n0 = 0, n1 = 0, n2 = 0;
		for( int i = 1; i < n; i++ )
		{
			if( pts[i]>x ) g++;
			else if( pts[i]==x ) n0++;
			else if( pts[i]==x-1 || pts[i]==x-2 ) n1++;
			else if( pts[i]<x ) n2++;
		}
		if( n0>0 ) n0--;
		if( n0>g+n2 ) g += (n0-(g+n2)+1)/2;
		return g+1;
	}
}
