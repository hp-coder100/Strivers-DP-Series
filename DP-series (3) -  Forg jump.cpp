#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
   
    for(int i=1;i<n;i++){
        int twoStep = INT_MAX;
        int oneStep = dp[i-1] + abs(heights[i-1] - heights[i]);
        if(i>1)
         twoStep = dp[i-2] + abs(heights[i-2] - heights[i]);
        dp[i] = min(oneStep, twoStep);
    }
    return dp[n-1];
    
    
}
};
