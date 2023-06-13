#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    
   //memoization
     bool solve(string &s, string &p, int i, int j,vector<vector<int>> &dp){
        if(i<0 && j<0) return 1;

        if(j<0)return 0;
        
        if(i<0){
           for (int k = 0; k <= j; k++) {
                if (p[k] != '*')
                return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j] || p[j]=='?')
            return dp[i][j] = solve(s, p, i-1, j-1,dp);
        
        if(p[j]=='*')
            return dp[i][j] = solve(s, p, i-1, j, dp) || solve(s, p, i, j-1, dp);

        return 0;
    }
    bool isMatch(string s, string p) {
        int n= s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s, p, n-1, m-1, dp);
    }


    //tabulation
   bool isMatch(string s, string p) {
        int n= s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = 1;
        for(int j=1;j<=m;j++){
            bool flag = true;
            for(int k=0;k<j;k++){
                if(p[k]!= '*')
                    flag = false;
            }
            dp[0][j] = flag;
        }

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){
            
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];

                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }

        }


        return dp[n][m];
    }


    //space optimization
    bool isMatch(string S2, string S1) {
        int n = S1.size();
  int m = S2.size();

  vector < bool > prev(m + 1, false);
  vector < bool > cur(m + 1, false);

  prev[0] = true;

  for (int i = 1; i <= n; i++) {
      bool flag = true;
      for(int k=0;k<i;k++){
          if(S1[k]!='*') flag=false;
      }
    
    cur[0] = flag;
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        cur[j] = prev[j - 1];

      else {
        if (S1[i - 1] == '*')
          cur[j] = prev[j] || cur[j - 1];

        else cur[j] = false;
      }
    }
    prev = cur;
  }

  return prev[m];
    }    
};
