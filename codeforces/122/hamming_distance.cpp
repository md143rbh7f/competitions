#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 6

int mat[N+1][N] =
{
	{1, 1, 0, 1, 0, 0},
	{1, 0, 1, 0, 1, 0},
	{0, 1, 1, 0, 0, 1},
	{0, 1, 1, 1, 1, 0},
	{1, 0, 1, 1, 0, 1},
	{1, 1, 0, 0, 1, 1},
	{0, 0, 0, 1, 1, 1}
};
int coeff[] = {1, 1, 1, -1, -1, -1, 1};
string strs[] = {"aaab", "aaba", "abaa", "aabb", "abab", "abba", "abbb"};

int main()
{
	vi hs(N), cs(N + 1);
	rep(i, N) cin >> hs[i];
	int l = 0;
	rep(i, N + 1)
	{
		rep(j, N) cs[i] += mat[i][j] * hs[j];
		if(cs[i] % 2)
		{
			cout << -1 << endl;
			return 0;
		}
		cs[i] /= 2;
		if(coeff[i] > 0) l = max(l, cs[i]), cs[i] *= -1;
	}
	rep(i, N + 1)
	{
		if(coeff[i] < 0 && l > cs[i])
		{
			cout << -1 << endl;
			return 0;
		}
		cs[i] += coeff[i] * l;
	}
	cout << l << endl;
	rep(j, 4)
	{
		rep(i, N + 1) rep(k, cs[i]) cout << strs[i][j];
		cout << endl;
	}
	return 0;
}
