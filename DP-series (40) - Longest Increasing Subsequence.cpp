#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    //recutstion and memoization

int solve(int arr[],int n, int i, int prev, vector<vector<int>> &dp){
    if(i==n)return 0;

    if( dp[i][prev+1] != -1 )return dp[i][prev+1];

    int maxi = INT_MIN;
    if(prev==-1 || arr[i] > arr[prev])
       maxi = 1+solve(arr, n, i+1, i, dp);

    return dp[i][prev+1]=max(maxi, solve(arr, n, i+1, prev, dp));
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1,-1));
    return solve(arr, n, 0, -1, dp);

}

//tabulation
  int lengthOfLIS(vector<int> &arr) 
    {
       

        int n= arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
             dp[i][j+1] = dp[i+1][j +1];
    
    
            if(j == -1 || arr[i] > arr[j]){
                
               dp[i][j+1] =  max(dp[i][j+1], 1 + dp[i+1][i+1]);
            }
            }
        }    
        return dp[0][0];
    

}

//
   
};
