#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 100

char buf[MAX];
vector<string> names;
int ans;

int main()
{
	while(1)
	{
		cin.getline( buf, MAX, ',' );
		if(cin.fail()) break;
		names.push_back( string( buf ) );
	}
	sort( names.begin(), names.end() );
	for( int i = 0; i < names.size(); i++ )
	{
		int s = 0;
		for( int j = 1; j < names[i].size()-1; j++ ) s += names[i][j]-'A'+1;
		ans += s*(i+1);
	}
	cout << ans << endl;
	return 0;
}
