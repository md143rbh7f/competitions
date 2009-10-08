import java.util.Scanner;

public class TowerParking
{
  static Scanner in = new Scanner( System.in );
  
  public static void main( String[] args )
  {
    int testCases = in.nextInt();
    //create a new instance of TowerParking and solve it
    for( int i = 0; i < testCases; i++ ) new TowerParking().solve();
  }
  
  //function to solve based on input
  private void solve()
  {
    //env variables
    int h = in.nextInt();
    int l = in.nextInt();
    int time = 0;
    
    //store current floor position and car locations
    int[] floorPositions = new int[h];
    int[][] carLocations = new int[h*l][2];
    
    //iterate and store all car locations
    for( int i = 0; i < h; i++ )
    {
      for( int j = 0; j < l; j++ )
      {
        int carNumber = in.nextInt();
        if( carNumber > 0 )
        {
          carLocations[carNumber][0] = i;
          carLocations[carNumber][1] = j;
        }
      }
    }
    
    //loop through array, calculate times
    for( int i = 1; i < carLocations.length; i++ )
    {
      int[] coords = carLocations[i];
      if( coords[0] + coords[1] == 0 ) break;
      time += 20 * coords[0];
      int horiz = coords[1] - floorPositions[coords[0]];
      horiz *= ( horiz < 0 ? -1 : 1 );
      if( horiz * 2 > l ) horiz = l - horiz;
      time += 5 * horiz;
      floorPositions[coords[0]] = coords[1];
    }
    
    System.out.println(time);
  }
  
}
