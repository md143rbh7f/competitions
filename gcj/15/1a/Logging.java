import java.io.*;
import java.math.*;
import java.util.*;

public class Logging
{
static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
static double EPS = 1e-14;

public static void main(String[] args)
{
	int c = in.nextInt();
	for(int i = 1; i <= c; i++) new Logging().solve(i);
}

void solve(int caseNum)
{
	int n = in.nextInt();

	int[] xs = new int[n], ys = new int[n];
	for(int i = 0; i < n; i++)
	{
		xs[i] = in.nextInt();
		ys[i] = in.nextInt();
	}

	System.out.printf("Case #%d:\n", caseNum);

	for(int i = 0; i < n; i++)
	{
		ArrayList<Double> qs = new ArrayList<>();
		for(int k = 0; k < n; k++) if(k != i)
		{
			double q = Math.atan2(ys[k] - ys[i], xs[k] - xs[i]);
			qs.add(q);
			qs.add(q + 2 * Math.PI);
		}
		Collections.sort(qs);
		System.out.println(work(qs));
	}
}

int work(ArrayList<Double> qs)
{
	int n = qs.size() / 2, ans = n, i = 0, j = 1;
	while(i < n)
	{
		while(qs.get(j) - qs.get(i) < Math.PI - EPS)
			j++;
		ans = Math.min(ans, j - i - 1);
		i++;
	}
	return ans;
}
}
