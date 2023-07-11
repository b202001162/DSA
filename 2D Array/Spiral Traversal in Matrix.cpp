int findK(int a[MAX][MAX],int n,int m,int k)
{
  // indexes
  
  int startRow = 0, startCol = 0;
  int endRow = n-1, endCol = m-1;
  // total elements in matrix
  long total = n*m;
  long cnt = 0;
  
  vector <int> ans;
  
  while(cnt < total) {
      // print starting row
      for(int i = startCol; i<=endCol; i++) {
          cnt++;
       //   if(cnt == k) return a[startRow][i];
          cout << a[startRow][i] << " ";
      }
      
      // update starting row
      startRow++;
      
      // print ending column
      for(int i = startRow; i<=endRow; i++) {
          cnt++;
       //   if(cnt == k) return a[i][endCol];
          cout << a[i][endCol] <<  " "; 
      } 
      
      // update ending column
      endCol--;
      
      // print ending row
      for(int i = endCol; i>=startCol; i--) {
          cnt++;
       //if(cnt == k)   return a[endRow][i];
       cout <<  a[endRow][i] << " ";
       
          //  cnt++;
      }
      
      // update ending row
      endRow--;
      
      // print starting column
      
      for(int i = endRow; i>=startRow; i--) {
          cnt++;
       //   if(cnt == k) return   a[i][startCol];
          cout << a[i][startCol] << " "; 
       //   cnt++;
      }
      
      // update starting col
      startCol++;
  }
  
  return -1;
}
