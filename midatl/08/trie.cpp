#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string,int> save, size, first;
string s;

int rec( int i )
{
	if( s[i] == '#' ) return i + 1;

	int j = rec( rec( i + 1 ) );
	string t = s.substr( i, j - i );

	if( !save.count( t ) )
	{
		int sz = 0;
		for( int k = 0; k < t.size(); k++ ) sz += t[k] != '#';
		size[t] = sz;
		first[t] = i;
		save[t] = 0;
	}
	else
	{
		save[t] += size[t];
		first[t] = min( first[t], i );
	}

	return j;
}

bool better( string & a, string & b )
{
	if( save[a] > save[b] ) return true;
	if( save[a] < save[b] ) return false;
	if( size[a] < size[b] ) return true;
	if( size[a] > size[b] ) return false;
	if( first[a] < first[b] ) return true;
	return false;
}

void run()
{
	save.clear(), size.clear(), first.clear();
	rec( 0 );
	
	string ans = save.begin()->first;
	for( map<string,int>::iterator it = save.begin(); it != save.end(); it++ )
	{
		string t = it->first;
		if( better( t, ans ) ) ans = t;
	}

	cout << ans << " " << save[ans] << endl;
}

int main()
{
	for(;;)
	{
		cin >> s;
		if( s == "END" ) break;
		run();
	}
	return 0;
}
