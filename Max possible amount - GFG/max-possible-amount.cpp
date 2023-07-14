//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int arr[],int l,int h,vector<vector<int>>& dp){
	    if(l>h)
	    return 0;
	    if(dp[l][h]!=-1)
	    return dp[l][h];
	    int a=arr[l]+min(solve(arr,l+2,h,dp),solve(arr,l+1,h-1,dp));
	    int b=arr[h]+min(solve(arr,l,h-2,dp),solve(arr,l+1,h-1,dp));
	    
	    return dp[l][h]=max(a,b);
	}
	int maxAmount(int arr[], int n)
	{
		
		// Your code goes here
		vector<vector<int>> dp(n,vector<int>(n,-1));
       int ans=solve(arr,0,n-1,dp);
       
       return ans;
	}
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

	   

	    Solution ob;
	    cout << ob.maxAmount(a, n) << "\n";

	     
    }
    return 0;
}

// } Driver Code Ends