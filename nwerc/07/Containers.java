import java.util.Scanner;

public class Containers
{
  static Scanner in = new Scanner( System.in );
  
  public static void main( String[] args )
  {
    int testCases = in.nextInt();
    //create a new instance of Containers and solve it
    for( int i = 0; i < testCases; i++ ) new Containers().solve();
  }
  
  //function to solve based on input
  private void solve()
  {
    //input variable
    double stacks = Math.floor( in.nextDouble() + 4 / 5 );
    
    //make guesses for height and width
    int w_low = (int) Math.floor( Math.sqrt( 22 * stacks / 5 ) );
    int h_low = (int) Math.floor( Math.sqrt( 5 * stacks / 22 ) );
    int w_high = (int) Math.ceil( Math.sqrt( 22 * stacks / 5 ) );
    int h_high = (int) Math.ceil( Math.sqrt( 5 * stacks / 22 ) );
    
    //find product that satisfies the condition
    int w = w_low;
    int h = w_high;
    
    w = w * 44 + 4;
    h = h * 10 + 2;
    
    //output
    System.out.println( w + " X " + h + " = " + (long) w * h );
    
  }
  
}