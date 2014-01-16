#include <iostream>
#include <string>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 505

string maze[N];
bool seen[N][N];
int n, m, k, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool dfs(int i, int j)
{
	if(i < 0 || j < 0 || i >= n || j >= m || maze[i][j] != '.' || seen[i][j]) return true;
	seen[i][j] = true;
	bool can_remove = true;
	rep(d, 4) can_remove &= dfs(i + dx[d], j + dy[d]);
	if(can_remove && k)
	{
		k--;
		maze[i][j] = 'X';
		return true;
	}
	return false;
}

int main()
{
	cin >> n >> m >> k;
	rep(i,n) cin >> maze[i];
	rep(i,n) rep(j,m) if(maze[i][j] == '.')
	{
		dfs(i, j);
		break;
	}
	rep(i,n) cout << maze[i] << endl;
	return 0;
}
