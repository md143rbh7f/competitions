#include <algorithm>
#include <vector>

using namespace std;

struct SRMRoomAssignmentPhase
{
	int countCompetitors( vector<int> R, int K )
	{
		int me = R[0], i;
		sort(R.begin(),R.end());
		for( i = 0; R[R.size()-i-1] != me; i++ );
		return i / K;
	}
};
