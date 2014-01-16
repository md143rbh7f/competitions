import java.io.*;
import java.util.*;

public class Rectangles
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
		String[] grid = new String[n];
		for(int i = 0; i < n; i++) grid[i] = in.next();

		int[][] sum = new int[n + 1][m + 1];
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
			sum[i+1][j+1] = grid[i].charAt(j) - '0' + sum[i+1][j] + sum[i][j+1] - sum[i][j];

		int[][][][] cnt = new int[n+1][m+1][n+1][m+1];
		for(int h = 1; h <= n; h++) for(int w = 1; w <= m; w++)
		for(int i = 0; i + h <= n; i++) for(int j = 0; j + w <= m; j++)
		{
			int ans = sum[i+h][j+w] + sum[i][j] == sum[i+h][j] + sum[i][j+w] ? 1 : 0;
			for(int a = 0; a < 2; a++) for(int b = 0; b < 2; b++)
			for(int c = 0; c < 2; c++) for(int d = 0; d < 2; d++)
				ans += ((a + b + c + d) % 2 == 1 ? 1 : -1) * cnt[i+a][j+b][i+h-c][j+w-d];
			cnt[i][j][i+h][j+w] = ans;
		}

		while(q --> 0) System.out.println(cnt[in.nextInt()-1][in.nextInt()-1][in.nextInt()][in.nextInt()]);
	}
}
