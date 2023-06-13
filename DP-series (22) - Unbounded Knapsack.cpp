#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
//recursion
int solve(int val[], int wt[], int W, int ind){
        if(ind == 0){
            return ((W/wt[0])*val[0]);
        }
        
        int notTake = solve(val, wt, W, ind-1);
        int take = INT_MIN;
        if(wt[ind]<=W)
        take = val[ind] + solve(val, wt, W-wt[ind], ind);
        return max(notTake, take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        if(N<=0  || W <=0)return 0;
      return solve(val, wt, W, N-1);
    }

//tabulation    
int unboundedKnapsack(int n, int maxWeight, vector<int> &value, vector<int> &weight)
{
  
    
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    for(int i=weight[0]; i<=maxWeight; i++){
        dp[0][i] = ((int) i/weight[0]) * value[0];
    }
    for(int i=1;i<n;i++)
        for(int w=0;w<=maxWeight;w++){
            int notTake = dp[i-1][w];
            int take = INT_MIN;
            if(weight[i] <= w)
                take = value[i] + dp[i][w-weight[i]];
            
            dp[i][w] = max(take, notTake);
        }
    return dp[n-1][maxWeight];
}

};
