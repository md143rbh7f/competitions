struct DigitHoles
{
	int numHoles( int a )
	{
		int ans = 0;
		while(a)
		{
			switch(a%10)
			{
				case 0: ans++; break;
				case 4: ans++; break;
				case 6: ans++; break;
				case 9: ans++; break;
				case 8: ans += 2; break;
			}
			a /= 10;
		}
		return ans;
	}
};
