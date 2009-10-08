import java.math.BigInteger;

/*
 * INCORRECT
 */

public class DigitsSwap
{
  public String maximalProduct( String X, String Y, int s )
  {
    char[] x = X.toCharArray();
    char[] y = Y.toCharArray();

    int n = x.length;
    int f = n;
    boolean eq = false;
    for( int i = 0; i < n; i++ )
    {
      if( x[i] != y[i] )
      {
        f = i;
        if( y[i] > x[i] )
        {
          char[] temp = y;
          y = x;
          x = temp;
        }
        break;
      }
      eq = true;
    }

    for( int i = f + 1; i < n; i++ )
    {
      if( s == 0 ) break;
      if( y[i] < x[i] )
      {
        char temp = x[i];
        x[i] = y[i];
        y[i] = temp;
        s--;
      }
      if( x[i] == y[i] ) eq = true;
    }

    if( s % 2 != 0 && !eq && ( f == n || s % (n-f) != 0 ) )
    {
      char temp = x[n-1];
      x[n-1] = y[n-1];
      y[n-1] = temp;
    }

    return new BigInteger(new String(x)).multiply(new BigInteger(new String(y))).toString();
  }
}
