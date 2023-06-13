//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int i,int w,int price[],vector<vector<int>>& dp){
        if(i==0){
            return price[0]*w;
        }
        if(dp[i][w]!=-1){
            return dp[i][w];
        }
        int not_take=solve(i-1,w,price,dp);
        int take=INT_MIN;
        if(w>=i+1){ //a i+1 denotes length of rod at index i
            take=price[i]+solve(i,w-(i+1),price,dp);
        }
        return dp[i][w]=max(take,not_take);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp (n,vector<int> (n+1,-1));
        return solve(n-1,n,price,dp);
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