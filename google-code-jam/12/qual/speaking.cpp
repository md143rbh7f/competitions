#include <iostream>

using namespace std;

#define N 105

char map[] = "yhesocvxduiglbkrztnwjpfmaq", line[N];

int main()
{
	int T;
	cin >> T;
	cin.getline( line, N );
	for( int t = 1; t <= T; t++ )
	{
		cin.getline( line, N );
		for( int i = 0; line[i]; i++ ) if( line[i] >= 'a' && line[i] <= 'z' ) line[i] = map[line[i]-'a'];
		cout << "Case #" << t << ": " << line << endl;
	}
	return 0;
}
