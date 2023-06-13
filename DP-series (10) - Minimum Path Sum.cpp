#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
 //Recursion
 int solve(vector<vector<int>> &grid, int i, int j){
    if(i==0 && j==0)
        return grid[i][j];
    int left = INT_MAX;
    if(j>0)
        left = grid[i][j] + solve(grid, i,j-1);
    int up = INT_MAX;
    if(i>0)
        up = grid[i][j] + solve(grid, i-1, j);
    return min(left, up);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int ans = solve(grid, grid.size()-1, grid[0].size()-1);
    return ans;
}
   


   //dp

   #include<bits/stdc++.h>
int solve(vector<vector<int>> &grid, int i, int j){
    if(i==0 && j==0)
        return grid[i][j];
    int left = INT_MAX;
    if(j>0)
        left = grid[i][j] + solve(grid, i,j-1);
    int up = INT_MAX;
    if(i>0)
        up = grid[i][j] + solve(grid, i-1, j);
    return min(left, up);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n= grid.size(), m= grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j] = grid[i][j];
                continue;
            }
            int right = INT_MAX, bottom = INT_MAX;
            if(i>0)
                bottom = grid[i][j] + dp[i-1][j];
            if(j>0)
                right = grid[i][j] + dp[i][j-1];
            
            dp[i][j] = min(bottom, right);
        }
        
    }
    return dp[n-1][m-1];
}

};
