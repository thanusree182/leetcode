//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
  int solve(int nums[],int i,int target,vector<vector<int>>& dp){
        if(target==0)
        return 1;
        if(i<0)
        return 0;
        if(dp[i][target]!=-1)
        return dp[i][target];
        int take=0;
if(target>=(nums[i])){
    take=solve(nums,i-1,target-nums[i],dp);
}
int not_take=solve(nums,i-1,target,dp);

return dp[i][target]=take||not_take;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totSum = 0;

  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }

  vector < vector < int >> dp(n, vector < int > (totSum + 1, -1));

  for (int i = 0; i <= totSum; i++) {
    bool dummy = solve(arr,n - 1, i, dp);
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (dp[n - 1][i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
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