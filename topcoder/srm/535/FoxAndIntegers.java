public class FoxAndIntegers
{
	public int[] get( int amb, int bmc, int apb, int bpc )
	{
		int a = ( amb + apb ) / 2, b = apb - a, c = bpc - b;
		return b - c == bmc && ( amb + apb ) % 2 == 0 ? new int[]{ a, b, c } : new int[0];
	}
}
