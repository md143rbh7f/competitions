#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 2505

double p0[N], p1[N];

void get(int a, int b, double * p)
{
	p[0] = 1;
	rep(t, a) for(int i = t * b; i >= t; i--)
	{
		range(j, 1, b + 1) p[i + j] += p[i] / b;
		p[i] = 0;
	}
}

struct FixedDiceGameDiv1
{
double getExpectation(int a, int b, int c, int d)
{
	get(a, b, p0), get(c, d, p1);
	double s = 0, p = 0, t = 0;
	rep(i, a * b + 1)
	{
		p += p0[i] * s;
		t += p0[i] * s * i;
		s += p1[i];
	}
	return p ? t / p : -1;
}
};
