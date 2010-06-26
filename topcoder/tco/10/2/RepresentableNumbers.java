import java.util.*;

public class RepresentableNumbers
{
	public int getNext( int x )
	{
		if( x==1 ) return 2;
		if( x==2 ) return 2;
		if( x==3 ) return 4;
		ArrayList<Integer> o = new ArrayList<Integer>();
		int index = -1;
		for( int l = 1; l <= 9; l++ )
		{
			int[] val = new int[l];
			for( int i = 0; i < l; i++ ) val[i] = 1;
			outer: while( true )
			{
				int res = 0;
				for( int i = l-1; i >= 0; i-- ) res = 10*res+val[i];
				o.add(res);
				int ptr = 0;
				while( val[ptr] == 9 )
				{
					val[ptr] = 1;
					ptr++;
					if( ptr == l ) break outer;
				}
				val[ptr] += 2;
			}
		}
		int min = 1000000000;
		for( int i : o )
		{
			if( i>=x ) { if( i+1<min ) min = i+1; }
			else
			{
				int j = 0, d = 1<<23;
				while( (d>>=1)>0 ) if( j+d<o.size() && i+o.get(j+d)<x ) j += d;
				if( i+o.get(j+1)<min ) min = i+o.get(j+1);
			}
		}
		return min;
	}
}
