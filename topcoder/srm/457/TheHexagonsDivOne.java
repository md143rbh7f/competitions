import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class TheHexagonsDivOne
{
	public long count( int n )
	{
		BigInteger ans = ZERO;
		int[] r = new int[6], count = new int[6];
		outer: while( true )
		{
			boolean works = true;
			fill( count, 0 );
			for( int i = 0; i < 6; i++ ) if( r[i]==r[(i+1)%6] || (count[r[i]]++)==2 ) works = false;
			if( works )
			{
				int unique = 0;
				for( int i = 0; i < 6; i++ ) if( count[i]!=0 ) unique++;
				BigInteger add = new BigInteger( ""+1440*n );
				for( int i = 0; i < unique; i++ ) add = add.multiply( new BigInteger( ""+2*(n-i-1) ) );
				for( int i = 0; i < unique; i++ ) add = add.divide( new BigInteger( ""+6-i ) );
				ans = ans.add(add);
			}
			int ptr = 0;
			while( r[ptr] == 5 )
			{
				r[ptr] = 0;
				ptr++;
				if( ptr == 6 ) break outer;
			}
			r[ptr]++;
		}
		return ans.divide( new BigInteger(""+4320) ).longValue();
	}
}
