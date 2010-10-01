public class BestApproximationDiv1
{
	int match( int a, int b, String n )
	{
		if( a>=b ) return 0;
		String approx = ""+(1.0*a/b)+"000000";
		int l = 0;
		for( int i = 1; i < n.length(); i++ )
		{
			if( approx.charAt(i)==n.charAt(i) ) l++;
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
			int ac = (int)Math.ceil(num*b), af = (int)Math.floor(num*b);
			if( match(af,b,number) > best )
			{
				best = match(af,b,number);
				A = af;
				B = b;
			}
			if( match(ac,b,number) > best )
			{
				best = match(ac,b,number);
				A = ac;
				B = b;
			}
		}
		return A+"/"+B+" has "+best+" exact digits";
	}
}
