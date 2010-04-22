import java.math.*;
import java.util.*;

public class T9
{
	public String message( String[] part, String[] dict, String[] input )
	{
		TreeMap<String,ArrayList<String>> lookup = new TreeMap<String,ArrayList<String>>();
		for( String s : dict )
		{
			String key = "";
			for( int i = 0; i < s.length(); i++ )
			for( int p = 0; p < part.length; p++ )
			if( part[p].contains(""+s.charAt(i)) )
			{
				key += p+1;
				break;
			}
			if( !lookup.containsKey(key) ) lookup.put( key, new ArrayList<String>() );
			lookup.get(key).add(s);
		}
		for( String key : lookup.keySet() ) Collections.sort( lookup.get(key) );

		String in = "";
		for( String i : input ) in += i;
		in = in.replace( '0', ' ' );
		String ans = "";
		for( int i = 0; i < in.length(); i++ )
		{
			if( in.charAt(i)==' ' )
			{
				ans += " ";
				continue;
			}
			int j = i;
			while( j<in.length() && in.charAt(j)>='1' && in.charAt(j)<='9' ) j++;
			String nums = in.substring(i,j);
			i = j;
			while( j<in.length() && ( in.charAt(j)=='*' || in.charAt(j)=='#' ) ) j++;
			String index = in.substring(i,j);
			i = j-1;
			int intIndex = 0;
			for( int k = 0; k < index.length(); k++ ) intIndex += index.charAt(k)=='#' ? 1 : 5;
			ans += lookup.get(nums).get(intIndex);
		}
		return ans;
	}
}
