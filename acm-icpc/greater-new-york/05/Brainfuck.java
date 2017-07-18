/*
 * Siyang Chen
 * CS 149s
 * 30 September 2008
 */

import java.util.Scanner;

public class Brainfuck
{
  static Scanner in = new Scanner( System.in );
  
  public static void main( String[] args )
  {
    //first line - # of programs
    int numPrograms = in.nextInt();
    //solve each program
    for( int i = 0; i < numPrograms; i++ ) new Brainfuck( i + 1 );
  }
  
  private Brainfuck( int n )
  {
    //output program number
    StringBuilder result = new StringBuilder( "PROGRAM #" + n + ":\n" );
    
    //parse commands
    StringBuilder commandsString = new StringBuilder();
    String lineString;
    //append all except for comments
    while( !( lineString = in.nextLine() ).equals( "end" ) )
    {
      int commentIndex = lineString.indexOf( "%" );
      if( commentIndex == -1 ) commandsString.append( lineString );
      else commandsString.append( lineString.substring( 0, commentIndex ) );
    }
    
    //commands
    char[] commands = commandsString.toString().toCharArray();
    //memory space
    byte[] memory = new byte[32768];
    short ptr = 0;
    //blocks
    int[] blockStart = new int[ commands.length / 2 ];
    int lastBlock = -1;
    int skipBlock = 0;
    //result
    StringBuilder execResult = new StringBuilder();
    boolean compileError = false;
    for( int i = 0; i < commands.length && !compileError; i++ )
    {
      if( skipBlock == 0 )
      {
        switch( commands[i] )
        {
          case '>':
            if( ptr == 32767 ) ptr = 0;
            else ptr++;
            break;
          case '<':
            if( ptr == 0 ) ptr = 32767;
            else ptr--;
            break;
          case '+':
            if( memory[ptr] == 127 ) memory[ptr] = -128;
            else memory[ptr]++;
            break;
          case '-':
            if( memory[ptr] == -128 ) memory[ptr] = 127;
            else memory[ptr]--;
            break;
          case '.':
            execResult.append( (char)( memory[ptr] < 0 ? memory[ptr] + 256 : memory[ptr] ) );
            break;
          case '[':
            if( memory[ptr] == 0 ) skipBlock = 1;
            else //else push this onto the stack
            {
              lastBlock++;
              blockStart[lastBlock] = i;
            }
            break;
          case ']':
            if( memory[ptr] == 0 ) //if 0, then skip
            {
              lastBlock--;
              if( lastBlock < -1 ) compileError = true;
            }
            else //else return to last block
            {
              if( lastBlock > -1 ) i = blockStart[lastBlock];
              else compileError = true;
            }
            break;
        }
      }
      else if( commands[i] == '[' ) skipBlock++;
      else if( commands[i] == ']' ) skipBlock--;
    }
    
    //catch compile errors
    if( compileError || skipBlock > 0 || lastBlock > -1 ) result.append( "COMPILE ERROR" );
    else result.append( execResult );
    
    //output
    System.out.println( result.toString() );
  }
}
