import java.io.*;
import java.math.*;
import java.util.*;

public class PegSolitaire
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	static boolean[][] hole = new boolean[5][9];
	static
	{
		hole[0][0] = hole[0][1] = hole[0][2] =
		hole[0][6] = hole[0][7] = hole[0][8] =
		hole[4][0] = hole[4][1] = hole[4][2] =
		hole[4][6] = hole[4][7] = hole[4][8] =
		true;
	}
	static int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};

	public static void main(String[] args)
	{
		for(int n = in.nextInt(); n --> 0;) new PegSolitaire().run();
	}

	int bestCount = 9001, bestMoves = 9001;

	void dfs(boolean[][] peg, int count, int moves)
	{
		if(count < bestCount || count == bestCount && moves < bestMoves)
		{
			bestCount = count;
			bestMoves = moves;
		}
		for(int i0 = 0; i0 < 5; i0++) for(int j0 = 0; j0 < 9; j0++)
		if(peg[i0][j0]) for(int d = 0; d < 4; d++)
		{
			int i1 = i0 + dx[d], j1 = j0 + dy[d];
			int i2 = i1 + dx[d], j2 = j1 + dy[d];
			if(i2 < 0 || i2 > 4 || j2 < 0 || j2 > 8 || !peg[i1][j1] || peg[i2][j2] || hole[i2][j2])
				continue;
			boolean[][] next = new boolean[5][9];
			for(int i = 0; i < 5; i++) for(int j = 0; j < 9; j++) next[i][j] = peg[i][j];
			next[i0][j0] = next[i1][j1] = false;
			next[i2][j2] = true;
			dfs(next, count - 1, moves + 1);
		}
	}

	void run()
	{
		boolean[][] peg = new boolean[5][9];
		int count = 0;
		for(int i = 0; i < 5; i++)
		{
			String s = in.next();
			for(int j = 0; j < 9; j++) if(s.charAt(j) == 'o')
			{
				count++;
				peg[i][j] = true;
			}
		}
		dfs(peg, count, 0);
		System.out.printf("%d %d\n", bestCount, bestMoves);
	}
}
