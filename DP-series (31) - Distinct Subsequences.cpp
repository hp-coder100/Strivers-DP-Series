#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
//recursion
int mod = 1000000007;
int solve(string &t, string &s, int i, int j){
    if(j<0)return 1;
    if(i<0)return 0;

    if(t[i]==s[j])return  solve(t, s, i-1, j-1) % mod + solve(t, s, i-1, j)% mod;

    return solve(t, s, i-1, j) % mod;
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
    return solve(t, s, lt, ls);
}  

//memoizaton
int solve(string &t, string &s, int i, int j, vector<vector<int>> &dp){
    if(j<0)return 1;
    if(i<0)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    if(t[i]==s[j])return dp[i][j]= solve(t, s, i-1, j-1,dp) % mod + solve(t, s, i-1, j,dp)% mod;

    return dp[i][j]=solve(t, s, i-1, j,dp) % mod;
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
    vector<vector<int>> dp(lt+1, vector<int>(ls+1, -1));
    return solve(t, s, lt, ls, dp);
} 

//tabulation

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
    vector<vector<int>> dp(lt+1, vector<int>(ls+1, 0));
    for(int i=0;i<=lt;i++)dp[i][0] = 1;

    for(int i=1;i<=lt;i++)
    for(int j=1;j<=ls;j++){
        if(t[i-1]==s[j-1])
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%mod;
        else
            dp[i][j] = dp[i-1][j];
    }
    return dp[lt][ls];
} 
//space optimizaton

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
    vector<int> prev(ls+1, 0);
    prev[0] = 1;

    for(int i=1;i<=lt;i++)
    for(int j=ls;j>0;j--){
        if(t[i-1]==s[j-1])
            prev[j] = (prev[j-1]+prev[j])%mod;
    }
    return prev[ls];
} 

   
};
