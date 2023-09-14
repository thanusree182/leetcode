//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	int solve(int arr[],int i,int target,vector<vector<int>>& dp){
	     if(i==0){
	        if(target==0 && arr[0]==0){
	            return 2;
	        }
	   
	        if(arr[0]==target || target==0){
	                return 1;
	            }
	       else  return 0;
	    }
	    if(dp[i][target]!=-1)
	    return dp[i][target];
	    int take=0;
	    if(target>=arr[i]){
	        take=solve(arr,i-1,target-arr[i],dp);
	    }
	    int not_take=solve(arr,i-1,target,dp);
	    
	    return dp[i][target]=(take%mod+not_take%mod)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(arr,n-1,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends