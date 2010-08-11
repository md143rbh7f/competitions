#include <algorithm>
#include <iostream>
#include <string>

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

int o[] = { 0, 1, 2 }, best = 1<<20, c = 29;
string s[3];

string join( string a, string b )
{
	int n = a.size(), m = b.size(), k = min(n,m), l = 0;
	unsigned long long hash = 0, hbsh = 0, x = 1;
	rep(i,k)
	{
		hash = c*hash+(a[n-1-i]-'a'+1), hbsh = hbsh+x*(b[i]-'a'+1), x *= c;
		if(hash==hbsh) l = i+1;
	}
	return a+b.substr(l);
}

bool contains( string a, string b )
{
	int n = a.size(), m = b.size();
	if( n==0 || m==0 || n<m ) return false;
	unsigned long long hash = 0, hbsh = 0, x = 1;
	rep(i,m) hbsh = hbsh+x*(b[i]-'a'+1), x *= c;
	for( int i=n-1; i>=0; i-- )
	{
		hash = c*hash+(a[i]-'a'+1);
		if( i+m<n ) hash -= x*(a[i+m]-'a'+1);
		if( i+m<=n && hash==hbsh ) return true;
	}
	return false;
}

int main()
{
	rep(i,3) cin >> s[i];
	rep(i,3) rep(j,3) if( i!=j && contains(s[i],s[j]) ) s[j]="";
	do best = min( best, (int)join(join(s[o[0]],s[o[1]]),s[o[2]]).size() );
	while( next_permutation(o,o+3) );
	cout << best;
	return 0;
}
