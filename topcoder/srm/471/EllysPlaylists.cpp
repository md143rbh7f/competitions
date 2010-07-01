#include <string>
#include <vector>

using namespace std;

bool okay[50][50];
int ways[1000][50], mod = 1000000007;

class EllysPlaylists
{
	public:
	int countPlaylists( vector<string> songs, int K )
	{
		int n = songs.size(), ans = 0;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ )
		{
			okay[i][j] = true;
			for( int k = 0; k < 3; k++ ) if( songs[i][songs[i].length()-3+k]!=songs[j][k] ) okay[i][j] = false;
		}
		for( int i = 0; i < n; i++ ) ways[0][i] = 1;
		for( int t = 0; t < K-1; t++ )
			for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ )
				if( okay[i][j] )
					ways[t+1][j] = (ways[t+1][j]+ways[t][i])%mod;
		for( int i = 0; i < n; i++ ) ans = (ans+ways[K-1][i])%mod;
		return ans;
	}
};
