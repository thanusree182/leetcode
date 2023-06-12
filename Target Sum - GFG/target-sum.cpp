//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int mod=1e9+7;
    int solve(vector<int>& arr,int target,int i,vector<vector<int>>& dp){
        if(i==0){
            if(arr[i]==0 && target==0){
                return 2;
            }
            if(target==0 || target==arr[0]){
                return 1;
            }
            return 0;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int not_take=solve(arr,target,i-1,dp);
        int take=0;
        if(target>=arr[i]){
            take=solve(arr,target-arr[i],i-1,dp);
        }
        return dp[i][target]=(take+not_take)%mod;
    }
    int findTargetSumWays(vector<int>&arr ,int d) {
        //Your code here
        //division of subsets
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        
         if((sum-d)%2==1 || (sum-d)<0){
             return 0;
         }
         int target=(sum-d)/2;
         vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(arr,target,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends