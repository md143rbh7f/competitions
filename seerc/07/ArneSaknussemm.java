import java.io.*;
import java.math.*;
import java.util.*;

public class ArneSaknussemm
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		while( in.hasNextInt() )
		{
			int n = in.nextInt();
			String s[] = new String[n];
			for( int i = 0; i < n; i++ ) s[i] = in.next();
			int m = s[0].length();
			char[] res = new char[n*m];
			for( int i = 0; i < m; i++ ) for( int j = 0; j < n; j++ ) res[i*n+j] = s[n-j-1].charAt(m-i-1);
			int end = n*m;
			while( res[end-1]=='_' ) end--;
			for( int i = 0; i < end; i++ ) switch( res[i] )
			{
				case '_': System.out.print(' '); break;
				case '\\': System.out.print('\n'); break;
				default: System.out.print(res[i]); break;
			}
			System.out.println();
			System.out.println();
		}
	}
}
