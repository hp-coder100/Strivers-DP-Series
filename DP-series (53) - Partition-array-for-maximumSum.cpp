#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    
int f(int ind, vector<int> &num, int k) {
    int n = num.size();
    //base case:
    if (ind == n) return 0;

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    for (int j = ind; j < min(ind + k, n); j++) {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + f(j + 1, num, k);
        maxAns = max(maxAns, sum);
    }
    return maxAns;
}
int maxSumAfterPartitioning(vector<int>& num, int k) {

    return f(0, num, k);
}
   
};


int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();
    vector<int> dp(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--) {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for (int j = ind; j < min(ind + k, n); j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }
    return dp[0];
}
