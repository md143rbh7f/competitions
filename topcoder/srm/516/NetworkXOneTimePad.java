import java.util.*;

public class NetworkXOneTimePad
{
	public int crack( String[] in, String[] out )
	{
		HashSet<Long> ans = new HashSet<Long>();
		for( int j = 0; j < out.length; j++ )
		{
			HashSet<Long> tmp = new HashSet<Long>();
			for( int i = 0; i < in.length; i++ )
			{
				long l = Long.parseLong( in[i], 2 ) ^ Long.parseLong( out[j], 2 );
				if( j == 0 || ans.contains(l) ) tmp.add(l);
			}
			ans = tmp;
		}
		return ans.size();
	}
}
