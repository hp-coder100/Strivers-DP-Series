#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
   
long countWaysToMakeChange(int *num, int n, int x)
{
     
    vector<vector<long>> dp(n, vector<long>(x+1, 0));
    for(int i=0;i<=x;i++){
        if(i%num[0]==0)
            dp[0][i] = 1;
     
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=x;j++){
            long notTake = dp[i-1][j];
            long take = 0;
            if(num[i]<=j)
                take = dp[i][j-num[i]];
            dp[i][j]= take+notTake;
        }
    }
    return dp[n-1][x];
}
   
};
