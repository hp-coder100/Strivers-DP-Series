#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    //recursion

     int solve(vector<int> &prices,int n, int ind, bool buy){
        if(ind==n)return 0;

        if(buy){
            return max(solve(prices, n, ind+1, !buy)-prices[ind], solve(prices, n, ind+1, buy));    
        }
         return max(solve(prices, n, ind+1, !buy)+prices[ind], solve(prices, n, ind+1, buy));

    }

    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        return solve(prices, n, 0, true);
    }
    

    //memoization
      int solve(vector<int> &prices,int n, int ind, int j, vector<vector<int>> &dp){
        if(ind==n)return 0;

        if(dp[ind][j]!=-1)return dp[ind][j];
        if(j==1){
            return dp[ind][j] =max(solve(prices, n, ind+1, 0, dp)-prices[ind], solve(prices, n, ind+1, 1, dp));    
        }
         return dp[ind][j] =  max(solve(prices, n, ind+1, 1, dp)+prices[ind], solve(prices, n, ind+1, 0, dp));

    }

    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, n, 0, 1, dp);
    }


//tabulation
 int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int ind= n-1; ind>=0; ind--){
        
            dp[ind][0] =  max(dp[ind+1][0], -prices[ind] + dp[ind+1][1]);
            dp[ind][1] =  max(dp[ind+1][1], prices[ind] + dp[ind+1][0]);
       }
        return dp[0][0];
    }
//space optimize
 int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int>prev(2, 0), curr(2,0);
        for(int ind= n-1; ind>=0; ind--){
        
            curr[0] =  max(prev[0], -prices[ind] + prev[1]);
            curr[1] =  max(prev[1], prices[ind] + prev[0]);
            prev = curr;
       }
        return curr[0];
    }


    

long getMaximumProfit(long *prices, int n)
{
      
        long prev1=0, prev0=0;
        for (int ind = n - 1; ind >= 0; ind--) {

          long curr0 = max(prev0, -prices[ind] + prev1);
          long curr1 = max(prev1, prices[ind] + prev0);
          prev1 = curr1;
          prev0 = curr0;
        }
        return prev0;

}

   
};
