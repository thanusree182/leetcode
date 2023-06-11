//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int solve(int i,vector<vector<int>> &colors,int prev,vector<vector<int>> &dp){
        if(i<0){
            return 0;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int p1=1e8,p2=1e8,p3=1e8;
        if(prev!=0){
            p1=colors[i][0]+solve(i-1,colors,0,dp);
        }
        if(prev!=1){
            p2=colors[i][1]+solve(i-1,colors,1,dp);
        }
        if(prev!=2){
            p3=colors[i][2]+solve(i-1,colors,2,dp);
        }
        return dp[i][prev]=min(p1,min(p2,p3));
    }
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        vector<vector<int>> dp (N,vector<int>(4,-1));
        return solve(N-1,colors,3,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends