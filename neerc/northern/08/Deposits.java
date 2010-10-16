import java.io.*;
import java.math.*;
import java.util.*;

public class Deposits
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	static int MAX = 1000001, MAXN = 100001;
	static int A[] = new int[MAXN], occ[] = new int[MAX];
	static long cnt[] = new long[MAX];

	public static void main( String[] args )
	{
		int n = in.nextInt();
		for( int i = 0; i < n; i++ ) A[i] = in.nextInt();
		int m = in.nextInt();
		for( int i = 0; i < m; i++ ) occ[in.nextInt()]++;
		for( int b = 1; b < MAX; b++ ) for( int a = b; a < MAX; a += b ) cnt[a] += occ[b];
		long ans = 0;
		for( int i = 0; i < n; i++ ) ans += cnt[A[i]];
		System.out.println( ans );
	}
}
