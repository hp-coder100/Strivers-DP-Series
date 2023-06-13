#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
  //tabulation
    int maxProfit(vector<int>& prices) {
    int n= prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int ind= n-1; ind>=0; ind--){
            dp[ind][1] =  max(dp[ind+1][1], prices[ind] + dp[ind+2][0]);
            dp[ind][0] =  max(dp[ind+1][0], -prices[ind] + dp[ind+1][1]);
            
       }
        return dp[0][0];
    }
    //space optimization

   int stockProfit(vector<int> &Arr){
    // Write your code here.
    int n = Arr.size();
    vector<int> cur(2,0);
    vector<int> front1(2,0);
    vector<int> front2(2,0);
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            int profit;
            
            if(buy==0){// We can buy the stock
                profit = max(0+front1[0], -Arr[ind] + front1[1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+front1[1], Arr[ind] + front2[0]);
            }
            
            cur[buy] = profit;
        }
        
        front2 = front1;
        front1 = cur;
        
    }
    
    return cur[0];
}
};
