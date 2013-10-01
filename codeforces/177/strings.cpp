#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	if(k > n || (n > 1 && k == 1)) cout << "-1" << endl;
	else if(n == 1 && k == 1) cout << "a" << endl;
	else
	{
		for(int i = 0; i < n - k + 2; i++) cout << (char)('a' + (i % 2));
		for(int i = 2; i < k; i++) cout << (char)('a' + i);
		cout << endl;
	}
	return 0;
}
