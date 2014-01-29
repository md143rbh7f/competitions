import java.io.*;
import java.math.*;
import java.util.*;

public class BitOperations
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	static int n, m, k, val[];

	public static void main(String[] args)
	{
		n = in.nextInt();
		m = in.nextInt();
		k = 1<<n;
		val = new int[2*k];
		for(int i = 0; i < k; i++) update(i, in.nextInt());
		while(m --> 0)
		{
			update(in.nextInt() - 1, in.nextInt());
			System.out.println(val[1]);
		}
	}

	static void update(int i, int x)
	{
		boolean or = true;
		i += k;
		val[i] = x;
		while((i /= 2) > 0)
		{
			int a = val[2 * i], b = val[2 * i + 1];
			if(or) val[i] = a | b;
			else val[i] = a ^ b;
			or = !or;
		}
	}
}
