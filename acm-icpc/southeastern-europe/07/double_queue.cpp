#include <cstdio>
#include <set>

using namespace std;

typedef pair<int,int> pii;
#define mp(a,b) make_pair((a),(b))

set<pii> q;
int cmd, a, b;

int main()
{
	while(1)
	{
		scanf("%d",&cmd);
		switch(cmd)
		{
			case 0:
				return 0;
			case 1:
				scanf("%d%d",&a,&b);
				q.insert(mp(b,a));
				break;
			case 2:
				if(q.empty()) printf("0\n");
				else
				{
					printf("%d\n",q.rbegin()->second);
					q.erase(q.find(*q.rbegin()));
				}
				break;
			case 3:
				if(q.empty()) printf("0\n");
				else
				{
					printf("%d\n",q.begin()->second);
					q.erase(q.begin());
				}
				break;
		}
	}
	return 0;
}
