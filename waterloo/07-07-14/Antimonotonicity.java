/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Antimonotonicity
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Antimonotonicity().solve( i );
	}

	void solve( int caseNum )
	{
		int n = in.nextInt(), nums[] = new int[n];
		for( int i = 0; i < n; i++ ) nums[i] = in.nextInt();
		boolean asc = true;
		int count = 1;
		for( int i = 1; i < n; i++ )
		if( (asc&&nums[i]<nums[i-1]) || (!asc&&nums[i]>nums[i-1]) )
		{
			asc = !asc;
			count++;
		}
		System.out.println( count );
	}
}
