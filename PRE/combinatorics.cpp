/*
	Compute various combinatorial quantities modulo MOD.
*/

ll fac[N];
int choose[N][N];
int part[N][N];
int dist_part[N][K];

	// Factorial
	fac[0] = 1;
	range(i, 1, N) fac[i] = M(i * fac[i-1]);

	// i choose j
	rep(i, N) choose[i][0] = 1;
	range(i, 1, N) range(j, 1, i + 1)
		choose[i][j] = M(choose[i-1][j] + choose[i-1][j-1]);
	
	// Partitions of i consisting of j integers
	range(i, 1, N) part[i][1] = 1;
	range(i, 1, N) range(j, 2, i + 1)
		part[i][j] = M(part[i-j][j] + part[i-1][j-1]);

	// Partitions of i consisting of j distinct integers
	// (We can compute dist_part[i][j] = part[i - choose[j][2]][j], but since
	// the largest K is asymptotically small compared to N, directly computing
	// dist_part saves time and memory.)
	range(i, 1, N) dist_part[i][1] = 1;
	range(i, 1, N) range(j, 2, K)
		dist_part[i][j] = M(dist_part[i-j][j] + dist_part[i-j][j-1]);


// Logarithmic versions of factorial and choose

ld log_fac[M];

inline ld log_choose(int i, int j)
{
	return i >= j ? log_fac[i] - log_fac[j] - log_fac[i - j] : 0;
}

	range(i, 1, m + 1)
		log_fac[i] = log_fac[i - 1] + log(i);

