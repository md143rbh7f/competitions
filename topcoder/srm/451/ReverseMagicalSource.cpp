struct ReverseMagicalSource
{
	int find( int source, int A )
	{
		int sum = 0;
		while( sum<=A ) sum += source, source *= 10;
		return sum;
	}
};
