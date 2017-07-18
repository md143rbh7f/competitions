import java.io.*;
import java.math.*;
import java.util.*;

public class TextRoll
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		while(new TextRoll().solve());
	}

	boolean solve()
	{
		int n = Integer.parseInt(in.nextLine());
		if(n == 0) return false;
		int ans = 0;
		while(n --> 0) ans = Math.max(ans, (in.nextLine() + " ").indexOf(" ", ans));
		System.out.println(ans + 1);
		return true;
	}
}
