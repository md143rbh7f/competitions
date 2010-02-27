/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Archery
{
	public double expectedPoints( int n, int[] pts )
	{
		double s = 0;
		for( int i = 0; i <= n; i++ ) s += pts[i]*(2*i+1);
		return s/(n*n);
	}
}
