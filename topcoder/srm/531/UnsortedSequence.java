import java.util.*;

public class UnsortedSequence
{
	public int[] getUnsorted( int[] arr )
	{
		int n = arr.length;
		if( n < 2 ) return new int[0];
		Arrays.sort(arr);
		if( arr[0] == arr[n-1] ) return new int[0];
		int i = n-2;
		while( arr[i] == arr[i+1] ) i--;
		int tmp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = tmp;
		return arr;
	}
}
