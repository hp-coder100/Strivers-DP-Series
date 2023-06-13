#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
 
int lcs(string &text1, string &text2){
	//	Write your code here.
	  int n = text1.size();
       int m = text2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    int ans = 0;
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
          if (text1[ind1 - 1] == text2[ind2 - 1]) {
            dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
			ans = max(ans, dp[ind1][ind2]);
		  } else
            dp[ind1][ind2] = 0;
        }
    }
    
    return ans;
}
};
