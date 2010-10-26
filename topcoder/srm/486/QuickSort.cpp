#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

map<vi,double> mem;

void rec(vi s)
{
	if(mem.count(s)) return;
	mem[s]=0;
	if(s.size()<=1) return;
	rep(p,s.size())
	{
		vi a,b;
		rep(i,s.size())
		{
			if(s[i]>s[p]) b.push_back(s[i]);
			if(s[i]<s[p]) a.push_back(s[i]);
			if(s[i]>s[p]&&i<p) mem[s]++;
			if(s[i]<s[p]&&i>p) mem[s]++;
		}
		rec(a), rec(b);
		mem[s]+=mem[a]+mem[b];
	}
	mem[s]/=s.size();
}

struct QuickSort
{
	double getEval(vi l)
	{
		rec(l);
		return mem[l];
	}
};
