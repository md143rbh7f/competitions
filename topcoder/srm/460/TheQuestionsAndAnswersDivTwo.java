/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class TheQuestionsAndAnswersDivTwo
{
	public int find( String[] questions )
	{
		HashSet<String> q = new HashSet<String>();
		for( String s : questions ) q.add(s);
		return 1<<q.size();
	}
}
