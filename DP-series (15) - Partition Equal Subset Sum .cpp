#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
     bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
   vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
   for(int i=0;i<n;i++){
       dp[i][0] = true;
   }
   if(arr[0] <= k)dp[0][arr[0]] = true;
   for(int i=1;i<n;i++){
       for(int j = 1;j<=k;j++){
           bool notTaken = dp[i-1][j];
           bool taken = false;
           if(arr[i] <= j)
               taken = dp[i-1][j-arr[i]];
           dp[i][j] = taken | notTaken;
        }
   }
    return dp[n-1][k];
}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int totalSum = 0;
    for(int a:arr)
        totalSum += a;
    if(totalSum & 1) return false;
    totalSum /= 2;
    return subsetSumToK(n, totalSum, arr);
}

   
};
