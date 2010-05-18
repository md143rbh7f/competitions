import java.math.*;
import java.util.*;

public class ToolsBox
{
	public int countTools( String[] need )
	{
		HashSet<String> n = new HashSet<String>();
		for( String t : need )
		for( String tool : t.split(" ") )
			n.add(tool);
		return n.size();
	}
}
