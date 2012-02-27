public class EllysDirectoryListing
{
	public boolean ok( String s )
	{
		return s.equals( "." ) || s.equals( ".." );
	}

	public String[] getFiles( String[] files )
	{
		int n = files.length;
		int i = 0;
		String[] ans = new String[n];
		for( i = 0; i < n; i++ ) ans[i] = files[i];
		if( ok( ans[n-1] ) && ok( ans[n-2] ) ) return ans;
		for( i = 0; i < n; i++ ) if( ok( ans[i] ) ) break;
		String tmp = ans[i];
		ans[i] = ans[n-1];
		ans[n-1] = tmp;
		if( ok( ans[n-1] ) && ok( ans[n-2] ) ) return ans;
		for( i = 0; i < n; i++ ) if( ok( ans[i] ) ) break;
		tmp = ans[i];
		ans[i] = ans[n-2];
		ans[n-2] = tmp;
		return ans;
	}
}
