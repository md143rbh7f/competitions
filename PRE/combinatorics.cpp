/*
	Compute various combinatorial quantities modulo MOD.
*/

ll fac[N];
int choose[N][N];
int part[N][N];
int dist_part[N][K];


	// Factorial
	fac[0] = 1;
	range(n, 1, N) fac[n] = M(n * fac[n-1]);

	// n choose k
	rep(n, N) choose[n][0] = 1;
	range(n, 1, N) range(k, 1, n + 1)
		choose[n][k] = M(choose[n-1][k] + choose[n-1][k-1]);
	
	// Partitions of n consisting of k integers
	range(n, 1, N) part[n][1] = 1;
	range(n, 1, N) range(k, 2, n + 1)
		part[n][k] = M(part[n-k][k] + part[n-1][k-1]);

	// Partitions of n consisting of k distinct integers
	// (We can compute dist_part[n][k] = part[n - choose[k][2]][k], but since
	// the largest K is asymptotically small compared to N, directly computing
	// dist_part saves time and memory.)
	range(n, 1, N) dist_part[n][1] = 1;
	range(n, 1, N) range(k, 2, K)
		dist_part[n][k] = M(dist_part[n-k][k] + dist_part[n-k][k-1]);
