import java.io.*;
import java.math.*;
import java.util.*;

public class Bookshelf
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		int n = in.nextInt(), m = 2 * n + 1;
		boolean[][] possible = new boolean[m][m];
		possible[0][0] = true;
		while(n --> 0)
		{
			int t = in.nextInt(), w = in.nextInt();
			for(int T = m - 1; T >= 0; T--) for(int W = m - 1; W >= 0; W--)
				possible[T][W] = (T >= t ? possible[T-t][W] : false) || (W >= w ? possible[T][W-w] : false);
		}
		for(int T = 0; T < m; T++) for(int W = 0; W <= T; W++) if(possible[T][W])
		{
			System.out.println(T);
			return;
		}
	}
}
