//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int i,int b_or_s,int transactions,int A[],int n,vector<vector<vector<int>>> &dp){
        if(i==n){
            return 0;
        }
        if(transactions==0){
            return 0;
        }
        if(dp[i][b_or_s][transactions]!=-1){
            return dp[i][b_or_s][transactions];
        }
        if(b_or_s==1){
            int buy=-A[i]+solve(i+1,0,transactions,A,n,dp);
            int not_buy=solve(i+1,1,transactions,A,n,dp);
            return dp[i][b_or_s][transactions]=max(buy,not_buy);
        }
        else{
            int sell=A[i]+solve(i+1,1,transactions-1,A,n,dp);
            int not_sell=solve(i+1,0,transactions,A,n,dp);
            return dp[i][b_or_s][transactions]=max(sell,not_sell);
        }
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return solve(0,1,K,A,N,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends