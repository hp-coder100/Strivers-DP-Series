#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
     #include<bits/stdc++.h>

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int totalSum = 0;
    for(int a:arr)totalSum +=  a;
    vector<vector<bool>> dp(n, vector<bool>(totalSum+1, 0));
   for(int i=0;i<n;i++){
       dp[i][0] = true;
   }
   if(arr[0] <= totalSum)dp[0][arr[0]] = true;
   for(int i=1;i<n;i++){
       for(int j = 1;j<=totalSum;j++){
           bool notTaken = dp[i-1][j];
           bool taken = false;
           if(arr[i] <= j)
               taken = dp[i-1][j-arr[i]];
           dp[i][j] = taken | notTaken;
        }
   }
    int mini = INT_MAX;
    for(int i = 0; i <= totalSum/2; i++){
        if(dp[n-1][i])
            mini = min(mini, abs(totalSum-i-i));
    }
    return mini;
}

   
};
