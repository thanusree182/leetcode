//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int solve(string& s1,string& s2,int i,int j,int n,vector<vector<int>>& dp){
	        if(i>=n || j>=n)
	        return 0;
	        if(dp[i][j]!=-1)
	        return dp[i][j];
	        if(s1[i]==s2[j] && i!=j){
	            return dp[i][j]=1+solve(s1,s2,i+1,j+1,n,dp);
	        }
	        else{
	            return dp[i][j]=max(solve(s1,s2,i+1,j,n,dp),solve(s1,s2,i,j+1,n,dp));
	        }
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		     int n=str.length();
		     vector<vector<int>> dp(n,vector<int>(n,-1));
		     return solve(str,str,0,0,n,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends