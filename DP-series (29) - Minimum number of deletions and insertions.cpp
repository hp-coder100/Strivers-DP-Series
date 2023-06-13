#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:



  int minOperations(string s1, string s2) {
    
    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return  n+m-2*dp[n][m];
}
   //without longest common subsequence

  int minOperations(string text1, string text2) 
	{   
	    int n = text1.size(), m= text2.size();
	    
	    vector<vector<int>> dp(n+1, vector<int> (m+1,0));
	    
	    for(int i=1;i<=n;i++)dp[i][0] = i;
	    for(int j=1;j<=m;j++)dp[0][j] = j;
	    
	    for(int i=1;i<=n;i++)
	        for(int j=1;j<=m;j++){
	            if(text1[i-1]==text2[j-1]){
	                dp[i][j] = dp[i-1][j-1];
	            }
	            else{
	                dp[i][j] = 1+min(dp[i][j-1], dp[i-1][j]);
	            }
	        }
	    
	    
	    return dp[n][m];
	    
	} 
};
