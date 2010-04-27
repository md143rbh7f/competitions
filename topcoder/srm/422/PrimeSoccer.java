import java.math.*;
import java.util.*;

public class PrimeSoccer
{
	int max = 18, primes[] = { 2, 3, 5, 7, 11, 13, 17 };
	public double getProbability( int sa, int sb )
	{
		double[] prob = { 0.01*sa, 0.01*sb };
		double[][][] p = new double[2][max+1][max+1];
		double[] sum = new double[2];
		for( int z = 0; z < 2; z++ )
		{
			p[z][0][0] = 1;
			for( int t = 1; t <= max; t++ )
			{
				p[z][t][0] = p[z][t-1][0]*(1-prob[z]);
				for( int g = 1; g <= max; g++ )
					p[z][t][g] = p[z][t-1][g]*(1-prob[z])+p[z][t-1][g-1]*prob[z];
			}
			for( int prime : primes )
				sum[z] += p[z][max][prime];
		}
		return sum[0]+sum[1]-sum[0]*sum[1];
	}
}
