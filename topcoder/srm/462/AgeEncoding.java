/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class AgeEncoding
{
	public double getRadix( int a, String bitString )
	{
		int n = bitString.length();
		long bits = 0;
		for( int i = 0; i < n; i++ ) if( bitString.charAt(n-i-1) == '1' ) bits |= 1l<<i;
		if( (a==0&&bits==0) || (a==1&&bits==1) ) return -2;
		double d = 1<<7, base = 0;
		int cycles = 1<<11;
		while( cycles != 0 )
		{
			if( eval(bits,base+d) < a ) base += d;
			d /= 2;
			cycles--;
		}
		if( Math.round(eval(bits,base)) != a || base==0 ) return -1;
		return base;
	}

	static double eval( long bits, double base )
	{
		double ret = 0, d = 1;
		for( int i = 0; i < 64; i++ )
		{
			if( ((bits>>i)&1) == 1 ) ret += d;
			d *= base;
		}
		return ret;
	}
}
