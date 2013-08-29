#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define iter(i,a,b,c) for(auto i=(a);i c(b);i++)
#define range(i,a,b) iter(i,a,b,<)
#define rep(i,n) range(i,0,n)
#define APP(f,...) f(__VA_ARGS__)
#define foreach(i,c) APP(iter,i,all(c),!=)
#define all(c) begin(c),end(c)
#define mp(a,b) make_pair((a),(b))
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)
#define M(x) ((x)%MOD)
#define acc(f,x,y) x=f(x,y)

## if c
int cases;

## endif
## if t
struct $NAME
{
	@
};
## endif
## if t!
int main()
{
##  if Q
	ios_base::sync_with_stdio(0);
##  endif
##  if c
	scanf( "%d", &cases );
	for (int case_num = 1; i <= cases; case_num++)
	{
		
	}
##  endif
##  if b
	while(1)
	{
	}
##  endif
	return 0;
}
## endif
