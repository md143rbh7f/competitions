public class BestView
{
  public int numberOfBuildings( int[] h )
  {
    int n = h.length;
    int max = 0;

    for( int i = 0; i < n; i++ )
    {
      int score = 0;
      double slope = Double.POSITIVE_INFINITY;
      for( int j = i-1; j > -1; j-- )
      {
        double temp = (double)( h[j] - h[i] ) / ( j - i );
        if( temp < slope )
        {
          slope = temp;
          score++;
        }
      }

      slope = Double.NEGATIVE_INFINITY;
      for( int j = i+1; j < n; j++ )
      {
        double temp = (double)( h[j] - h[i] ) / ( j - i );
        if( temp > slope )
        {
          slope = temp;
          score++;
        }
      }

      max = max > score ? max : score;
    }

    return max;
  }
}
