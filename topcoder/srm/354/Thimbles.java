/*
 * AxiomOfChoice
 */

public class Thimbles
{
  public int thimbleWithBall( String[] swaps )
  {
    // ball position mask
    int pos = 1;
    int a, b;
    for( String swap : swaps )
    {
      a = swap.charAt(0) - '0';
      b = swap.charAt(2) - '0';
      if( pos == a ) pos = b;
      else if( pos == b ) pos = a;
    }
    return pos;
  }
}
