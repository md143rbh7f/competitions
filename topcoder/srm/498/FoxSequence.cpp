#include <string>
#include <vector>

using namespace std;

int d[50];

struct FoxSequence
{
	string isValid( vector<int> seq )
	{
		int n = seq.size(), x = 1;
		for( int i = 0; i+1 < n; i++ ) d[i] = seq[i+1]-seq[i];
		if( d[0] <= 0 ) return "NO";
		while( x+1 < n && d[x] == d[x-1] ) x++;
		if( x+1 == n || d[x] >= 0 ) return "NO";
		x++;
		while( x+1 < n && d[x] == d[x-1] ) x++;
		while( x+1 < n && d[x] == 0 ) x++;
		if( x+1 == n || d[x] <= 0 ) return "NO";
		x++;
		while( x+1 < n && d[x] == d[x-1] ) x++;
		if( x+1 == n || d[x] >= 0 ) return "NO";
		x++;
		while( x+1 < n && d[x] == d[x-1] ) x++;
		if( x+1 != n ) return "NO";
		return "YES";
	}
};
