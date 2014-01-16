import java.io.*;
import java.util.*;

public class Weights
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	static int N = 10;

	public static void main(String[] args)
	{
		String s = in.next();
		ArrayList<Integer> can = new ArrayList<>();
		for(int i = 0; i < N; i++) if(s.charAt(i) == '1') can.add(i + 1);

		int m = in.nextInt();
		int[][] prev = new int[m + 1][N + 1];
		prev[0][0] = 9001;
		for(int t = 0; t < m; t++) for(int i = 0; i <= N; i++) if(prev[t][i] > 0)
		for(int c : can) if(c > i && (prev[t][i] | (1<<c)) > (1<<c))
			prev[t + 1][c - i] |= 1<<c;

		int state = 0;
		for(int i = 0; i <= N; i++) if(prev[m][i] != 0)
			state = i;
		if(state == 0)
		{
			System.out.println("NO");
			return;
		}

		ArrayList<Integer> ans = new ArrayList<>();
		int move = 0;
		for(int t = m; t > 0; t--) for(int c : can) if(c != move && (prev[t][state] & (1<<c)) > 0)
		{
			ans.add(c);
			move = c;
			state = c - state;
			break;
		}
		Collections.reverse(ans);
		System.out.println("YES");
		for(int x : ans) System.out.print(x + " ");
	}
}
