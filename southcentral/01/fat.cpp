#include <iostream>
#include <set>
#include <utility>

using namespace std;

#define mp(a,b) make_pair((a),(b))
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

string in;
set< pair<int,string> > w;
int a,b;

int main()
{
	while(1)
	{
		cin >> in;
		if(cin.fail()) break;
		if(!w.empty()) cout << endl, w.clear();
		while(1)
		{
			cin >> in;
			if(in=="END") break;
			cin >> a >> b;
			w.insert(mp(a-b,in));
		}
		foreach(i,w) cout << i->second << endl;
	}
	return 0;
}
