//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(string& s1,string& s2,int i,int j, vector<vector<int>>& dp){
        if(i<0 || j<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+solve(s1,s2,i-1,j-1,dp);
        }
        else{
            return dp[i][j]=max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));
        }
    }
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n=S.length();
        string s1=S;
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp (n+1,vector<int>(n+1,-1));
        int len=solve(S,s1,n-1,n-1,dp);
        
        return n-len;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends