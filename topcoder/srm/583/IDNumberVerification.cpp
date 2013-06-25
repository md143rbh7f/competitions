#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define all(i) (i).begin(),(i).end()

int parse( string s )
{
	int ans;
	stringstream(s) >> ans;
	return ans;
}

inline bool leap( int year )
{
	return ( year % 4 == 0 && year % 100 ) || year % 400 == 0;
}

int last_day( int year, int month )
{
	if( month == 4 || month == 6 || month == 9 || month == 11 ) return 30;
	if( month != 2 ) return 31;
	return 28 + leap( year );
}

bool check_birthday( string date )
{
	int year = parse( date.substr( 0, 4 ) );
	if( year < 1900 || year > 2011 ) return false;
	int month = parse( date.substr( 4, 2 ) );
	if( !month || month > 12 ) return false;
	int day = parse( date.substr( 6 ) );
	if( !day || day > last_day( year, month ) ) return false;
	return true;
}

bool checksum( string id )
{
	int code = 0;
	if( id[17] == 'X' ) id[17] = ':';
	rep(i,18) code = 2 * code + id[i] - '0';
	return code % 11 == 1;
}

struct IDNumberVerification
{
	string verify( string id, vs good )
	{
		if(
			find( all( good ), id.substr( 0, 6 ) ) == good.end()
			|| !check_birthday( id.substr( 6, 8 ) )
			|| id.substr( 14, 3 ) == "000"
			|| !checksum( id )
		)
			return "Invalid";
		return ( id[16] - '0' ) % 2 ? "Male" : "Female";
	}
};
