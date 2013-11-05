import java.io.*;
import java.math.*;
import java.util.*;

public class CountYourCousins
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		while(new CountYourCousins().solve());
	}

	boolean solve()
	{
		int n = in.nextInt(), k = in.nextInt();
		if(n == 0) return false;
		int parent[] = new int[n], j = -2, m = 0, last = -1000;
		for(int i = 0; i < n; i++)
		{
			int x = in.nextInt();
			if(x != last + 1) j++;
			last = x;
			parent[i] = j;
			if(x == k) m = i;
		}
		int ans = 0, p = parent[m];
		if(p != -1)
		{
			int q = parent[p];
			if(q != -1) for(int i = 0; i < n; i++) if(parent[i] != p && parent[i] != -1 && parent[parent[i]] == q) ans++;
		}
		System.out.println(ans);
		return true;
	}
}
