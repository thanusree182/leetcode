//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int i,int target,int wt[],int val[],vector<vector<int>>& dp){
        if(i==0){
            if(target<wt[0]){
                return 0;
            }
            else{
               return val[0];
            }
        }
        
        if(target<0){
            return 0;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int take=0;
        if(target>=wt[i]){
            take=val[i]+solve(i-1,target-wt[i],wt,val,dp);
        }
        int not_take=solve(i-1,target,wt,val,dp);
        
        return dp[i][target]=max(take,not_take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
      return solve(n-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends