/*
	AxiomOfChoice
 */

import java.math.*;
import java.util.*;

public class TheTriangleBothDivs
{
	static int miss = 1337, max = 24*60;
	public String fix( String time )
	{
		char[] T = time.toCharArray();
		int H0 = T[0]=='?'? miss:T[0]-'0';
		int H1 = T[1]=='?'? miss:T[1]-'0';
		int M0 = T[3]=='?'? miss:T[3]-'0';
		int M1 = T[4]=='?'? miss:T[4]-'0';
		int S = T[9]=='?'? miss:(T[9]=='-'?-1:1);
		int Z = T[10]=='?'? miss:T[10]-'0';
		int least = max;
		for( int s = -1; s <= 1; s += 2 ) if( S==miss || s==S )
		for( int z = s==-1?1:0; z < 10; z++ ) if( Z==miss || z==Z )
		{
			for( int h = 0; h < 24; h++ )
			{
				int h0 = h/10, h1=h%10;
				if( H0==miss || h0==H0 )
				if( H1==miss || h1==H1 )
				for( int m0 = 0; m0 < 6; m0++ ) if( M0==miss || m0==M0 )
				for( int m1 = 0; m1 < 10; m1++ ) if( M1==miss || m1==M1 )
				{
					int t = ((h0*10+h1-s*z)*60+(m0*10+m1))%max;
					if( t < 0 ) t += max;
					if( t < least ) least = t;
				}
			}
		}
		String res0 = ""+least/60, res1 = ""+least%60;
		if( res0.length()==1 ) res0 = "0"+res0;
		if( res1.length()==1 ) res1 = "0"+res1;
		return res0+":"+res1;
	}
}
