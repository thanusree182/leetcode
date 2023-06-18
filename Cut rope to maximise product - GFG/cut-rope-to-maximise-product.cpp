//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public: 
    long long solve(long long n,vector<long long>& dp){
        if(dp[n]!=-1){
            return dp[n];
        }
        long long maxi=0;
         for(long long i=1;i<n;i++)
      {
          maxi=max(maxi, max(1LL*i*(n-i), 1LL*i*solve(1LL*(n-i),dp)) );
      }
      return dp[n]=maxi;
    }
    long long maxProduct(int n) {
        // code here
        vector<long long> dp(n+1,-1);
        dp[0]=0;
        dp[1]=0;
        dp[2]=1;
        if(n<=2){
            return dp[n];
        }
        else{
          
                solve(1LL*n,dp);
            
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.maxProduct(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends