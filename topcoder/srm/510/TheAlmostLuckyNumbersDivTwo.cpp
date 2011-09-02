struct TheAlmostLuckyNumbersDivTwo
{
	int find( int a, int b )
	{
		int ans = 0;
		for( int i = a; i <= b; i++ )
		{
			int cnt = 0;
			for( int j = i; j; j /= 10 ) if( ( j % 10 ) != 4 && ( j % 10 ) != 7 ) cnt++;
			if( cnt <= 1 ) ans++;
		}
		return ans;
	}
};
