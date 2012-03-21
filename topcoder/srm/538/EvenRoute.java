public class EvenRoute
{
	public String isItPossible( int[] x, int[] y, int parity )
	{
		for( int i = 0; i < x.length; i++ ) if( Math.abs( ( x[i] + y[i] ) % 2 ) == parity ) return "CAN";
		return "CANNOT";
	}
}
