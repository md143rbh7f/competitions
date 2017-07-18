import java.io.*;
import java.util.*;

public class DataPacking
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		for(int i = 1, t = in.nextInt(); i <= t; i++)
			System.out.printf("Case #%d: %d\n", i, new DataPacking().solve());
	}

	int solve()
	{
		int n = in.nextInt(), x = in.nextInt(), s[] = new int[n];
		for(int i = 0; i < n; i++) s[i] = in.nextInt();
		Arrays.sort(s);
		int ans = n;
		for(int i = 0, j = n - 1; i < j; j--) if(s[i] + s[j] <= x)
		{
			ans--;
			i++;
		}
		return ans;
	}
}
