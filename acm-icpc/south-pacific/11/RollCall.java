import java.util.*;

public class RollCall
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		int K = in.nextInt();
		for( int k = 1; k <= K; k++ )
		{
			int N = in.nextInt();
			in.nextLine();
			int present = 0, study = 0, remedial = 0, absent = 0;
			for( int i = 0; i < N; i++ )
			{
				String s[] = in.nextLine().split( "\\s+" );
				if( s.length == 1 ) absent++;
				else if( s.length == 2 ) present++;
				else if( s.length < 6 || s[5].charAt(0) == 'y' ) study++;
				else remedial++;
			}
			System.out.printf( "Roll-call: %d\n", k );
			System.out.printf( "Present: %d out of %d\n", present, N );
			System.out.printf( "Needs to study at home: %d out of %d\n", study, N );
			System.out.printf( "Needs remedial work after school: %d out of %d\n", remedial, N );
			System.out.printf( "Absent: %d out of %d\n", absent, N );
		}
	}
}
