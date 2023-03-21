//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int> (W+1,-1));
       return  fun(n-1,W,wt,val,dp);
    }
    int fun(int index,int max_weight,int wt[],int val[], vector<vector<int>>& dp){
        if(index==0){
            if(wt[0]<=max_weight){
                return val[0];
            }
            else
            return 0;
        }
        if(dp[index][max_weight]!=-1)
        return dp[index][max_weight];
        int not_take=0+fun(index-1,max_weight,wt,val,  dp);
        int take=INT_MIN;
        if(wt[index]<=max_weight){
            take=val[index]+fun(index-1,max_weight-wt[index],wt,val,dp);
        }
        return dp[index][max_weight]=max(take,not_take);
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