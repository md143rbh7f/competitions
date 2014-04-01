import java.io.*;
import java.math.*;
import java.util.*;

public class Letter
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		int k = in.nextInt(), x = in.nextInt(), n = in.nextInt(), m = in.nextInt();
		int[] sc = new int[k + 1], ea = new int[k + 1];
		long[] cnt = new long[k + 1];
		for(sc[1] = 0; sc[1] < 2; sc[1]++)
		for(ea[1] = 0; ea[1] < 2; ea[1]++)
		for(cnt[1] = 0; 2 * cnt[1] <= n; cnt[1]++)
		if(sc[1] + ea[1] + 2 * cnt[1] <= n)
		for(sc[2] = 0; sc[2] < 2; sc[2]++)
		for(ea[2] = 0; ea[2] < 2; ea[2]++)
		for(cnt[2] = 0; 2 * cnt[2] <= m; cnt[2]++)
		if(sc[2] + ea[2] + 2 * cnt[2] <= m)
		{
			for(int i = 3; i <= k; i++)
			{
				cnt[i] = cnt[i-2] + cnt[i-1] + (ea[i-2] & sc[i-1]);
				sc[i] = sc[i-2];
				ea[i] = ea[i-1];
			}
			if(cnt[k] == x)
			{
				print(n, sc[1], cnt[1], ea[1]);
				print(m, sc[2], cnt[2], ea[2]);
				return;
			}
		}
		System.out.println("Happy new year!");
	}

	static void print(int len, int sc, long cnt, int ea)
	{
		char[] s = new char[len];
		Arrays.fill(s, 'X');
		int i = 0;
		if(sc == 1) s[i++] = 'C';
		if(ea == 1) s[len - 1] = 'A';
		while(cnt --> 0)
		{
			s[i++] = 'A';
			s[i++] = 'C';
		}
		System.out.println(new String(s));
	}
}
