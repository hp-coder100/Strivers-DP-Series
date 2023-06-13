#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x+1, 0));
    for(int i=0;i<=x;i++){
        if(i%num[0]==0)
            dp[0][i] = i/num[0];
        else dp[0][i] = 1e9;
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=x;j++){
            int notTake = dp[i-1][j];
            int take = 1e9;
            if(num[i]<=j)
                take = 1+dp[i][j-num[i]];
            dp[i][j]= min(take, notTake);
        }
    }
    return dp[n-1][x] >= 1e9?-1:dp[n-1][x];
}
   
};
