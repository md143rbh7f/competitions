/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Humidex
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Humidex().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		String s1 = in.next(); if( s1.equals("E") ) return false;
		double d1 = in.nextDouble();
		String s2 = in.next();
		double d2 = in.nextDouble();
		HashMap<String,Double> vals = new HashMap<String,Double>();
		vals.put(s1,d1);
		vals.put(s2,d2);
		if( !vals.containsKey("T") ) vals.put( "T", T(vals.get("D"),vals.get("H")) );
		if( !vals.containsKey("D") ) vals.put( "D", D(vals.get("T"),vals.get("H")) );
		if( !vals.containsKey("H") ) vals.put( "H", H(vals.get("T"),vals.get("D")) );
		System.out.printf( "T %.1f D %.1f H %.1f\n", vals.get("T"), vals.get("D"), vals.get("H") );
		return true;
	}

	double T( double d, double h )
	{
		return h-(0.5555)*(6.11*Math.exp(5417.7530*((1/273.16)-(1/(d+273.16))))-10.0);
	}

	double D( double t, double h )
	{
		double hh = h-t;
		double e = hh/0.5555+10.0;
		return 1/((1/273.16)-Math.log(e/6.11)/5417.7530)-273.16;
	}

	double H( double t, double d )
	{
		return t+(0.5555)*(6.11*Math.exp(5417.7530*((1/273.16)-(1/(d+273.16))))-10.0);
	}
}
