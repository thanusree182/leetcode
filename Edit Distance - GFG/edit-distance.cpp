//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int i,int j, string &s,string &t,vector<vector<int>>&dp){
        if(i<0){
            return j+1;  //if s is ended we need (j+1) character to be added to it to make equal to t
        }
        if(j<0){
            return i+1; //if t is exhausted we need to remove (i+1) length of s to make it equal to t
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=solve(i-1,j-1,s,t,dp);
        }
        else{
            int insert=1+solve(i,j-1,s,t,dp);
            int delet=1+solve(i-1,j,s,t,dp);
            int replace=1+solve(i-1,j-1,s,t,dp);
            
            return dp[i][j]=min(insert,min(delet,replace));
        }
        
    }
    int editDistance(string s, string t) {
        // Code here
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends