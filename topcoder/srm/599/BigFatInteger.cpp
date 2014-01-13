struct BigFatInteger
{
	int minOperations(int a, int b)
	{
		int cnt = 0, top = 0;
		for(int p = 2; p <= a; p++) if(!(a % p))
		{
			cnt++;
			int q = 0;
			do a /= p, q++;
			while(!(a % p));
			q *= b;
			int t = 0;
			for(int i = 1; i < q; i *= 2) t++;
			if(t > top) top = t;
		}
		return cnt + top;
	}
};
