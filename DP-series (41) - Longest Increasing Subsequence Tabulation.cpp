#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    
   //tabulation
  int lengthOfLIS(vector<int> &arr) 
    {
       

        int n= arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
             dp[i][j+1] = dp[i+1][j +1];
    
    
            if(j == -1 || arr[i] > arr[j]){
                
               dp[i][j+1] =  max(dp[i][j+1], 1 + dp[i+1][i+1]);
            }
            }
        }    
        return dp[0][0];
    

}

//
   
};
