#include <iostream>
#include <string>

using namespace std;

int p[10];
char grid[100][100];
string key, ctext;

int main()
{
	while(1)
	{
		cin >> key;
		if( key == "THEEND" ) break;
		cin >> ctext;
		int L = 0, nm = ctext.size(), n = key.size(), m = nm / n;
		for( char c = 'A'; c <= 'Z' ; c++ ) for( int i = 0; i < key.size(); i++ ) if( key[i] == c ) p[L++] = i;
		for( int j = 0; j < n; j++ ) for( int i = 0; i < m; i++ ) grid[i][p[j]] = ctext[j*m+i];
		for( int i = 0; i < m; i++ ) for( int j = 0; j < n; j++ ) cout << grid[i][j];
		cout << endl;
	}
	return 0;
}
