#include <string>

using namespace std;

struct SentenceCapitalizerInator
{
	string fixCaps( string in )
	{
		string out = "";
		bool cap = true;
		for( int i = 0; i < in.size(); i++ )
		{
			if( cap && in[i] >= 'a' && in[i] <= 'z' )
			{
				out += in[i] + 'A' - 'a';
				cap = false;
			}
			else
			{
				if( in[i] == '.' ) cap = true;
				out += in[i];
			}
		}
		return out;
	}
};
