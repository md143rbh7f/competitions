class ChildlessNumbers
{
	public:
	int howMany( int A, int B )
	{
		int ans = 0;
		for( long long i = A; i <= B; i++ )
		{
			int works = 1;
			for( int j = 1; j <= 100; j++ )
			{
				long long k = i*j;
				int l = 0;
				while( k )
				{
					l += k%10;
					k /= 10;
				}
				if( l==j ) works = 0;
			}
			ans += works;
		}
		return ans;
	}
};
