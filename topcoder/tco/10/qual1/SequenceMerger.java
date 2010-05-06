import java.math.*;
import java.util.*;

public class SequenceMerger
{
	int max = 1000000000, top = 1<<30;
	BigInteger MAX = new BigInteger( ""+max );

	public int[] getVal( String[] seqs, int[] p )
	{
		int n = seqs.length, m = p.length, ans[] = new int[m];
		LinkedList<BigInteger[]> a = new LinkedList<BigInteger[]>(), g = new LinkedList<BigInteger[]>(), e = new LinkedList<BigInteger[]>();
		for( int i = 0; i < n; i++ )
		{
			String[] sp = seqs[i].split(" ");
			BigInteger[] temp = new BigInteger[sp.length-1];
			for( int j = 1; j < sp.length; j++ ) temp[j-1] = new BigInteger(sp[j]);
			switch( sp[0].charAt(0) )
			{
				case 'A': a.add(temp); break;
				case 'G': g.add(temp); break;
				case 'E': Arrays.sort(temp); e.add(temp); break;
			}
		}
		for( int j = 0; j < m; j++ )
		{
			int d = top;
			while( (d>>=1)!=0 )
			{
				int test = d+ans[j], i = 0;
				BigInteger big = new BigInteger( ""+test );
				for( BigInteger[] s : a )
				{
					BigInteger temp = big.subtract(s[0]).add(s[1]).subtract(BigInteger.ONE).divide(s[1]);
					if( temp.compareTo(BigInteger.ZERO)>0 ) i += temp.min(s[2]).intValue();
					if( i > max ) i = max+1;
				}
				for( BigInteger[] s : g )
				{
					BigInteger temp = s[0], pow = BigInteger.ZERO;
					if( s[1].equals(BigInteger.ONE) )
					{
						if( temp.compareTo(big)<0 )
						{
							if( s[2].compareTo(MAX)<=0 ) i += s[2].intValue();
							else i = max+1;
						}
					}
					else while( temp.compareTo(big)<0 && pow.compareTo(s[2])<0 )
					{
						temp = temp.multiply(s[1]);
						pow = pow.add(BigInteger.ONE);
						i++;
					}
					if( i > max ) i = max+1;
				}
				for( BigInteger[] s : e )
				{
					int k = 0;
					while( k<s.length && s[k].compareTo(big)<0 ) k++;
					i += k;
					if( i > max ) i = max+1;
				}
				if( i < p[j] ) ans[j] = test;
			}
			if( ans[j]>max ) ans[j] = -1;
		}
		return ans;
	}
}
