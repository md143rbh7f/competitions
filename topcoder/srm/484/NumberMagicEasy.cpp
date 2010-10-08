#include <string>

using namespace std;

bool a[4][16]=
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }
};

struct NumberMagicEasy
{
	int theNumber( string answer )
	{
		for(int i=0;i<16;i++)
		{
			bool okay=true;
			for(int j=0;j<4;j++) if((answer[j]=='Y'&&!a[j][i])||(answer[j]=='N'&&a[j][i])) okay=false;
			if(okay) return i+1;
		}
		return -1;
	}
};
