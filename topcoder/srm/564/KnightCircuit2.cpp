struct KnightCircuit2
{
	int maxSize( int w, int h )
	{
		if( w > h ) h ^= w, w ^= h, h ^= w;
		if( w < 2 || h < 3 ) return 1;
		if( w == 2 ) return ( h + 1 ) / 2;
		if( h == 3 ) return 8;
		return w * h;
	}
};
