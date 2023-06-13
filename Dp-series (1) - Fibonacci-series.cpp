#include <bits/stdc++.h>
using namespace std;

//Memoization
int  fibonacci(int n, vector<int> &arr){
  if(n <= 1)
    return n;
  if( arr[n] != -1)
    return arr[n];
  
  return arr[n] = arr[n-1]+arr[n-2];
}

//Tabulation
int fibonacci1(int n){
   vector<int> dp(n+1, -1);
   dp[0]= 0;
   dp[1] = 1;
   for(int i=2; i<=n;i++){
      dp[i] = dp[i-1]+dp[i-2];
   }
  return dp[n];
}
//Without Space
int fibonacci2(int n){
  int prev1 = 0;
  int prev2 = 1;
  for(int i=2;i<=n;i++){
    int curr = prev1 + prev2;
    prev1 = prev2;
    prev2 = curr;
  }
  return prev2;
}


//{ Driver Code Starts.
int main(){
  //number to step to fibonacci series
  
  int n=5;

  vector<int> arr(n+1, -1);

  fibonacci(n, arr);

  cout<<arr[n]<<endl;

  return 0;
}
