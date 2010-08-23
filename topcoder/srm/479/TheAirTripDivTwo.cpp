#include <vector>

using namespace std;

struct TheAirTripDivTwo
{
	int find( vector<int> flights, int fuel )
	{
		int i = 0;
		while( i<flights.size() )
		{
			fuel -= flights[i];
			if( fuel<0 ) break;
			i++;
		}
		return i;
	}
};
