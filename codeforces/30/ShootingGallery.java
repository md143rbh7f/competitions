import java.io.*;
import java.math.*;
import java.util.*;

public class ShootingGallery
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		int n = in.nextInt();
		Target[] ts = new Target[n];
		for(int i = 0; i < n; i++) ts[i] = new Target();
		Arrays.sort(ts);
		double ans = 0, best[] = new double[n];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < i; j++)
			if(Math.hypot(ts[i].x - ts[j].x, ts[i].y - ts[j].y) <= ts[i].t - ts[j].t)
				best[i] = Math.max(best[i], best[j]);
			ans = Math.max(ans, best[i] += ts[i].p);
		}
		System.out.printf("%.10f\n", ans);
	}

	static class Target implements Comparable<Target>
	{
		int x, y, t;
		double p;

		Target()
		{
			x = in.nextInt();
			y = in.nextInt();
			t = in.nextInt();
			p = in.nextDouble();
		}

		public int compareTo(Target o)
		{ return Integer.compare(t, o.t); }
	}
}
