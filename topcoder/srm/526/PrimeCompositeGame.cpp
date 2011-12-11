#include <list>

using namespace std;

#define L 1<<19

list<int> win[2], lose[2];
int best[2][L], p[L];

void update_max( list<int> & q, int id, int index )
{
	while( !q.empty() && best[id][q.back()] <= best[id][index] ) q.pop_back();
	q.push_back( index );
}

struct PrimeCompositeGame
{
	int theOutcome( int N, int K )
	{
		for( int i = 2; i < L; i++ ) p[i] = 1;
		for( int i = 2; i < L; i++ )
		{
			if( p[i] ) for( int j = 2 * i; j < L; j += i ) p[j] = 0;
			for( int j = 0; j < 2; j++ )
			{
				if( !lose[1-j].empty() ) best[j][i] = 1 - best[1-j][lose[1-j].front()];
				else if( !win[1-j].empty() ) best[j][i] = -1 - best[1-j][win[1-j].front()];
			}
			if( best[p[i]][i] > 0 ) update_max( win[p[i]], p[i], i );
			else update_max( lose[p[i]], p[i], i );
			if( i >= K ) for( int j = 0; j < 2; j++ )
			{
				if( !win[j].empty() && win[j].front() == i-K ) win[j].pop_front();
				else if( !lose[j].empty() && lose[j].front() == i-K ) lose[j].pop_front();
			}
		}
		return best[0][N];
	}
};
