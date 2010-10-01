import java.math.*;

public class BestApproximationDiv2
{
	BigDecimal BASE;
	
	int match( int a, String n )
	{
		String approx = new BigDecimal(a).setScale(50).divide( BASE, BigDecimal.ROUND_DOWN ).toPlainString();
		int l = 1;
		for( int i = 2; i < n.length(); i++ )
		{
			if( (i<approx.length()&&approx.charAt(i)==n.charAt(i)) || (i>=approx.length()&&n.charAt(i)=='0') ) l++;
			else break;
		}
		return l;
	}

	public String findFraction( int maxDen, String number )
	{
		double num = Double.parseDouble(number);
		int B = 0, A = 0, best = 0;
		for( int b = 1; b <= maxDen; b++ )
		{
			BASE = new BigDecimal(b);
			int aa = (int)Math.ceil(num*b);
			for( int g = aa-1; g <= aa; g++ ) if(g>=0&&g<b)
			{
				int ma = match(g,number);
				if( ma > best )
				{
					best = ma;
					A = g;
					B = b;
				}
			}
		}
		return A+"/"+B+" has "+best+" exact digits";
	}
}
