public class Time
{
	public String whatTime( int s )
	{
		return String.format( "%d:%d:%d", s / 3600, ( s / 60 ) % 60, s % 60 );
	}
}
