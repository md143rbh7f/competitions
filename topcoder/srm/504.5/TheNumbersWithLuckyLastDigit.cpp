struct TheNumbersWithLuckyLastDigit
{
	int find( int n )
	{
		if( n<4 || ( n>4 && n<7 ) ) return -1;
		if( n%10 == 4 || n%10==7 ) return 1;
		int a = find(n-4), b = find(n-7);
		if( a != -1 && b != -1 ) return 1 + ( a<b ? a : b );
		else if( a != -1 ) return 1 + a;
		else if( b != -1 ) return 1 + b;
		else return -1;
	}
};
