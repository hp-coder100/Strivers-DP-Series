#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
  
     //recursion
  int solve(vector<int> &prices, int n, int i,int j, int cap){
    if(i==n || cap==0)return 0;
   
    if (j == 1) {
        return max(-prices[i]+solve(prices, n, i+1, 0, cap), solve(prices, n, i+1, 1, cap));
    }
    return max(prices[i]+solve(prices, n, i+1, 1, cap-1), solve(prices, n, i+1, 0, cap));

}

int maxProfit(vector<int>& prices, int n, int cap)
{
    return solve(prices, n, 0, 1, cap);
   
}

//memoization
int solve(vector<int> &prices, int n, int i,int j, int cap,vector<vector<vector<int>>> &dp){
    if(i==n)return 0;
    if(cap==0)return 0;

    if(dp[i][j][cap]!=-1)return dp[i][j][cap];
    if (j == 1) {
        return dp[i][j][cap]=max(-prices[i]+solve(prices, n, i+1, 0, cap, dp), solve(prices, n, i+1, 1, cap, dp));
    }
    return dp[i][j][cap]=max(prices[i]+solve(prices, n, i+1, 1, cap-1, dp), solve(prices, n, i+1, 0, cap, dp));

}

int maxProfit(vector<int>& prices, int n, int cap)
{
    vector<vector<vector<int>>> dp(n, 
            vector<vector<int>>(2, 
                    vector<int>(cap, -1)));
    return solve(prices, n, 0, 1, 2, dp);
   
}
//tabullation
int maxProfit(vector<int>& prices, int n, int k)
{
    vector<vector<vector<int>>> dp(n+1, 
            vector<vector<int>>(2, 
                    vector<int>(k, 0)));

    for(int i=n-1; i>=0; i--){
       
            for(int cap=k;cap>=1; cap--){
            dp[i][0][cap] =  max(dp[i+1][0][cap], -prices[i] + dp[i+1][1][cap]);
            dp[i][1][cap] =  max(dp[i+1][1][cap], prices[i] + dp[i+1][0][cap-1]);
            }
    }
    return dp[0][0][k];
   
}
//space optimization

int maxProfit(vector<int>& Arr, int n, int k){
vector<vector<int>> ahead(2,vector<int> (k,0));
    
    vector<vector<int>> cur(2,vector<int> (k,0));
    
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=k; cap++){
                
                if(buy==0){// We can buy the stock
                    cur[buy][cap] = max(0+ahead[0][cap], 
                                -Arr[ind] + ahead[1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    cur[buy][cap] = max(0+ahead[1][cap],
                                Arr[ind] + ahead[0][cap-1]);
                }
            }
        }
        ahead = cur;
    }
    
    return ahead[0][k];
}
    
   
};
