#include <cstdio>
#include <set>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define MAX 5000

set<int> p;
int i, j, I, J;

int main()
{
	for( i = 1; i < MAX; i++ ) p.insert( i*(3*i-1)/2 );
	foreach(i,p) foreach(j,p)
	{
		I = *i, J = *j;
		if(I==J) break;
		if( p.count(I-J) && p.count(I+J) ) printf( "%d\n", I-J ), i = j = p.end();
	}
	return 0;
}
