public class CatAndRabbit
{
	public String getWinner( String s )
	{
		if( s.indexOf( '#' ) == -1 ) return "Rabbit";
		String[] t = s.split( "#" );
		int ans = 0;
		for( String u : t ) ans ^= u.length();
		return ans > 0 ? "Cat" : "Rabbit";
	}
}
