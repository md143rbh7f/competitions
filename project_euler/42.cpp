#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define MAX 100

char buf[MAX];
int ans, i, s;
set<int> tri;

int main()
{
	for( i = 1; i < MAX; i++ ) tri.insert( i*(i+1)/2 );
	while(1)
	{
		cin.getline( buf, MAX, ',' );
		if(cin.fail()) break;
		for( s = 0, i = 1; buf[i] != '"'; s += buf[i]-'A'+1, i++ );
		if(tri.count(s)) ans++;
	}
	cout << ans << endl;
	return 0;
}
