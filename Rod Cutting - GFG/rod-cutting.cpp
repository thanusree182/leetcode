//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int price[],int i,int len,vector<vector<int>>& dp){
        if(i==0){
            return price[0]*len;
        }
        if(dp[i][len]!=-1)
        return dp[i][len];
        int take=-1e8;
        if(len>=(i+1)){
            take=price[i]+solve(price,i,len-(i+1),dp);
        }
        int not_take=solve(price,i-1,len,dp);
        return dp[i][len]=max(take,not_take);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(price,n-1,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends