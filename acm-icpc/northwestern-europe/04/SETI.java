import java.io.*;
import java.math.*;
import java.util.*;

public class SETI
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new SETI().solve( i );
	}

	void solve( int caseNum )
	{
		int p = in.nextInt();
		String msg = in.next();
		int n = msg.length(), b[] = new int[n], A[][] = new int[n][n];
		for( int i = 0; i < n; i++ )
		{
			if( msg.charAt(i)=='*' ) b[i] = 0;
			else b[i] = msg.charAt(i)-'a'+1;
		}
		for( int i = 0; i < n; i++ )
		{
			A[i][0] = 1;
			for( int j = 1; j < n; j++ ) A[i][j] = ((i+1)*A[i][j-1])%p;
		}
		int[] ans = gaussian_elim_mod(A,b,p);
		for( int i : ans ) System.out.print( i+" " );
		System.out.println();
	}

	static int[] extended_euclidean( int a, int b )
	{
		int x = 0, lx = 1, y = 1, ly = 0;
		while( b != 0 )
		{
			int t = a%b, q = a/b;
			a = b; b = t;
			t = x; x = lx-q*x; lx = t;
			t = y; y = ly-q*y; ly = t;
		}
		return new int[]{ lx, ly };
	}

	static int modulo_inverse( int a, int m )
	{
		int inv = extended_euclidean(a,m)[0];
		if( inv<0 ) inv += m;
		return inv;
	}

	static int[] gaussian_elim_mod( int[][] A, int[] b, int p )
	{
		int n = A.length;
		int a[][] = new int[n][n+1], temp[], scale, inv[] = new int[p];
		inv[1] = 1;
		for( int i = 2; i < p; i++ ) inv[i] = -1;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) a[i][j] = A[i][j];
		for( int i = 0; i < n; i++ ) a[i][n] = b[i];
		for( int i = 0; i < n; i++ )
		{
			for( int j = i; j < n && a[i][i] == 0; j++ )
				if( a[j][i] != 0 )
				{
					temp = a[j];
					a[j] = a[i];
					a[i] = temp;
				}
			if( inv[a[i][i]]==-1 )
			{
				inv[a[i][i]] = modulo_inverse(a[i][i],p);
				inv[inv[a[i][i]]] = a[i][i];
			}
			scale = inv[a[i][i]];
			for( int j = 0; j <= n; j++ ) a[i][j] = (scale*a[i][j])%p;
			for( int j = 0; j < n; j++ )
				if( i != j && a[j][i] != 0 )
				{
					scale = p-a[j][i];
					for( int k = 0; k <= n; k++ ) a[j][k] = (a[j][k]+scale*a[i][k])%p;
				}
		}
		int[] x = new int[n];
		for( int i = 0; i < n; i++ ) x[i] = a[i][n];
		return x;
	}
}
