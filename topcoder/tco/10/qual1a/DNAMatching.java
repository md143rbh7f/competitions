import java.util.HashSet;

public class DNAMatching
{
	public int getMaxSize( String[] dna )
	{
		HashSet<String> equiv = new HashSet<String>(), self = new HashSet<String>();
		for( String s : dna )
		{
			char[] rc = new char[s.length()];
			for( int i = 0; i < s.length(); i++ )
			{
				char base = 0;
				switch( s.charAt(i) )
				{
					case 'A': base = 'T'; break;
					case 'T': base = 'A'; break;
					case 'C': base = 'G'; break;
					case 'G': base = 'C'; break;
				}
				rc[s.length()-i-1] = base;
			}
			String z = new String(rc);
			if( z.equals(s) ) self.add(z);
			else
			{
				equiv.add(s);
				equiv.add(z);
			}
		}
		return equiv.size()/2+self.size();
	}
}
