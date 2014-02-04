import java.io.*;
import java.math.*;
import java.util.*;

public class Dima
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	static char[] next = new char[128];
	static
	{
		next['D'] = 'I';
		next['I'] = 'M';
		next['M'] = 'A';
		next['A'] = 'D';
	}
	static int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};

	public static void main(String[] args)
	{
		int n = in.nextInt(), m = in.nextInt();
		char[][] board = new char[n][];
		for(int i = 0; i < n; i++) board[i] = in.next().toCharArray();

		int[][] parentCount = new int[n][m];
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) for(int d = 0; d < 4; d++)
		{
			int ii = i + dx[d], jj = j + dy[d];
			if(ii < 0 || ii >= n || jj < 0 || jj >= m || board[ii][jj] != next[board[i][j]])
				continue;
			parentCount[ii][jj]++;
		}

		ArrayList<int[]> q = new ArrayList<int[]>();
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(parentCount[i][j] == 0)
			q.add(new int[]{i, j});

		int qi = 0;
		for(; qi < q.size(); qi++)
		{
			int i = q.get(qi)[0], j = q.get(qi)[1];
			for(int d = 0; d < 4; d++)
			{
				int ii = i + dx[d], jj = j + dy[d];
				if(ii < 0 || ii >= n || jj < 0 || jj >= m || board[ii][jj] != next[board[i][j]])
					continue;
				parentCount[ii][jj]--;
				if(parentCount[ii][jj] == 0) q.add(new int[]{ii, jj});
			}
		}

		if(qi < n * m)
		{
			System.out.println("Poor Inna!");
			return;
		}

		int[][] best = new int[n][m];
		int ans = 0;
		for(qi--; qi >= 0; qi--)
		{
			int i = q.get(qi)[0], j = q.get(qi)[1];
			for(int d = 0; d < 4; d++)
			{
				int ii = i + dx[d], jj = j + dy[d];
				if(ii < 0 || ii >= n || jj < 0 || jj >= m || board[ii][jj] != next[board[i][j]])
					continue;
				best[i][j] = Math.max(best[i][j], best[ii][jj]);
			}
			best[i][j]++;
			if(board[i][j] == 'D') ans = Math.max(ans, best[i][j]);
		}

		if(ans < 4) System.out.println("Poor Dima!");
		else System.out.println(ans / 4);
	}
}
