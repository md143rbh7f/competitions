public class MagicDiamonds
{
	public long minimalTransfer( long a )
	{
		if( a <= 3 ) return a;
		for( long i = 2; i * i <= a; i++ ) if( a % i == 0 ) return 1;
		return 2;
	}
}
