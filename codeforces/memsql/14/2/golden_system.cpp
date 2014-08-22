#include <iostream>
#include <string>

using namespace std;

#define N 100005

bool x[N], y[N];

void read(bool * t)
{
	string s;
	cin >> s;
	int n = s.size();
	for(int i = n - 1; i >= 0; i--)
	{
		t[i] = s[n - i - 1] - '0';
		for(int j = i; t[j] && t[j + 1]; j += 2)
			t[j] = t[j + 1] = false, t[j + 2] = true;
	}
}

string cmp()
{
	for(int i = N - 1; i >= 0; i--)
	{
		if(x[i] > y[i]) return ">";
		if(x[i] < y[i]) return "<";
	}
	return "=";
}

int main()
{
	read(x), read(y);
	cout << cmp();
	return 0;
}
