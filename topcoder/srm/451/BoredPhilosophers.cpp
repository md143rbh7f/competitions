#include <vector>
#include <set>
#include <string>
#include <sstream>

using namespace std;

string s, tmp;
vector<int> ans;
vector<string> strs;
set< vector<string> > strset;

struct BoredPhilosophers
{
	vector<int> simulate( vector<string> text, int N )
	{
		for( int i = 0; i < text.size(); i++ ) s += text[i];
		istringstream count(s);
		while( count>>tmp ) strs.push_back(tmp);
		int num = strs.size();
		for( int p = 0; p < N; p++ )
		{
			strset.clear();
			for( int i = 0; i+p < num; i++ )
			{
				vector<string> v;
				for( int j = 0; j <= p; j++ ) v.push_back(strs[i+j]);
				strset.insert(v);
			}
			ans.push_back(strset.size());
		}
		return ans;
	}
};
