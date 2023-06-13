#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:

  //Recursion
    int solve(vector<vector<int>> & triangle, int n , int i, int j){
    if(i==n-1)
        return triangle[i][j];
    
    int down = triangle[i][j] + solve(triangle, n, i+1, j);
    int downRight = triangle[i][j] + solve(triangle, n, i+1, j+1);
    return min(down, downRight);
            
    }

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    return solve(triangle, n, 0, 0);
}
   


  //dp
  int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<vector<int> > dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }
    
    return dp[0][0];
    
}



};
