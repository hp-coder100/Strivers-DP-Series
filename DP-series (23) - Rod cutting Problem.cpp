#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int cutRod(vector<int> &value, int n)
{
	vector<vector<int>> dp(n, vector<int>(n+1, 0));
    for(int i=0; i<=n; i++){
        dp[0][i] = i * value[0];
    }
      
    
    for(int i=1;i<n;i++)
        for(int w=0;w<=n;w++){
            int notTake = dp[i-1][w];
            int take = 0;
            if(i+1 <= w)
                take = value[i] + dp[i][w-i-1];
            
            dp[i][w] = max(take, notTake);
        }
    return dp[n-1][n];
}

   
};
