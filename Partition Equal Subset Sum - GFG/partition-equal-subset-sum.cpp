//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   bool subsetSumToK(int n, int k, int arr[]) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    if(arr[0]<=k)
    dp[0][arr[0]]=true;
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
           bool not_take=dp[i-1][j];
           bool take=false;
           if (j >= arr[i]) {
             take = dp[i - 1][j - arr[i]];
           }
         dp[i][j]=not_take||take;
    
        }
    }

   
    
    return dp[n-1][k];
}
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        //check for subset having half sum then automatically another will be there
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        else{
            sum=sum/2;
            subsetSumToK(N,sum , arr);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends