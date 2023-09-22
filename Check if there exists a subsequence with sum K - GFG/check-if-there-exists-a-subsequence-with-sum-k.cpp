//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
   int solve(int i, int tar,  vector<int> &arr, vector<vector<int>> &dp){
        if(tar==0) return true;
        if(i==0) return arr[0]==tar;
        if(dp[i][tar]!=-1) return dp[i][tar];
        bool notpick=solve(i-1,tar,arr,dp);
        bool pick=0;
        if(tar>=arr[i]) pick=solve(i-1, tar-arr[i],arr,dp);
        return dp[i][tar]=pick || notpick;
    }
   
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (k+1,-1));
        return solve(n-1,k,arr,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends