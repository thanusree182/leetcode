//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	int solve(int arr[],int i,int sum,vector<vector<int>>& dp){
	   // if(sum==0)
	   // return 1; 
	   //upper base case is eliminated as there can be 0 elemenets which add into sub array
	    if(i==0){
	        if(sum==0 && arr[0]==0){
	            return 2;
	        }
	   
	        if(arr[0]==sum || sum==0){
	                return 1;
	            }
	       else  return 0;
	    }
	    if(dp[i][sum]!=-1){
	        return dp[i][sum];
	    }
	    int not_take=solve(arr,i-1,sum,dp);
	    int take=0;
	    if(sum>=arr[i])
	    take=solve(arr,i-1,sum-arr[i],dp);
	    
	    return dp[i][sum]= (take%mod+not_take%mod)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
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