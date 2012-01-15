import java.util.*;

public class KingSort
{
	static HashMap<String,Integer> romanToInt;
	static String[][] digits = { { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }, { "", "X", "XX", "XXX", "XL", "L" } };
	static int[][] values = { { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 0, 10, 20, 30, 40, 50 } };
	static
	{
		romanToInt = new HashMap<String,Integer>();
		int[] index = new int[digits.length];
		while( true )
		{
			String roman = "";
			int value = 0;
			for( int i = index.length-1; i >= 0; i-- )
			{
				roman += digits[i][index[i]];
				value += values[i][index[i]];
			}
			romanToInt.put( roman, value );
			int inc = 0;
			while( inc < index.length && index[inc] == digits[inc].length-1 ) index[inc++] = 0;
			if( inc == index.length ) break;
			index[inc]++;
		}
	}

	public String[] getSortedList( String[] _names )
	{
		int n = _names.length;
		String[][] names = new String[n][];
		for( int i = 0; i < n; i++ ) names[i] = _names[i].split(" ");
		Arrays.sort( names, new Comp() );
		String[] ans = new String[n];
		for( int i = 0; i < n; i++ ) ans[i] = names[i][0] + " " + names[i][1];
		return ans;
	}
	
	class Comp implements Comparator<String[]>
	{
		public int compare( String[] a, String[] b )
		{
			if( a[0].compareTo(b[0]) != 0 ) return a[0].compareTo(b[0]);
			int na = romanToInt.get( a[1] ), nb = romanToInt.get( b[1] );
			if( na < nb ) return -1;
			if( na > nb ) return 1;
			return 0;
		}
	}
}
