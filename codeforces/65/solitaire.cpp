#include <iostream>
#include <set>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

int n, m, u, v, x, y;
set<string> unused, aset, bset;
set<char> cur_rank, cur_suit;
string cards[17][17], rank[] = { "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" }, suit[] = { "C", "D", "H", "S" };
bool j1, j2, found;

bool okay( int a, int b, string j1str, string j2str )
{
	cur_rank.clear();
	cur_suit.clear();
	rep(p,3) rep(q,3)
	{
		string cur = cards[a+p][b+q];
		if(cur=="J1") cur = j1str;
		if(cur=="J2") cur = j2str;
		cur_rank.insert(cur[0]);
		cur_suit.insert(cur[1]);
	}
	return cur_rank.size()==9 || cur_suit.size()==1;
}

bool find( string j1str, string j2str )
{
	for( u = 0; u < n-2; u++ ) for( v = 0; v < m-2; v++ )
	if(okay(u,v,j1str,j2str))
	for( x = 0; x < n-2; x++ ) for( y = 0; y < m-2; y++ )
	if( ( x>=u+3 || x<=u-3 || y>=v+3 || y<=v-3 ) && okay(x,y,j1str,j2str) )
		return true;
	return false;
}

int main()
{
	rep(i,13) rep(j,4) unused.insert( rank[i] + suit[j] );
	aset.insert("a");
	bset.insert("b");
	cin >> n >> m;
	rep(i,n) rep(j,m)
	{
		cin >> cards[i][j];
		if( cards[i][j] == "J1" ) j1 = true;
		if( cards[i][j] == "J2" ) j2 = true;
		unused.erase( cards[i][j] );
	}
	if(j1) aset = unused;
	if(j2) bset = unused;
	foreach(a,aset) foreach(b,bset) if( *a!=*b && find(*a,*b) )
	{
		cout << "Solution exists." << endl;
		if(j1&&j2) cout << "Replace J1 with " << *a << " and J2 with " << *b << "." << endl;
		else if(j1) cout << "Replace J1 with " << *a << "." << endl;
		else if(j2) cout << "Replace J2 with " << *b << "." << endl;
		else cout << "There are no jokers." << endl;
		cout << "Put the first square to (" << u+1 << ", " << v+1 << ")." << endl;
		cout << "Put the second square to (" << x+1 << ", " << y+1 << ")." << endl;
		return 0;
	}
	cout << "No solution." << endl;
	return 0;
}
