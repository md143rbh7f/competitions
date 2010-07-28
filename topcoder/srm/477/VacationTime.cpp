#include <vector>

using namespace std;

bool bad[1000];

struct VacationTime
{
	int bestSchedule( int N, int K, vector<int> workingDays )
	{
		int ans = N;
		for( int i = 0; i < workingDays.size(); i++ ) bad[workingDays[i]-1] = true;
		for( int i = 0; i+K <= N; i++ )
		{
			int cnt = 0;
			for( int j = 0; j < K; j++ ) if( bad[i+j] ) cnt++;
			if( cnt<ans ) ans = cnt;
		}
		return ans;
	}
};
