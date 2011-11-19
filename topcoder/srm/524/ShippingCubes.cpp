struct ShippingCubes
{
	int minimalCost( int N )
	{
		int ans = 111111111;
		for( int i = 1; i <= N; i++ )
		for( int j = 1; j <= N; j++ )
		for( int k = 1; k <= N; k++ )
		if( i * j * k == N && i + j + k < ans )
			ans = i + j + k;
		return ans;
	}
};
