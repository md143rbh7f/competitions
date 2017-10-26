import java.util.*;

public class cd_pwd
{
	class Node
	{
		String name;
		Node parent;
		HashMap<String,Node> children = new HashMap<String,Node>();
	}

	static Scanner in = new Scanner(System.in);
	Node root, cur;

	void cd( String dir )
	{
		String[] path = dir.split( "/" );
		int i = 0;
		if( path.length == 0 || path[0].length() == 0 )
		{
			cur = root;
			i++;
		}
		for( ; i < path.length; i++ )
		{
			if( path[i].equals("..") ) cur = cur.parent;
			else
			{
				if( !cur.children.containsKey(path[i]) )
				{
					Node child = new Node();
					child.name = path[i];
					child.parent = cur;
					cur.children.put( path[i], child );
				}
				cur = cur.children.get(path[i]);
			}
		}
	}

	void pwd()
	{
		LinkedList<String> path = new LinkedList<String>();
		for( Node ptr = cur; ptr != root; ptr = ptr.parent ) path.addFirst( ptr.name );
		StringBuilder output = new StringBuilder();
		for( String name : path )
		{
			output.append("/");
			output.append(name);
		}
		output.append("/");
		System.out.println( output );
	}

	void solve()
	{
		root = new Node();
		cur = root;
		int n = in.nextInt();
		in.nextLine();
		for( int i = 0; i < n; i++ )
		{
			String[] cmd = in.nextLine().split(" ");
			if( cmd[0].equals("cd") ) cd(cmd[1]);
			else pwd();
		}
	}

	public static void main( String[] args )
	{
		new cd_pwd().solve();
	}
}
