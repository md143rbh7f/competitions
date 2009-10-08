/*
 * AxiomOfChoice
 */

public class DateFormat
{
  int[][] dates;
  public String fromEuropeanToUs( String[] dateList )
  {
    // process input
    StringBuilder buildInput = new StringBuilder();
    for( String date : dateList ) buildInput.append( date );
    String[] inputArray = buildInput.toString().split( " " );

    dates = new int[inputArray.length][2];
    String[] date;
    for( int i = 0; i < dates.length; i++ )
    {
      date = inputArray[i].split( "/" );
      dates[i][0] = Integer.parseInt( date[0] );
      dates[i][1] = Integer.parseInt( date[1] );
      
      if( dates[i][0] > 12 ||                                         // invalid month - forced switch
          ( i != 0 && val(i) <= val(i-1) ) ||                         // not strictly increasing - forced switch
          ( ( i == 0 || sVal(i) > val(i-1) ) && sVal(i) < val(i) ) )  // greedy solution, if possible - forced switch
        swap( i );

      // if it is still invalid, return
      if( dates[i][0] > 12 || ( i != 0 && val(i) <= val(i-1) ) )
        return "";
    }

    StringBuilder result = new StringBuilder();
    for( int i = 0; i < dates.length; i++ )
    {
      result.append(
        ( dates[i][0] < 10 ? "0" : "" ) + dates[i][0] + "/" +
        ( dates[i][1] < 10 ? "0" : "" ) + dates[i][1] +
        ( i != dates.length-1 ? " " : "" ) );
    }
    return result.toString();
  }

  int val( int i )
  { return ( dates[i][0] << 5 ) + dates[i][1]; }

  int sVal( int i )
  { return ( dates[i][1] << 5 ) + dates[i][0]; }

  void swap( int i )
  {
    dates[i][0] ^= dates[i][1];
    dates[i][1] ^= dates[i][0];
    dates[i][0] ^= dates[i][1];
  }
}
