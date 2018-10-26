// Gets the index of the minimum rotation of string s.
int min_rot( string & s )
{
	int n = s.size(), ans = 0, cur = 1, len = 0;
	while( cur < n && ans + len + 1 < n )
	{
		if( s[ans+len] < s[(cur+len)%n] )
		{
			cur = cur + len + 1;
			len = 0;
		}
		else if( s[ans+len] > s[(cur+len)%n] )
		{
			ans = max( ans + len + 1, cur );
			cur = ans + 1;
			len = 0;
		}
		else len++;
	}
	return ans;
}
