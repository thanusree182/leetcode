//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int func(vector<int>&cost,vector<int>& dp,int n){
        if(n<0){
            return 0;
        }
        if(n==0 || n==1){
            return cost[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=cost[n]+min(func(cost,dp,n-1),func(cost,dp,n-2));
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //Write your code here
        vector<int> dp(N+1,-1);
        int ans=min(func(cost,dp,N-1),func(cost,dp,N-2));
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends