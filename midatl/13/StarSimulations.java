import java.io.*;
import java.math.*;
import java.util.*;

public class StarSimulations
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		while(new StarSimulations().solve());
	}

	class Point
	{
		long x, y, z;

		Point(long x, long y, long z)
		{
			this.x = x;
			this.y = y;
			this.z = z;
		}

		public int hashCode()
		{
			return (int)(1000000 * x + 1000 * y + z);
		}

		public boolean equals(Object o)
		{
			Point p = (Point) o;
			return x == p.x && y == p.y && z == p.z;
		}
	}

	int[] del = {-1, 0, 1};

	boolean solve()
	{
		int n = in.nextInt();
		long k = in.nextInt();
		if(n == 0) return false;
		HashMap<Point,ArrayList<Point>> pts = new HashMap<Point,ArrayList<Point>>();
		int ans = 0;
		while(n --> 0)
		{
			Point p = new Point(in.nextInt(), in.nextInt(), in.nextInt());
			for(int dx : del) for(int dy : del) for(int dz : del)
			{
				Point b = new Point(p.x / k + dx, p.y / k + dy, p.z / k + dz);
				if(pts.containsKey(b)) for(Point q : pts.get(b))
				if(
					(p.x - q.x) * (p.x - q.x)
					+ (p.y - q.y) * (p.y - q.y)
					+ (p.z - q.z) * (p.z - q.z)
					< k * k
				)
					ans++;
				if(dx == 0 && dy == 0 && dz == 0)
				{
					if(!pts.containsKey(b)) pts.put(b, new ArrayList<Point>());
					pts.get(b).add(p);
				}
			}
		}
		System.out.println(ans);
		return true;
	}
}
