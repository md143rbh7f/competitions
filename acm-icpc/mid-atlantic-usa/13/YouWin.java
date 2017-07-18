import java.io.*;
import java.math.*;
import java.util.*;

public class YouWin
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	static int C = 26, INF = 1234567890;

	public static void main(String[] args)
	{
		while(new YouWin().solve());
	}

	boolean solve()
	{
		String _x = in.next();
		if(_x.equals("0")) return false;
		int n = _x.length(), m = 1<<n, x[] = new int[n], d[][] = new int[m][n];
		for(int i = 0; i < n; i++) x[i] = _x.charAt(i) - 'A';
		for(int s = 0; s < m; s++) Arrays.fill(d[s], INF);
		for(int i = 0; i < n; i++) d[1<<i][i] = 1 + Math.min(x[i], C - x[i]);
		for(int s = 0; s < m; s++)
		for(int i = 0; i < n; i++) if((1&(s>>i)) == 1)
		for(int j = 0; j < n; j++) if((1&(s>>j)) == 0)
			d[s^(1<<j)][j] = Math.min(
				d[s^(1<<j)][j],
				d[s][i]
				+ Integer.bitCount(s & ((2<<Math.max(i, j)) - (2<<Math.min(i, j))))
				+ Math.min((C + x[i] - x[j]) % C, (C + x[j] - x[i]) % C)
				+ 1
			);
		int ans = INF;
		for(int t : d[m-1]) ans = Math.min(ans, t);
		System.out.println(ans);
		return true;
	}
}
