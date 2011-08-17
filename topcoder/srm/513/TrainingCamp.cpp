#include <string>
#include <vector>

using namespace std;

struct TrainingCamp
{
	vector<string> determineSolvers( vector<string> students, vector<string> topics )
	{
		vector<string> ans( students.size() );
		for( int i = 0; i < students.size(); i++ ) for( int j = 0; j < topics.size(); j++ )
		{
			bool ok = true;
			for( int k = 0; k < students[i].size(); k++ ) if( topics[j][k]=='X' && students[i][k]!='X' ) ok = false;
			ans[i] += ok ? 'X' : '-';
		}
		return ans;
	}
};
