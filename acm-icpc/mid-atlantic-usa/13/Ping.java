import java.io.*;
import java.math.*;
import java.util.*;

public class Ping
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		while(new Ping().solve());
	}

	boolean solve()
	{
		String _s = in.next();
		if(_s.equals("0")) return false;
		int n = _s.length();
		boolean[] s = new boolean[n];
		for(int i = 0; i < n; i++) s[i] = _s.charAt(i) == '1';
		for(int i = 1; i < n; i++) if(s[i])
		{
			System.out.print(i + " ");
			for(int j = 0; j < n; j += i) s[j] = !s[j];
		}
		System.out.println();
		return true;
	}
}
