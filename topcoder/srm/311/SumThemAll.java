public class SumThemAll
{
  // lookup[i][j] is sum of the digits of (j000... to j999...) with i total digits
  long[][] lookup = new long[11][10];

  public long getSum( int low, int high )
  {
    long z = 1;
    // lookup table
    for( int i = 1; i < 11; i++ )
    {
      // for each 'digit', sum all the entries that go from 0 to 999... (i digits)
      for( int j = 0; j < 10; j++ ) lookup[i][0] += lookup[i-1][j];
      // then add the next place of precision to the base value
      for( int j = 1; j < 10; j++ ) lookup[i][j] = lookup[i][0] + z * j;
      z *= 10;
    }

    return sum( high + 1 ) - sum( low );
  }

  long sum( int a )
  {
    String s = ((Integer)a).toString();
    long ans = 0;
    long remainder = 0;
    long z = 1;
    int len = s.length();
    for( int i = len-1; i >= 0; i-- )
    {
      int d = s.charAt(i)-'0';
      // for j from 0 to d-1, add range from j000... to j999...
      for( int j = 0; j < d; j++ ) ans += lookup[len-i][j];
      // now add the digit multiplied by the remainder, update remainder
      ans += d * remainder;
      remainder += d * z;
      z *= 10;
    }
    return ans;
  }
}
