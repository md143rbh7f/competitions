int mem[4][4] =
{
	{ 0, 0, 0, 0 },
	{ 0, 1, 2, 2 },
	{ 0, 2, 4, 4 },
	{ 0, 2, 4, 5 }
};

struct NotTwo
{
	int maxStones( int w, int h )
	{
		return (w/4)*(h/4)*8 + (w%4)*(h/4)*2 + (h%4)*(w/4)*2 + mem[w%4][h%4];
	}
};
