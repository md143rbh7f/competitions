struct MicrowaveSelling
{
	int mostAttractivePrice( int a, int b )
	{
		int B=a, BL=0;
		for(int i=a;i<=b;i++)
		{
			int j=i, c=0;
			while(j%10==9) c++, j/=10;
			if(c>=BL) B=i, BL=c;
		}
		return B;
	}
};
