#include <vector>
#include <string>

#define foreach(i,c) for(typeof((c).end()) i=(c).begin(); i!=(c).end(); i++ )

using namespace std;

int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

class SequenceOfCommands
{
	public:
	string whatHappens( vector<string> cmd )
	{
		int x = 0, y = 0, d = 0;
		foreach(s,cmd)
		foreach(c,*s)
		switch(*c)
		{
			case 'R': d = (d+1)%4; break;
			case 'L': d = (d+3)%4; break;
			default: x += dx[d], y += dy[d]; break;
		}
		return (!x&&!y) || d ? "bounded" : "unbounded";
	}
};
