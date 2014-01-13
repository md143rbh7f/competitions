#include <iostream>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 510005

bool ok[N];

int main()
{
	int n, d, m = 0;
	cin >> n >> d;
	ok[0] = true;
	rep(i, n)
	{
		int c;
		cin >> c;
		for(int j = m; j >= 0; j--) ok[j+c] |= ok[j];
		m += c;
	}
	int a = 0, b = 0;
	while(1)
	{
		int c = a + d;
		while(c >= a && !ok[c]) c--;
		if(c == a) break;
		a = c, b++;
	}
	cout << a << " " << b << endl;
	return 0;
}
