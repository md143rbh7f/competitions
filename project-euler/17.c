#include <stdio.h>

int ans, i, j,
ones[] =
{
	0,
	3,	// one
	3,	// two
	5,	// three
	4,	// four
	4,	// five
	3,	// six
	5,	// seven
	5,	// eight
	4,	// nine
	3,	// ten
	6,	// eleven
	6,	// twelve
	8,	// thirteen
	8,	// fourteen
	7,	// fifteen
	7,	// sixteen
	9,	// seventeen
	8,	// eighteen
	8	// nineteen
},
tens[] =
{
	0,
	0,
	6,	// twenty
	6,	// thirty
	5,	// forty
	5,	// fifty
	5,	// sixty
	7,	// seventy
	6,	// eighty
	6	// ninety
};

int main()
{
	for( i = 1; i < 1000; i++ )
	{
		if( i >= 100 )
		{
			ans += ones[i/100] + 7;
			if( i%100 ) ans += 3;
		}
		j = i%100;
		if( j >= 20 ) ans += ones[j%10] + tens[j/10];
		else ans += ones[j];
	}
	ans += 11; // one thousand
	printf( "%d\n", ans );
	return 0;
}
