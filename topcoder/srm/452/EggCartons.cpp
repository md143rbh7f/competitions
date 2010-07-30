struct EggCartons
{	
	int minCartons( int n )
	{
		int x = n/8;
		while( x>=0 && (n-8*x)%6 ) x--;
		return x>=0 ? x+(n-8*x)/6 : -1;
	}
};
