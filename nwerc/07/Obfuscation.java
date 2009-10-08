import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Obfuscation
{
  static Scanner in = new Scanner( System.in );
  
  public static void main( String[] args )
  {
    int testCases = in.nextInt();
    //create a new instance of Obfuscation and solve it
    for( int i = 0; i < testCases; i++ ) new Obfuscation().solve();
  }
  
  //dictionary
  private HashMap<CanonicalWord,AmbiguousString> dictionary;
  private int shortestWordLength = 1001;
  private int longestWordLength = 0;
  
  //function to solve based on input
  private void solve()
  {
    //input
    char[] sentence = in.next().toCharArray();
    int dictionarySize = in.nextInt();
    //build dictionary
    dictionary = new HashMap<CanonicalWord,AmbiguousString>( dictionarySize * 2 );
    for( int i = 0; i < dictionarySize; i++ )
    {
      String next = in.next();
      char[] chars = next.toCharArray();
      if( chars.length < shortestWordLength ) shortestWordLength = chars.length;
      if( chars.length > longestWordLength ) longestWordLength = chars.length;
      CanonicalWord word = new CanonicalWord( chars );
      if( !dictionary.containsKey( word ) ) dictionary.put( word, new AmbiguousString( next ) );
      else dictionary.get( word ).isAmbiguous = true;
    }
    //recursive search
    ArrayList<AmbiguousString> solutionSet = search( sentence, 0, new AmbiguousString( null, false ) );
    
    //print result(s)
    if( solutionSet.size() == 0 ) System.out.println( "impossible" ); //no results
    else if( solutionSet.size() == 1 )
    {
      AmbiguousString solution = solutionSet.get( 0 );
      if( !solution.isAmbiguous ) System.out.println( solutionSet.get( 0 ) ); //one unique result
      else System.out.println( "ambiguous" ); //one result, using ambiguous substrings
    }
    else System.out.println( "ambiguous" ); //more than one result - ambiguous
  }
  
  //recursively search for a solution, return in the form of a HashSet
  private ArrayList<AmbiguousString> search( char[] charArray, int startIndex, AmbiguousString startString )
  {
    //recursively match each of the possibilities to get a solution set
    ArrayList<AmbiguousString> solutionSet = new ArrayList<AmbiguousString>();
    for( int i = startIndex + shortestWordLength - 1; i < charArray.length && i - startIndex < longestWordLength; i++ )
    {
      CanonicalWord canonical = new CanonicalWord( charArray, startIndex, i );
      if( dictionary.containsKey( canonical ) ) solutionSet.add( dictionary.get( canonical ) );
    }
    //recurse for each of the solutions generated in this step - also check the end case
    ArrayList<AmbiguousString> completeSolutionSet = new ArrayList<AmbiguousString>();
    for( AmbiguousString match : solutionSet )
    {
      if( match.string.length() + startIndex + shortestWordLength <= charArray.length )
        completeSolutionSet.addAll( search( charArray, startIndex + match.string.length(), new AmbiguousString( ( startString.string == null ? "" : startString + " " ) + match.string , startString.isAmbiguous | match.isAmbiguous ) ) );
      else if( match.string.length() + startIndex == charArray.length )
        completeSolutionSet.add( new AmbiguousString( startString + " " + match.string, startString.isAmbiguous | match.isAmbiguous ) );
    }
    return completeSolutionSet;
  }
  
  //canonicalWord class to help match stuff
  private class CanonicalWord
  {
    int[] midFreqs;
    char first;
    char last;
    int hash;
    private CanonicalWord( char[] orig, int startIndex, int endIndex )
    {
      first = orig[ startIndex ];
      last = orig[ endIndex ];
      midFreqs = new int[26];
      for( int i = startIndex; i < endIndex; i++ ) midFreqs[ orig[i] - 97 ]++;
      //build hash code
      hash = first + 28 * last;
      for( int i = 0; i < midFreqs.length; i++ ) hash += midFreqs[i] * ( i + 1 );
    }
    private CanonicalWord( char[] orig )
    { this( orig, 0, orig.length - 1 ); }
    public int hashCode()
    { return hash; }
    //equals matches the canonical word
    public boolean equals( Object other )
    {
      CanonicalWord o = (CanonicalWord)other;
      if( o.first != first || last != last ) return false;
      for( int i = 0; i < midFreqs.length; i++ ) if( o.midFreqs[i] != midFreqs[i] ) return false;
      return true;
    }
  }
  
  //ambiguous string - only used as a wrapper to store the 'ambiguous' state
  private class AmbiguousString
  {
    String string;
    boolean isAmbiguous = false;
    private AmbiguousString( String _string )
    { string = _string; }
    private AmbiguousString( String _string, boolean _isAmbiguous )
    {
      string = _string;
      isAmbiguous = _isAmbiguous;
    }
    public String toString()
    { return string; }
  }
  
}