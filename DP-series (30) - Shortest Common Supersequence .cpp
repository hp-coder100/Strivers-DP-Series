#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    //related to longest common subsequence
string shortestSupersequence(string a, string b)
{
	int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
    
    for(int ind1=1;ind1<=n;ind1++){
      for (int ind2 = 1; ind2 <= m; ind2++) {
        if (a[ind1 - 1] == b[ind2 - 1])
          dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
        else
          dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
      }
    }

    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0){
		if(a[i-1]==b[j-1]){
			ans = a[i-1] + ans;
			i--,j--;
		}	
		else if(dp[i-1][j] < dp[i][j-1]){
			ans = b[j-1] + ans;
			j--;
		}else{
			ans= a[i-1] + ans;
			i--;
		}
	}
	while(i>0){
		ans = a[i-1]+ans;
		i--;
	}

	while(j>0){
		ans = b[j-1]+ans;
		j--;
	}
	
	return ans;
}
   
};
