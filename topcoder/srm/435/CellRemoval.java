public class CellRemoval
{
  public int cellsLeft( int[] TREE, int d )
  {
    tree = TREE;
    boolean[] leaf = new boolean[tree.length];
    int tot = 0;
    for( int i = 0; i < tree.length; i++ ) leaf[i] = true;
    leaf[tree[d]] = false;
    tree[d] = -1;
    for( int i = 0; i < tree.length; i++ ) if( tree[i] != -1 ) leaf[tree[i]] = false;
    for( int i = 0; i < tree.length; i++ ) if( leaf[i] ) tot++;
    for( int i = 0; i < tree.length; i++ ) compress( i );
    int count = 0;
    for( int i = 0; i < tree.length; i++ ) if( leaf[i] && tree[i] == d ) count++;
    if( count == 0 ) count = 1;
    
    return tot-count;
  }

  int[] tree;
  
  void compress( int x )
  {
    int ptr = x;
    while( tree[ptr] != -1 ) ptr = tree[ptr];
    
    while( x != ptr )
    {
      int old = x;
      x = tree[x];
      tree[old] = ptr;
    }
  }
}
