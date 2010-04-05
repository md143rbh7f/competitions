/*
	AxiomOfChoice
 */

import java.math.*;
import java.util.*;

public class LotteryPyaterochka
{
	public double chanceToWin( int in )
	{
		double n = in, N = 5*n;
		return (10*(N-5)*(N-6)/2+5*(N-5)+1)*n*120/N/(N-1)/(N-2)/(N-3)/(N-4);
	}
}
