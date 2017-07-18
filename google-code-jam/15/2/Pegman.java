import java.io.*;
import java.math.*;
import java.util.*;

public class Pegman
{
static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
static int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

public static void main(String[] args)
{
	int t = in.nextInt();
	for(int i = 1; i <= t; i++)
		System.out.printf("Case #%d: %s\n", i, new Pegman().work());
}

int n, m, dirs[][];

boolean ok(int i, int j, int dir)
{
	i += dx[dir];
	j += dy[dir];
	while(i >= 0 && i < n && j >= 0 && j < m)
	{
		if(dirs[i][j] != -1)
			return true;
		i += dx[dir];
		j += dy[dir];
	}
	return false;
}

String work()
{
	n = in.nextInt();
	m = in.nextInt();
	dirs = new int[n][m];
	for(int i = 0; i < n; i++)
	{
		String s = in.next();
		for(int j = 0; j < m; j++)
		{
			char c = s.charAt(j);
			dirs[i][j] =
				c == '>' ? 0 :
				c == 'v' ? 1 :
				c == '<' ? 2 :
				c == '^' ? 3 :
				-1;
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	if(dirs[i][j] != -1)
	{
		boolean can = false;
		for(int dir = 0; dir < 4; dir++)
		{
			if(ok(i, j, dir))
				can = true;
			else if(dir == dirs[i][j])
				ans++;
		}
		if(!can) return "IMPOSSIBLE";
	}

	return "" + ans;
}
}
