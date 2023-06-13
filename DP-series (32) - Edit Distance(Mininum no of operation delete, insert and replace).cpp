#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
  //recursion
     int solve(string &word1, string &word2, int i,int j){
        if(j<0)return i+1;
        if(i<0)return j+1;

        if(word1[i]==word2[j])
            return min(solve(word1, word2, i-1, j-1), solve(word1, word2, i-1, j));

        return 1 + min(solve(word1, word2, i-1, j), min(solve(word1, word2, i-1, j-1), solve(word1, word2, i, j-1))); 

    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return solve(word1, word2, n-1, m-1);
    }

    //memoization
     int solve(string &word1, string &word2, int i,int j,vector<vector<int>> &dp){
        if(j<0)return i+1;
        if(i<0)return j+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j])
            return dp[i][j]=min(solve(word1, word2, i-1, j-1,dp), solve(word1, word2, i-1, j,dp));

        return dp[i][j]= 1 + min(solve(word1, word2, i-1, j,dp), min(solve(word1, word2, i-1, j-1,dp), solve(word1, word2, i, j-1,dp))); 

    }
    int minDistance(string word1, string word2) {


        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(word1, word2, n-1, m-1,dp);
    }

    //tabulation
    int minDistance(string word1, string word2) {


        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;

        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])); 
        }
        return dp[n][m];

       
    }


    //space optimization
int editDistance(string word1, string word2) {


        int n = word1.size();
        int m = word2.size();
        
        vector<int>prev(m+1, 0), curr(m+1, 0);

        for(int j=0;j<=m;j++) prev[j] = j;

        for(int i=1;i<=n;i++)
        {curr[0]=i;
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1])
                curr[j] = prev[j-1];
            else 
                curr[j] = 1 + min(prev[j], min(prev[j-1], curr[j-1])); 
        }
        prev = curr;
        }
        return prev[m];

       
    }

   
};
