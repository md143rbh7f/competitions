import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeSet;

public class Assembly
{
  static Scanner in = new Scanner( System.in );
  
  public static void main( String[] args )
  {
    int testCases = in.nextInt();
    for( int i = 0; i < testCases; i++ )
    {
      //create a new instance of Assembly and solve it
      Assembly a = new Assembly();
      a.solve();
    }
  }
  
  //store the map and budget (used in the test function later)
  Map<String,TreeSet<Component>> componentMap;
  int budget;
  
  //function to solve based on input
  private void solve()
  {
    int numComponents = in.nextInt();
    budget = in.nextInt();
    int result = 1000000000; //start the result at the maximum quality
    //iterate and store all the entries in a HashMap of lists, based on component type
    componentMap = new HashMap<String,TreeSet<Component>>( numComponents );
    for( int k = 0; k < numComponents; k++ )
    {
      //each line contains the type, name, price, and quality of the component - read and store these
      String type = in.next();
      in.next();
      int price = in.nextInt();
      int quality = in.nextInt();
      //dump the component info into the list
      if( !componentMap.containsKey( type ) ) componentMap.put( type, new TreeSet<Component>() );
      TreeSet<Component> componentSet = componentMap.get( type );
      componentSet.add( new Component( quality, price ) );
    }
    //binary search through all the entries based on entry quality
    int upper = result;
    int lower = 0;
    //search until you get to step size of two
    while( upper - lower > 1 )
    {
      //calculate result as the average of upper and lower
      result = ( upper + lower ) / 2;
      //if you stay within the budget, then increase the lower bound
      if( test( result ) ) lower = result;
      else upper = result;
    }
    //now that you have reduced the range down to two, test the next highest just to make sure
    if( upper == result ) result--;
    System.out.println( result );
  }
  
  //test to see if a certain quality works
  public boolean test( int testQuality )
  {
    Component floor = new Component( testQuality, 0 );
    int testBudget = budget;
    //iterate through, buy the component in the tail range that has the lowest cost
    for( TreeSet<Component> componentSet : componentMap.values() )
    {
      if( componentSet.tailSet( floor ).size() != 0 )
      {
        int minCost = 1000000000;
        for( Component component : componentSet.tailSet( floor ) ) if( component.price < minCost ) minCost = component.price;
        testBudget -= minCost;
        if( testBudget >= 0 ) continue;
      }
      //if you exceed the budget or don't find a solution, reduce the upper bound
      return false;
    }
    return true;
  }
  
  public class Component implements Comparable<Component>
  {
    int quality;
    int price;
    public Component( int _quality, int _price )
    {
      quality = _quality;
      price = _price;
    }
    public int compareTo( Component other )
    { return quality - other.quality; }public String toString(){return "quality: "+quality+", price: "+price;}
  }
  
}