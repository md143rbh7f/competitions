#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

#define START 0
#define END 1
#define SELF_CLOSE 2

string in;
int doc[2000005], stack[1000005], rule[205], match_index[205], n, m, nt = 1;
map<string,int> id;

int main()
{
	cin >> in;

	for( int i = 0; i < in.size(); )
	{
		i++;
		int type = START;
		if( in[i] == '/' ) type = END, i++;
		int j = i;
		while( in[j] != '>' ) j++;
		if( in[j-1] == '/' ) type = SELF_CLOSE, j--;
		string tag = in.substr( i, j - i );
		if( in[j] == '/' ) j++;
		if( !id.count(tag) ) id[tag] = nt++;
		int tag_id = id[tag];
		switch( type )
		{
			case START: doc[n++] = tag_id; break;
			case END: doc[n++] = -tag_id; break;
			case SELF_CLOSE: doc[n++] = tag_id, doc[n++] = -tag_id; break;
		}
		i = j+1;
	}

	cin >> m;
	getline( cin, in );
	while( m-- )
	{
		getline( cin, in );
		istringstream read_line( in );
		string tag;
		bool ok = true;
		int rule_len = 0;
		while( read_line >> tag )
		{
			if( !id.count(tag) )
			{
				ok = false;
				break;
			}
			rule[rule_len++] = id[tag];
		}
		if( !ok )
		{
			cout << 0 << endl;
			continue;
		}

		int num_matched = 0, sp = 0, cnt = 0;
		for( int i = 0; i < n; i++ )
		{
			int cur = doc[i];
			if( cur > 0 )
			{
				if( num_matched < rule_len && cur == rule[num_matched] ) match_index[num_matched++] = sp;
				if( num_matched == rule_len && cur == rule[rule_len-1] ) cnt++;
				stack[sp++] = cur;
			}
			else
			{
				sp--;
				if( num_matched > 0 && sp == match_index[num_matched-1] ) num_matched--;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
