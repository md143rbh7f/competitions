import java.math.*;
import java.util.*;

public class EqualizeStrings
{
	public String getEq( String s, String t )
	{
		int n = s.length();
		char[] ans = new char[n];
		for( int i = 0; i < n; i++ )
		{
			char a = s.charAt(i), b = t.charAt(i);
			if( a>b )
			{
				char temp = b;
				b = a;
				a = temp;
			}
			int d1 = b-a, d2 = a+26-b;
			if( d1 < d2 ) ans[i] = a;
			else ans[i] = 'a';
		}
		return new String(ans);
	}
}
