#include <string>

using namespace std;

#define a 'a'
#define z 'z'

int cnt[z+1], tmp[z+1];

struct FoxAndHandle
{
	string lexSmallestName( string s )
	{
		int n = s.size();
		for( int i = 0; i < n; i++ ) cnt[s[i]]++;
		for( char c = a; c <= z; c++ ) cnt[c] /= 2;

		string ans;
		int last = 0;
		for( int i = 0; i < n / 2; i++ )
		for( char c = a; c <= z; c++ )
		if( cnt[c] )
		{
			int pos = last;
			while( pos < n && s[pos] != c ) pos++;

			for( char d = a; d <= z; d++ ) tmp[d] = 0;
			for( int j = pos; j < n; j++ ) tmp[s[j]]++;

			bool bad = false;
			for( char d = a; d <= z; d++ ) if( tmp[d] < cnt[d] ) bad = true;
			if( !bad )
			{
				last = pos + 1;
				cnt[c]--;
				ans += c;
				break;
			}
		}
		return ans;
	}
};
