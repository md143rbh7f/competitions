#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005

char buf[N];

struct Trie
{
	Trie * c[26] = {};
	bool win = false, lose = true;

	void add(char * s)
	{
		int x = *s;
		if(!x) return;
		lose = false, x -= 'a';
		if(!c[x]) c[x] = new Trie();
		c[x]->add(s + 1);
	}

	void rec()
	{
		if(lose) return;
		for(auto x : c) if(x)
		{
			x->rec();
			win |= !(x->win), lose |= !(x->lose);
		}
	}
} trie;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	rep(i, n)
	{
		scanf("%s", buf);
		trie.add(buf);
	}
	trie.rec();
	printf(trie.win && (trie.lose || k % 2) ? "First" : "Second");
	return 0;
}
