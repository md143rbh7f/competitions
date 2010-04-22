import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class AppleWord
{
	public int minRep( String word )
	{
		int n = word.length();
		if( n<5 ) return -1;
		word = word.toLowerCase();
		int ans = 0;
		if( word.charAt(0)!='a' ) ans++;
		for( int i = 1; i < n-2; i++ ) if( word.charAt(i)!='p' ) ans++;
		if( word.charAt(n-2)!='l' ) ans++;
		if( word.charAt(n-1)!='e' ) ans++;
		return ans;
	}
}
