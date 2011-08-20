public class RotatedClock
{
	public String getEarliest( int ha, int ma )
	{
		int min = 2 * ( ha % 30 );
		ha -= ha % 30;
		for( int i = 0; i < 12; i++ )
			if( ( ma - ha + i * 30 + 360 ) % 360 == 6 * min )
				return ( i < 10 ? "0" : "" ) + i + ":" + ( min < 10 ? "0" : "" ) + min;
		return "";
	}
}
