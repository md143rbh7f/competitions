#include <string>

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define MAX 111

using namespace std;

char buf[MAX], best[MAX];
int len = MAX;

class TwoRegisters
{
	public:
	string minProg( int r )
	{
		if( r==1 ) return "";
		REP(s,1,r)
		{
			int l = 0, a = r, b = s, i = 0;
			while(b)
			{
				l += a/b;
				int t = a%b; a = b; b = t;
				i++;
			}
			if( a!=1 || l>=MAX ) continue;
			char c = i%2 ? 'X' : 'Y';
			a = r, b = s;
			int m = l;
			while(b)
			{
				rep(x,a/b) buf[--m] = c;
				int t = a%b; a = b; b = t;
				c = c=='X' ? 'Y' : 'X';
			}
			bool works = l<len;
			if( l==len ) REP(i,1,l) if( buf[i]!=best[i] )
			{
				if( buf[i]<best[i] ) works = true;
				break;
			}
			if( works )
			{
				len = l;
				REP(i,1,l) best[i] = buf[i];
			}
		}
		return string(best+1,len-1);
	}
};
