#include <algorithm>
#include <iostream>

using namespace std;

int t[10005], k, n0, n1, n2, t0, t1, t2;

int main()
{
	cin >> k >> n0 >> n1 >> n2 >> t0 >> t1 >> t2;
	for(int i = 1; i <= k; i++)
	{
		if(i > n0) t[i] = max(t[i], t[i - n0] + t0);
		if(i > n1) t[i] = max(t[i], t[i - n1] + t1);
		if(i > n2) t[i] = max(t[i], t[i - n2] + t2);
	}
	cout << t[k] + t0 + t1 + t2 << endl;
	return 0;
}
