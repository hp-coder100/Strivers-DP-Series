#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    //recursion
    int solve(int i, int j,int m, int n, vector<vector<int>> &mat){
    if(i==m-1 && j==n-1)
        return 1;
    if(i>=m || j>=n || mat[i][j]== -1)
        return 0;
    int bottom = solve(i+1, j, m, n, mat);
    int right = solve(i, j+1, m, n, mat);
    
    return right+bottom;    
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    return solve(0,0, n, m, mat);
}


//tabulation
int mazeObstacles(int n, int m, vector< vector< int> > &maze) {
    vector<vector<int>> dp(n, vector<int> (m, -1)); 
    for(int i=0; i<n ;i++){
      for(int j=0; j<m; j++){
          
          //base condition
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          
          if(maze[i][j]==-1){
              dp[i][j] = 0;
              continue;
          }
          long up=0;
          long left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = (up % 1000000007 + left % 1000000007) % 1000000007;
      }
  }
  
  return dp[n-1][m-1] % 1000000007;
}



};
