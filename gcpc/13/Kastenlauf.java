import java.io.*;
import java.math.*;
import java.util.*;

public class Kastenlauf
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		for(int n = in.nextInt(); n --> 0;) new Kastenlauf().run();
	}

	boolean[] seen;
	int n, x[], y[];

	boolean dfs(int i)
	{
		if(seen[i]) return false;
		if(i == n + 1) return true;
		seen[i] = true;
		for(int j = 0; j <= n + 1; j++)
		if(Math.abs(x[i] - x[j]) + Math.abs(y[i] - y[j]) <= 1000 && dfs(j))
			return true;
		return false;
	}

	void run()
	{
		n = in.nextInt();
		seen = new boolean[n+2];
		x = new int[n+2];
		y = new int[n+2];
		for(int i = 0; i <= n + 1; i++)
		{
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		System.out.println(dfs(0) ? "happy" : "sad");
	}
}
