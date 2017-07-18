import java.io.*;
import java.util.*;
import java.awt.Point;

public class OceanCurrents
{
	static final int INF = 1<<23;
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	// N NE E SE S SW W NW
	static int[] DY = { -1, -1, 0, 1, 1, 1, 0, -1 };
	static int[] DX = { 0, 1, 1, 1, 0, -1, -1, -1 };

	static int[][] D;

	public static void main( String[] args )
	{
		int Y = in.nextInt(), X = in.nextInt();
		in.nextLine();

		char[][] map = new char[Y][];
		for( int i = 0; i < Y; i++ )
		{
			map[i] = in.nextLine().toCharArray();
			for( int j = 0; j < X; j++ ) map[i][j] -= '0';
		}
		D = new int[Y][X];
		LinkedList<Point> q = new LinkedList<Point>();

		int C = in.nextInt();
		for( int c = 0; c < C; c++ )
		{
			int y0 = in.nextInt()-1, x0 = in.nextInt()-1, y1 = in.nextInt()-1, x1 = in.nextInt()-1;
			
			for( int i = 0; i < Y; i++ ) for( int j = 0; j < X; j++ ) D[i][j] = INF;
			D[y0][x0] = 0;
			q.add( new Point( x0, y0 ) );

			while( !q.isEmpty() )
			{
				Point p = q.pollFirst();
				for( int dir = 0; dir < 8; dir++ )
				{
					int ty = p.y + DY[dir], tx = p.x + DX[dir];
					int edge = dir == map[p.y][p.x] ? 0 : 1, dist = D[p.y][p.x] + edge;
					if( ty < 0 || ty >= Y || tx < 0 || tx >= X || D[ty][tx] <= dist ) continue;
					D[ty][tx] = dist;
					Point next = new Point( tx, ty );
					if( edge == 0 ) q.push( next );
					else q.add( next );
				}
			}

			System.out.println( D[y1][x1] );
		}
	}
}
