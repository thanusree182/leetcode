//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int solve(int l,int h,int arr[],vector<vector<int>>& dp){
        if(l>h)
        return 0;
        if(dp[l][h]!=-1)
        return dp[l][h];
        int a=arr[l]+min(solve(l+2,h,arr,dp),solve(l+1,h-1,arr,dp)); //as both players play optimally min value will be left among 2 possible values for 2nd player
        int b=arr[h]+min(solve(l,h-2,arr,dp),solve(l+1,h-1,arr,dp));
        return dp[l][h]=max(a,b);
    }
    bool is1winner(int N,int arr[]) {
        
        // code here
        int total=0;
        for(int i=0;i<N;i++){
            total+=arr[i];
        }
        vector<vector<int>> dp(N,vector<int>(N,-1));
        int sum=solve(0,N-1,arr,dp);
        
        return (sum>(total-sum));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends