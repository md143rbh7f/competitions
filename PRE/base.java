## if t!
import java.io.*;
## endif
import java.math.*;
import java.util.*;

public class $NAME
{
## if t!
##	if f
	static Scanner in;
##	else
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
##	endif
## endif
## if t!

##	if f!
	public static void main(String[] args)
##	else
	public static void main(String[] args) throws FileNotFoundException
##	endif
	{
##	if f
		in = new Scanner(new BufferedInputStream(new FileInputStream(new File("@.in")))); 
##	endif
##	if b
		int caseNum = 1;
		while(new $NAME().solve(caseNum++));
##	else if c
		int c = in.nextInt();
		for(int i = 1; i <= c; i++) new $NAME().solve(i);
##	endif
	}
## endif
## if t
	public @
	{
	}
## else if b

	boolean solve(int caseNum)
	{
		return true;
	}
## else if c

	void solve(int caseNum)
	{
	}
## endif
}
