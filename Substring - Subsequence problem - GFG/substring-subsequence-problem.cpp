//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(string& A, string& B,int n,int m,vector<vector<int>>& dp){
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(A[n-1]==B[m-1]){
            return dp[n][m]=1+solve(A,B,n-1,m-1,dp);
        }
        else{
            return dp[n][m]=solve(A,B,n-1,m,dp);
        }
        
    }
    int getLongestSubsequence(string A, string B) {
        // code here
        int n=A.length(),m=B.length();
        int maxi=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=m;i++){
            int ans=solve(A,B,n,i,dp);
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string A,B;

        cin >>A>>B;

        Solution ob;
        cout << ob.getLongestSubsequence(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends