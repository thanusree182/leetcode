//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long maxi=0;
    long long solve(int arr[],int s,int e, int n,vector<vector<int>>& dp){
        if(s>e || s>=n || e<0){
            return 0;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        long long a=arr[s]+min(solve(arr,s+2,e,n,dp),solve(arr,s+1,e-1,n,dp));
        long long b=arr[e]+min(solve(arr,s,e-2,n,dp),solve(arr,s+1,e-1,n,dp));
        return dp[s][e]=max(a,b);
        
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(arr,0,n-1,n,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends