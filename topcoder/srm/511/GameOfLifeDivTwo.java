public class GameOfLifeDivTwo
{
	public String theSimulation( String init, int T )
	{
		int n = init.length();
		char s[][] = new char[2][n];
		for( int i = 0; i < n; i++ ) s[0][i] = init.charAt(i);
		for( int t = 0; t < T; t++ )
			for( int i = 0; i < n; i++ )
				s[1-(t%2)][i] = ( ( s[t%2][(i-1+n)%n] == '1' ? 1 : 0 ) + ( s[t%2][i] == '1' ? 1 : 0 ) + ( s[t%2][(i+1)%n] == '1' ? 1 : 0 ) ) >= 2 ? '1' : '0';
		return new String(s[T%2]);
	}
};
