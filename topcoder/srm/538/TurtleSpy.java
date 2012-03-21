public class TurtleSpy
{
	int N = 360;
	
	public double maxDistance( String[] cmds )
	{
		double a = 0, b = 0;
		boolean ok[] = new boolean[N];
		ok[0] = true;
		for( String s : cmds )
		{
			String[] cmd = s.split( " " );
			int v = Integer.parseInt( cmd[1] );
			if( cmd[0].equals( "right" ) )
			{
				boolean ok2[] = new boolean[N];
				for( int i = 0; i < N; i++ ) if( ok[i] )
				{
					ok2[i] = true;
					ok2[(i+v)%N] = true;
				}
				ok = ok2;
			}
			else if( cmd[0].equals( "left" ) )
			{
				boolean ok2[] = new boolean[N];
				for( int i = 0; i < N; i++ ) if( ok[i] )
				{
					ok2[i] = true;
					ok2[(i-v+N)%N] = true;
				}
				ok = ok2;
			}
			else if( cmd[0].equals( "forward" ) ) a += v;
			else if( cmd[0].equals( "backward" ) ) b += v;
		}
		double best = 0;
		for( int i = 0; i < N/2; i++ ) if( ok[N/2-i] || ok[N/2+i] )
		{
			best = ( N / 2 - i ) * Math.PI / 180;
			break;
		}
		return Math.sqrt( a * a + b * b - 2 * a * b * Math.cos( best ) );
	}
}
