#include <string>

using namespace std;

struct PikachuEasy
{
	string check( string word )
	{
		int i = 0;
		while( i < word.size() )
		{
			if( i + 2 > word.size() ) break;
			if( ( word[i] == 'p' && word[i+1] == 'i' ) || ( word[i] == 'k' && word[i+1] == 'a' ) )
			{
				i += 2;
				continue;
			}
			if( i + 3 > word.size() ) break;
			if( word[i] == 'c' && word[i+1] == 'h' && word[i+2] == 'u' )
			{
				i += 3;
				continue;
			}
			break;
		}
		return i == word.size() ? "YES" : "NO";
	}
};
