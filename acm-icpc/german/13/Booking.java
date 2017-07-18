import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Booking
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	static DateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm");

	public static void main(String[] args)
	{
		for(int n = in.nextInt(); n --> 0;) new Booking().run();
	}

	long nextTime()
	{
		try { return df.parse(in.next() + " " + in.next()).getTime(); }
		catch(Exception e) {}
		return -1;
	}

	void add(TreeMap<Long,Integer> deltas, long k, int v)
	{
		if(!deltas.containsKey(k)) deltas.put(k, v);
		else deltas.put(k, deltas.get(k) + v);
	}

	void run()
	{
		int b = in.nextInt(), c = in.nextInt();
		TreeMap<Long,Integer> deltas = new TreeMap<Long,Integer>();
		while(b --> 0)
		{
			String tmp = in.next();
			add(deltas, nextTime(), 1);
			add(deltas, nextTime() + c * 60 * 1000, -1);
		}
		int cur = 0, ans = 0;
		for(int v : deltas.values()) ans = Math.max(ans, cur += v);
		System.out.println(ans);
	}
}
