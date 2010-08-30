#include <vector>
#include <string>

using namespace std;

vector<string> ans;

struct Xosceles
{
	vector<string> draw( int num )
	{
		int n = 0, start = 0;
		for( int i = 1; i <= 50; i++ )
		{
			if(i*i==num) n = i, start = 1;
			if(i*(i+1)==num) n = i;
		}
		if(n)
		{
			int m = 2*n-start;
			for( int i = 1; i <= n; i++ )
			{
				string tmp(m,'X');
				for( int j = 0; j < n-i; j++ ) tmp[j] = tmp[m-j-1] = '.';
				ans.push_back(tmp);
			}
		}
		return ans;
	}
};
