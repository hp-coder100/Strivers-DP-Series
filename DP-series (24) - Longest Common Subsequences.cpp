#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
 //recursion
  int solve(string a, string b, int i, int j){
        if(i<0 || j<0)return 0;

        if(a[i]==b[j])return 1+solve(a,b, i-1, j-1);

        return max(solve(a, b, i-1, j), solve(a,b, i, j-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
       int n = text1.size();
       int m = text2.size();

       return solve(text1, text2, n-1,m-1);
    }


    //memoization
     int solve(string a, string b, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!= -1) return dp[i][j];

        if(a[i]==b[j])return dp[i][j]= 1 + solve(a,b, i-1, j-1, dp);

        return dp[i][j] = max(solve(a, b, i-1, j,dp), solve(a,b, i, j-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
       int n = text1.size();
       int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
       
       return solve(text1, text2, n-1, m-1, dp);
    }
    //tabulation
    int longestCommonSubsequence(string text1, string text2) {
      int n = text1.size();
       int m = text2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(text1[ind1-1]==text2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
    }
  int longestCommonSubsequence(string text1, string text2) {
      int n = text1.size();
       int m = text2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(text1[ind1-1]==text2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
    }


    //space optimization
     int longestCommonSubsequence(string text1, string text2) {
       int n = text1.size();
       int m = text2.size();
       vector<int> prev(m+1, 0), curr(m+1,0);
        
       for(int i=1;i<=n;i++)
     {  for(int j=1;j<=m;j++)
       {
           if(text1[i-1]==text2[j-1])
                curr[j] = 1 + prev[j-1];
            else{
                curr[j] = max(prev[j], curr[j-1]);
            }
       }
       prev= curr;
    }
       return prev[m];
    } 
};
