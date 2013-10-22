#include <iostream>

using namespace std;

typedef long long ll;
#define MOD 1000000007
#define M(x) ((x)%MOD)

struct matrix { ll a, b, c, d; };

matrix I{1, 0, 0, 1};

matrix operator*(matrix s, matrix t)
{
	return
	{
		M(s.a * t.a + s.b * t.c),
		M(s.a * t.b + s.b * t.d),
		M(s.c * t.a + s.d * t.c),
		M(s.c * t.b + s.d * t.d)
	};
}

matrix operator^(matrix s, int n)
{
	if(!n) return I;
	return ((s * s)^(n/2)) * (n % 2 ? s : I);
}

int main()
{
	int n;
	cin >> n;
	cout << (matrix{0, 1, 3, 2}^n).a << endl;
	return 0;
}
