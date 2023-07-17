//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    int mod=1e9+7;
    long long int solve(string& str,int l,int h, vector<vector<long long int>> &dp){
        if(l==h){
            return 1;
        }
        if(l>h)
        return 0;
        if(dp[l][h]!=-1)
        return dp[l][h];
        if(str[l]==str[h]){
            dp[l][h]=(1+solve(str,l+1,h,dp)+solve(str,l,h-1,dp))%mod;
        }
        else{
            dp[l][h]=((solve(str,l+1,h,dp)+solve(str,l,h-1,dp)-solve(str,l+1,h-1,dp))%mod+mod)%mod;
        }
        return dp[l][h];
    }
    long long int  countPS(string str)
    {
       //Your code here
       int n=str.size();
       vector<vector<long long int>> dp(n,vector<long long int>(n,-1));
       return solve(str,0,n-1,dp);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends