import java.math.*;
import java.util.*;

public class GirlsAndBoys
{
	public int sortThem( String row )
	{
		char[] r = row.toCharArray();
		int n = r.length, ans1 = 0, last1 = 0, ans2 = 0, last2 = 0;
		for( int i = 0; i < n; i++ )
			if( r[i]=='G' ) ans1 += i-(last1++);
			else ans2 += i-(last2++);
		return ans1<ans2?ans1:ans2;
	}
}
