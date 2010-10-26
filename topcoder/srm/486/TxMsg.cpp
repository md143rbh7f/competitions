#include <string>
#include <sstream>

using namespace std;

string ans,w;

bool vowel(char c)
{
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

struct TxMsg
{
	string getMessage( string o )
	{
		istringstream s(o);
		while(s>>w)
		{
			bool v=true;
			for(int i=0;i<w.size();i++) if(!vowel(w[i])) v=false;
			if(ans.size()) ans+=" ";
			if(v) ans+=w;
			else
			{
				bool u=true;
				for(int i=0;i<w.size();i++)
				{
					if(!vowel(w[i]))
					{
						if(u) ans+=w[i];
						u=false;
					}
					else u=true;
				}
			}
		}
		return ans;
	}
};
