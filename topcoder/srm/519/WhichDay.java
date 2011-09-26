import java.util.*;

public class WhichDay
{
	public String getDay( String[] args )
	{
		HashSet<String> days = new HashSet<String>();
		days.add( "Monday" );
		days.add( "Tuesday" );
		days.add( "Wednesday" );
		days.add( "Thursday" );
		days.add( "Friday" );
		days.add( "Saturday" );
		days.add( "Sunday" );
		for( String s : args ) days.remove( s );
		String ans = "";
		for( String s : days ) ans = s;
		return ans;
	}
}
