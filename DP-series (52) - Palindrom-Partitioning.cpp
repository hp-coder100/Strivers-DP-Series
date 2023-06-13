#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int f(int i, int n, string &str) {
    //Base case:
    if (i == n) return 0;

    int minCost = INT_MAX;
    //string[i...j]
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            int cost = 1 + f(j + 1, n, str);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}
int minCut(string str) {
    // Write your code here
    int n = str.size();
    return f(0, n, str) - 1;
}

    


//tabulation
int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        //string[i...j]
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, str)) {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;
}
};