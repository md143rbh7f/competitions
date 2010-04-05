/*
	AxiomOfChoice
 */

import java.math.*;
import java.util.*;

public class LotteryTicket
{
	public String buy( int price, int b1, int b2, int b3, int b4 )
	{
		int[] b = { b1, b2, b3, b4 };
		for( int i = 0; i < 16; i++ )
		{
			int sum = 0;
			for( int j = 0; j < 4; j++ ) if( ((i>>j)&1)==1 ) sum += b[j];
			if( sum == price ) return "POSSIBLE";
		}
		return "IMPOSSIBLE";
	}
}
