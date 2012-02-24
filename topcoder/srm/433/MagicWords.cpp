#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char tmp[200];
int p[8];

struct MagicWords
{
	int count( vector<string> s, int k )
	{
		for( int i = 0; i < s.size(); i++ ) p[i] = i;
		int ans = 0;
		do
		{
			int index = 0, i = 0, j = 0;
			for( i = 0; i < s.size(); i++ ) for( j = 0; j < s[p[i]].size(); j++ ) tmp[index++] = s[p[i]][j];
			for( i = 1; i <= index; i++ ) if( index % i == 0 )
			{
				for( j = 0; j < index && tmp[j] == tmp[(i+j)%index]; j++ );
				if( j == index ) break;
			}
			if( i * k == index ) ans++;
		}
		while(next_permutation(p,p+s.size()));
		return ans;
	}
};
