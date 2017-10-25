import java.util.*;

public class Balls {
	static int N = 51, M = 1001, best[][] = new int[N][M];

	public static void main(String[] args) {
		for (int j = 1; j < M; j++) best[1][j] = j;
		for (int i = 2; i < N; i++) for (int j = 1, k = 1; j < M; j++) {
			while (k < j && best[i - 1][k - 1] < best[i][j - k]) k++;
			best[i][j] = 1 + best[i - 1][k - 1];
		}

		Scanner in = new Scanner(System.in);
		int c = in.nextInt();
		for (int i = 0; i < c; i++)
			System.out.println(in.nextInt() + " " + best[in.nextInt()][in.nextInt()]);
	}
}
