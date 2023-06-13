#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
   
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    for(int i=1;i<nums.size();i++){
        int pick = nums[i];
        if(i>1)
            pick = nums[i] + dp[i-2];
        int notpick  =  dp[i-1];
        dp[i] = max(notpick, pick);
        
    } 
    return dp[nums.size()-1];
}
   
};

