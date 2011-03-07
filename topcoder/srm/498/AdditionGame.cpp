struct AdditionGame
{
	int getMaximumPoints( int a, int b, int c, int n )
	{
		int ans = 0;
		while( n-- )
		{
			int *max = &a;
			if( *max < b ) max = &b;
			if( *max < c ) max = &c;
			if( *max > 0 ) ans += *max;
			(*max)--;
		}
		return ans;
	}
};
