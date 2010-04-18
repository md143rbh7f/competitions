import java.math.*;
import java.util.*;

public class LateProfessor
{
	public double getProbability( int wait, int walk, int late, int start, int end )
	{
		if( late>=walk ) return 0;
		int times = 0, ww = walk+wait;
		if( start==end ) return start%ww>wait && (start%ww)+late<=ww ? 1 : 0;
		for( int t = start; t < end; t++ )
			if( (t%ww)+0.5>wait && (t%ww)+late+0.5<ww )
				times++;
		return 1.0*times/(end-start);
	}
}
