#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
   int countDistinctWays(int nStairs) {
  int  prev2 = 1;
  int prev = 1;
  
  for(int i=2; i<=nStairs; i++){
      int cur_i = (prev2 % 1000000007 + prev  % 1000000007) % 1000000007;
      prev2 = prev;
      prev= cur_i;
  }
  return prev % 1000000007;
}
};