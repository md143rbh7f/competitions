public class RepaintTheChessboard
{
  public int minimumChanges( String[] board )
  {
    char[][] b = new char[board.length][board[0].length()];
    for( int i = 0; i < b.length; i++ ) b[i] = board[i].toCharArray();

    int start = 0;
    for( int i = 0; i < b.length; i++ )
    {
      for( int j = start; j < b[0].length; j+=2 )
      {
        if( b[i][j] == 'W' )
          b[i][j] = 'B';
        else b[i][j] = 'W';
      }
      if( start == 0 )
        start = 1;
      else start = 0;
    }

    int min = 10000;
    for( int i = 0; i < b.length-7; i++ )
    {
      for( int j = 0; j < b[0].length-7; j++ )
      {
        int curr = 0;
        for( int k = 0; k < 8; k++ )
        {
          for( int l = 0; l < 8; l++ )
          {
            if( b[i+k][j+l] == 'W' ) curr++;
          }
        }
        min = Math.min( min, Math.min( curr, 64-curr ) );
      }
    }

    return min;
  }
}
