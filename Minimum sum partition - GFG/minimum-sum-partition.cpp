//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int total_sum=0;
	    for(int i=0;i<n;i++){
	        total_sum+=arr[i];
	    }
	    vector<vector<bool>> dp(n,vector<bool>(total_sum+1,false));
	    for(int i=0;i<n;i++){
	        dp[i][0]=true;
	    }
	    if(arr[0]<=total_sum){
	    dp[0][total_sum]=true;
	    }
	    for(int ind=1;ind<n;ind++){
	        for(int t=1;t<=total_sum;t++){
	            bool not_take=dp[ind-1][t];
	            bool take=false;
	            if(t>=arr[ind]){
	                take=dp[ind-1][t-arr[ind]];
	            }
	            dp[ind][t]=take || not_take;
	        }
	        
	    }
	    int mini=1e9;
	    for(int i=0;i<=total_sum;i++){
	        if(dp[n-1][i]==true){
	            mini=min(mini,abs((total_sum-i)-i));
	        }
	    }
	    return mini;
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends