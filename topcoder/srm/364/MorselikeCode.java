/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class MorselikeCode
{
	public String decrypt( String[] library, String message )
	{
		HashMap<String,String> dict = new HashMap<String,String>();
		for( String s : library )
		{
			String[] sp = s.split(" ");
			dict.put(sp[1],sp[0]);
		}
		String[] split = message.split(" ");
		StringBuilder res = new StringBuilder();
		for( String s : split )
			if( dict.containsKey(s) ) res.append( dict.get(s) );
			else res.append( "?" );
		return res.toString();
	}
}
