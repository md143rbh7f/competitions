import java.math.*;
import java.util.*;

public class TheTournamentDivTwo
{
	public int find( int[] p )
	{
		int tot = 0;
		for( int s : p ) tot += s;
		if( tot%2==1 ) return -1;
		return tot/2;
	}
}
