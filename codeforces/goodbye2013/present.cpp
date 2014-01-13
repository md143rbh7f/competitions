#include <iostream>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 305

int a[N];

int main()
{
	int n, m = 0;
	cin >> n;
	rep(i, n)
	{
		cin >> a[i];
		if(!a[i]) m++;
	}
	int i = 0, dir = 1;
	while(1)
	{
		if(a[i])
		{
			a[i]--;
			cout << "P";
			if(!a[i]) m++;
		}
		if(m == n) break;
		if(i + dir < 0 || i + dir >= n) dir = -dir;
		i += dir;
		cout << (dir == 1 ? "R" : "L");
	}
	cout << endl;
	return 0;
}
