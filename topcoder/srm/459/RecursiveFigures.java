/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class RecursiveFigures
{
	public double getArea( int len, int n )
	{
		double[] rad = new double[n], area = new double[n];
		rad[0] = 0.5*len;
		for( int i = 1; i < n; i++ ) rad[i] = rad[i-1]*Math.sqrt(2)/2;
		for( int i = 0; i < n; i++ ) area[i] = rad[i]*rad[i]*Math.PI;
		double ans = area[0];
		for( int i = 1; i < n; i++ ) ans += area[i]-rad[i]*rad[i]*4;
		return ans;
	}
}
