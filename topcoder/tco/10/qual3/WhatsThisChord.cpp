#include <string>
#include <vector>

using namespace std;

bool played[12];
int start[] = { 4, 9, 2, 7, 11, 4 }, MAJ[] = { 0, 4, 7 }, MIN[] = { 0, 3, 7 };
string notes[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };

class WhatsThisChord
{
	public:
	string classify( vector<int> chord )
	{
		for( int i = 0; i < 6; i++ ) if( chord[i]!=-1 ) played[(start[i]+chord[i])%12] = true;
		int cnt = 0;
		for( int i = 0; i < 12; i++ ) if( played[i] ) cnt++;
		if( cnt==3 )
		for( int i = 0; i < 12; i++ )
		{
			bool majWorks = true, minWorks = true;
			for( int j = 0; j < 3; j++ )
			{
				if( !played[(i+MAJ[j])%12] ) majWorks = false;
				if( !played[(i+MIN[j])%12] ) minWorks = false;
			}
			if( majWorks ) return notes[i]+" Major";
			if( minWorks ) return notes[i]+" Minor";
		}
		return "";
	}
};
