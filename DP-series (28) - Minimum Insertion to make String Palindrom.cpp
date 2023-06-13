#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int mInsertion(string &s){
      int n  =s.size();
    
    string s2  = s;
    reverse(s2.begin(), s2.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=n;ind2++){
            if(s2[ind1-1]==s[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }

    return n-dp[n][n];
    }
   
};
