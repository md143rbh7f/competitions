#include <string>

using namespace std;

struct ChickenOracle
{
	string theTruth( int n, int E, int lie, int liar )
	{
		int C = n-E;
		bool e = false, c = false;
		for( int ee = 0; ee <= E; ee++ )
		{
			int ce = E-ee;
			if(lie<ce||liar<ce) continue;
			if(lie-ce+liar-ce==C) e = true;
		}
		for( int cc = 0; cc <= C; cc++ )
		{
			int ec = C-cc;
			if(lie<ec||liar<ec) continue;
			if(lie-ec+liar-ec==E) c = true;
		}
		if(e&&c) return "Ambiguous";
		if(e) return "The egg";
		if(c) return "The chicken";
		return "The oracle is a lie";
	}
};
