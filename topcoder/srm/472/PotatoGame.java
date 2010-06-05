public class PotatoGame
{
	public String theWinner( int n )
	{
		if( n%5==0 || n%5==2 ) return "Hanako";
		else return "Taro";
	}
}
