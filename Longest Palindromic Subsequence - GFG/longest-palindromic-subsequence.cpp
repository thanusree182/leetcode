//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int solve(string& s1,string& s2,int i,int j,int n,vector<vector<int>>&dp){
        if(i<0 || j<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+solve(s1,s2,i-1,j-1,n,dp);
        }
        else{
            return dp[i][j]=max(solve(s1,s2,i-1,j,n,dp),solve(s1,s2,i,j-1,n,dp));
        }
    }
    int longestPalinSubseq(string A) {
        //code here
        int n=A.length();
        string s1=A;
        reverse(A.begin(),A.end());
        string s2=A;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s1,s2,n-1,n-1,n,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends