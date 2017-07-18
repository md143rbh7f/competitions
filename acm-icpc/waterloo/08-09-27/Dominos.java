/*
 * Siyang Chen
 * CS 149s
 * 1 October 2008
 */

import java.util.HashSet;
import java.util.Scanner;

public class Dominos
{
  static Scanner in = new Scanner( System.in );
  
  public static void main( String[] args )
  {
    //first line - # of programs
    int cases = in.nextInt();
    //solve each program
    for( int i = 0; i < cases; i++ ) new Dominos();
  }
  
  private Dominos()
  {
    //# of tiles, # of commands
    int tiles = in.nextInt();
    int commands = in.nextInt();
    
    //initialize the graph - you are storing basically a list of parents that you have
    //(this is quite possibly the most disgusting thing ever)
    HashSet<Integer>[] nodesToParents = (HashSet<Integer>[])( new HashSet[tiles] );
    for( int i = 0; i < nodesToParents.length; i++ ) nodesToParents[i] = new HashSet<Integer>();
    
    //parse each of the node relationships
    for( int i = 0; i < commands; i++ )
    {
      int source = in.nextInt() - 1;
      int target = in.nextInt() - 1;
      nodesToParents[target].add( source );
    }
    
    boolean finished = false;
    while( !finished )
    {
      finished = true;
      //repeatedly compress your graph using the 'generation gap' method
      for( int i = 0; i < nodesToParents.length; i++ )
      {
        HashSet<Integer> parents = nodesToParents[i];
        //first check if you have any parents
        if( parents.size() == 0 ) continue;
        HashSet<Integer> generationGap = new HashSet<Integer>();
        for( int parent : parents )
        {
          //if you have grandparents, remove your link to your parent and add your grandparent(s) instead
          if( nodesToParents[parent].size() == 0 ) generationGap.add( parent );
          else
          {
            for( int grandParent : nodesToParents[parent] ) if( grandParent != i ) generationGap.add( grandParent );
            finished = false;
          }
        }
        nodesToParents[i] = generationGap;
      }
    }
    
    //check the number of nodes in the array that do not have parents
    int result = 0;
    for( HashSet<Integer> parents : nodesToParents ) if( parents.size() == 0 ) result++;
    System.out.println( result );
  }
  
}