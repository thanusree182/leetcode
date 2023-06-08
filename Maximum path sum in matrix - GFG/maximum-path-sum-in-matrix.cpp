//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int>>& mat,int i,int j,int n,int m,vector<vector<int>>& dp){
        if(j<0 || j>=m){
            return -1e9;
        }
        if(i==0){
            return mat[0][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
           int  up1=mat[i][j]+solve(mat,i-1,j-1,n,m,dp);
        
        
          int   up2=mat[i][j]+solve(mat,i-1,j,n,m,dp);
        
        
           int up3=mat[i][j]+solve(mat,i-1,j+1,n,m,dp);
        
        return dp[i][j]=max(up1,max(up2,up3));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int ans=INT_MIN;
        int n=N;
        int m=Matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++){
            ans=max(ans,solve(Matrix,n-1,j,n,m,dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends