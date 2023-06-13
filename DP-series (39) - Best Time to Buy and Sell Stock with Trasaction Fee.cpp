#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
  //tabulation
  
int maximumProfit(int n, int fee, vector<int> &prices) {
    
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int ind= n-1; ind>=0; ind--){
            dp[ind][1] =  max(dp[ind+1][1], prices[ind] + dp[ind+1][0]);
            dp[ind][0] =  max(dp[ind+1][0], -prices[ind]- fee + dp[ind+1][1]);
            
       }
        return dp[0][0];
    
}

   
};
