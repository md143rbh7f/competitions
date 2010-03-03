/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class ColoringRectangle
{
	public int chooseDisks( int X, int Y, int[] red, int[] blue )
	{
		int[][] diam = { red, blue };
		int[] dim = { red.length, blue.length };
		double[][] len = new double[2][];
		for( int z = 0; z < 2; z++ )
		{
			len[z] = new double[dim[z]];
			for( int i = 0; i < dim[z]; i++ )
				if( diam[z][i] >= Y )
					len[z][i] = Math.sqrt( diam[z][i]*diam[z][i] - Y*Y );
				else len[z][i] = -1;
			Arrays.sort( len[z] );
		}

		int min = 111;
		for( int z = 0; z < 2; z++ )
		{
			int pos[] = { dim[0]-1, dim[1]-1 }, colour = z, count = 0;
			double l = X;
			while( l > 0 && pos[colour] != -1 && len[colour][pos[colour]] >= 0 )
			{
				l -= len[colour][pos[colour]--];
				colour = 1-colour;
				count++;
			}
			if( l <= 0 && count < min ) min = count;
		}

		return min==111 ? -1 : min;
	}
}
