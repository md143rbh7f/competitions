import java.io.*;
import java.math.*;
import java.util.*;

public class Playlist
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		int n = in.nextInt();
		final int len[] = new int[n];
		final double[] p = new double[n];
		Integer ord[] = new Integer[n];
		for(int i = 0; i < n; i++)
		{
			len[i] = in.nextInt();
			p[i] = 0.01 * in.nextInt();
			ord[i] = i;
		}
		Arrays.sort(ord, new Comparator<Integer>()
		{
			public int compare(Integer a, Integer b)
			{
				return Double.compare(
					(1 - p[a]) * p[b] * len[b],
					(1 - p[b]) * p[a] * len[a]
				);
			}
		});

		double ans = 0, sum = 0;
		for(int i = 0; i < n; i++)
		{
			int j = ord[i];
			ans += len[j] + (1 - p[j]) * sum;
			sum += p[j] * len[j];
		}
		System.out.printf("%.11f\n", ans);
	}
}
