/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class ColorfulBoxesAndBalls
{
	public int getMaximum( int r, int b, int rs, int bs, int rbs )
	{
		if( b > r )
		{
			int t = b; b = r; r = t;
			t = bs; bs = rs; rs = t;
		}
		int swap = 2*rbs*b+rs*(r-b);
		int same = r*rs+b*bs;
		return Math.max(swap,same);
	}
}
