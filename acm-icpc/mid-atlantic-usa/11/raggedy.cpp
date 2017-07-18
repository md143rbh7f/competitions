#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef pair<int,int> pii;
#define range(i,a,b) for(int i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)

#define INF 123456789
#define N 505

string line, word;
int w[N][N], score[N], pre[N];
bool newl[N];

bool run()
{
	int L;
	cin >> L;
	if(!L) return false;

	vs ws;
	getline(cin, line);
	while(1)
	{
		getline(cin, line);
		if(!line.size()) break;
		for(istringstream iss(line); iss >> word;) ws.push_back(word);
	}

	int n = ws.size();
	rep(i,n)
	{
		w[i][i+1] = ws[i].size();
		range(j,i+1,n) w[i][j+1] = w[i][j] + ws[j].size() + 1;
	}

	range(i,1,n+1)
	{
		score[i] = INF;
		for(int j = i - 1; j >= 0 && w[j][i] <= L; j--)
		{
			int s = score[j] + (i < n) * (L - w[j][i]) * (L - w[j][i]);
			if(s < score[i]) score[i] = s, pre[i] = j;
		}
	}

	clr(newl);
	for(int i = n; i; i = pre[i]) newl[i] = true;
	rep(i,n) cout << ws[i] << (newl[i+1] ? "\n" : " ");
	cout << "===" << endl;

	return true;
}

int main()
{
	while(run());
	return 0;
}
