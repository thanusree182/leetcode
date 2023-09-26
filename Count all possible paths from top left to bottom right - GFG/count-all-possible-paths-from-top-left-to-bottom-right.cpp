//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// User function Template for C++
class Solution {
  public:
   long long int func(int i,int j,vector<vector<long long int>>& dp){
       int mod=1e9+7;
        if(i==0 && j==0){
            return 1;
        }
       
        if(i<0 || j<0)
        return 0;
         if(dp[i][j]!=-1){
            return (dp[i][j]%mod);
        }
        int top=func(i-1,j,dp);
        int left=func(i,j-1,dp);
        
        return dp[i][j]=(top+left)%mod;
    }
    long long int numberOfPaths(int a, int b){
        // code here
         vector<vector<long long int>> dp(a,vector<long long int>(b,-1));
        return func(a-1,b-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends