import java.util.*;

public class PalindromicPartitions
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );

		int N = 1001, palins[] = new int[N]; // Michael, Sarah, etc...
		palins[0] = palins[1] = 1;
		for( int i = 2; i < N; i++ ) palins[i] = palins[i-2] + palins[i/2];

		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) System.out.printf( "%d %d\n", i, palins[in.nextInt()] );
	}
}
