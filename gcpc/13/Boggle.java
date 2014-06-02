import java.io.*;
import java.math.*;
import java.util.*;

public class Boggle
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	static Trie trie = new Trie();
	static int[] scores = {0, 0, 0, 1, 1, 2, 3, 5, 11};

	static class Trie
	{
		Trie[] c = new Trie[26];
		boolean end = false, found = false;

		void clear()
		{
			found = false;
			for(Trie x : c) if(x != null) x.clear();
		}

		void addWord(String w, int i)
		{
			if(i == w.length()) end = true;
			else
			{
				char x = (char)(w.charAt(i) - 'A');
				if(c[x] == null) c[x] = new Trie();
				c[x].addWord(w, i + 1);
			}
		}
	}

	public static void main(String[] args)
	{
		for(int n = in.nextInt(); n --> 0;) trie.addWord(in.next(), 0);
		for(int n = in.nextInt(); n --> 0;) new Boggle().run();
	}

	char[] stack = new char[8], board[] = new char[4][];
	boolean[][] seen = new boolean[4][4];
	String longest = "";
	int score = 0, found = 0;

	void dfs(int i, int j, int len, Trie t)
	{
		if(i < 0 || i > 3 || j < 0 || j > 3 || seen[i][j]) return;
		char c = board[i][j];
		t = t.c[c];
		if(t == null) return;
		seen[i][j] = true;
		stack[len] = (char)(c + 'A');
		len++;
		if(t.end && !t.found)
		{
			t.found = true;
			score += scores[len];
			found++;
			if(len > longest.length()) longest = new String(stack, 0, len);
			else if(len == longest.length())
			{
				String s = new String(stack, 0, len);
				if(s.compareTo(longest) < 0) longest = s;
			}
		}
		for(int di = -1; di <= 1; di++) for(int dj = -1; dj <= 1; dj++)
			dfs(i + di, j + dj, len, t);
		seen[i][j] = false;
	}

	void run()
	{
		for(int i = 0; i < 4; i++) board[i] = in.next().toCharArray();
		for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) board[i][j] -= 'A';
		for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) dfs(i, j, 0, trie);
		System.out.printf("%d %s %d\n", score, longest, found);
		trie.clear();
	}
}
