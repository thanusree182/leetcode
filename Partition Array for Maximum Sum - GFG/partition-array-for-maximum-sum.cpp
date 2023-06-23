//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int help(int ind,int n,int k,vector<int>& arr,vector<int>& dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int maxi=INT_MIN;
        int len=0;
        int maxians=INT_MIN;
        for(int i=ind;i<min(n,ind+k);i++){
            len++;
            maxi=max(maxi,arr[i]);
            int sum=(maxi*len)+help(i+1,n,k,arr,dp);
            maxians=max(maxians,sum);
        }
        return dp[ind]=maxians;
    }
    int solve(int n, int k, vector<int>& arr){
        // Code here
        vector<int> dp(n,-1);
       return help(0,n,k,arr,dp);
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
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends