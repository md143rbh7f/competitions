#include <string>

using namespace std;

struct StrangeComputer
{
	int setMemory( string mem )
	{
		int ans = 0, cur = 0;
		for( int i = 0; i < mem.length(); i++ ) if( mem[i]-'0'!=cur ) cur = 1-cur, ans++;
		return ans;
	}
};
