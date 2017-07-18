import java.io.*;
import java.math.*;
import java.util.*;

public class CutTheCake
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		while(new CutTheCake().run());
	}

	boolean run()
	{
		long r = in.nextInt(), x = in.nextInt(), y = in.nextInt(), n = in.nextInt();
		if(r == 0) return false;
		int ans = 1;
		ArrayList<long[]> lines = new ArrayList<long[]>();
		while(n --> 0)
		{
			long x0 = in.nextInt() - x, y0 = in.nextInt() - y, x1 = in.nextInt() - x, y1 = in.nextInt() - y;
			long cross = x0 * y1 - x1 * y0;
			long d2 = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
			boolean ok = cross * cross <= r * r * d2;
			if(!ok) continue;
			ans++;
			long a = y1 - y0, b = x0 - x1, c = a * x0 + b * y0;
			for(long[] line : lines)
			{
				double[] u = {a, b, c}, v = {line[0], line[1], line[2]};
				if(a == 0)
				{
					double[] w = v;
					v = u;
					u = w;
				}
				double y2 = (v[2] - u[2] / u[0] * v[0]) / (v[1] - u[1] / u[0] * v[0]);
				double x2 = u[2] / u[0] - u[1] / u[0] * y2;
				if(Math.hypot(x2, y2) <= r) ans++;
			}
			lines.add(new long[]{a, b, c});
		}
		System.out.println(ans);
		return true;
	}
}
