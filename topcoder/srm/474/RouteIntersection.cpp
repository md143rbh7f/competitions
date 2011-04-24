#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

map<int,int> dict;
set<vi> pts;

struct RouteIntersection
{
	string isValid( int N, vector<int> coords, string moves )
	{
		int n = coords.size(), m = 0;
		rep(i,n) if(!dict.count(coords[i])) dict[coords[i]] = m++;
		vi pt0(m);
		pts.insert(pt0);
		rep(i,n)
		{
			vi pt1(pt0);
			pt1[dict[coords[i]]] += moves[i] == '+' ? 1 : -1;
			if(pts.count(pt1)) return "NOT VALID";
			pts.insert(pt1);
			pt0 = pt1;
		}
		return "VALID";
	}
};
