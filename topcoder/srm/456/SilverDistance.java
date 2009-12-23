/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class SilverDistance
{
	public int minSteps( int x1, int y1, int x2, int y2 )
	{
		int dx = x2-x1, dy = y2-y1;
		int ddx = Math.abs( dx ), ddy = Math.abs( dy );
		if( dx == 0 && dy >= 0 ) return dy;
		boolean odd = (ddx+ddy)%2 == 1;
		if( odd ) dy--;
		int dxr = Math.abs((dx-dy)/2), dyr = Math.abs((dx+dy)/2);
		return dxr+dyr+(odd?1:0);
	}
}
