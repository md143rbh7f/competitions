/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class TrappingRabbit
{
	public int findMinimumTime( int[] tx, int[] ty )
	{
		int min = 12345;
		for( int i = 0; i < tx.length; i++ ) if( tx[i]+ty[i] < min ) min = tx[i]+ty[i];
		return min-2;
	}
}
