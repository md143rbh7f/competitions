public class UnsealTheSafe
{
  public long countPasswords( int N )
  {
    int[][] e =
    {
      { 7 },
      { 2, 4 },
      { 1, 3, 5 },
      { 2, 6 },
      { 1, 5, 7 },
      { 2, 4, 6, 8 },
      { 3, 5, 9 },
      { 4, 8, 0 },
      { 5, 7, 9 },
      { 6, 8 }
    };

    // dp solution
    long[][] fill = new long[N+1][10];
    for( int i = 0; i < 10; i++ ) fill[1][i] = 1;
    // fill step
    for( int i = 1; i < N; i++ )
    {
      // start pos
      for( int j = 0; j < 10; j++ )
        // fill neighbors
        for( int k = 0; k < e[j].length; k++ )
          fill[i+1][e[j][k]] += fill[i][j];
    }

    long res = 0;
    for( int i = 0; i < 10; i++ ) res += fill[N][i];
    return res;
  }
}
