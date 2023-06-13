#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
  #include<bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m, 0));
    for(int i=0;i<m;i++){
        dp[0][i] = matrix[0][i];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up = matrix[i][j]+dp[i-1][j];
            int upLeft = INT_MIN, upRight = INT_MIN;
            if(j>0)
                upLeft = matrix[i][j] + dp[i-1][j-1];
            if(j<m-1)
                upRight = matrix[i][j]+ dp[i-1][j+1];
            
            dp[i][j] = max(up, max(upRight, upLeft));
        }
    }
    int maxi = INT_MIN;
    for(int i=0;i<m;i++){
        if(maxi < dp[n-1][i])
            maxi = dp[n-1][i];
    }
    return maxi;
}
    
   
};
