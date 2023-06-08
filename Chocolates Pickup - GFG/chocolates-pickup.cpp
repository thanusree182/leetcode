//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int func(vector<vector<int>>& grid,int i,int j1,int j2,int m,int n,vector<vector<vector<int>>> &dp ){
        //outof bounds
        if(j1<0 || j2<0 || j1>=m || j2>=m ){
            return -1e9;
        }
        //base case
        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        //try all paths
        int ans=-1e8;
        for(int k1=-1;k1<=1;k1++){
            for(int k2=-1;k2<=1;k2++){
                int value=0;
                 if(j1==j2){
                     value=grid[i][j1];
                 }
                 else{
                     value=grid[i][j1]+grid[i][j2];
                 }
                 value+=func(grid,i+1,j1+k1,j2+k2,m,n,dp);
                 ans=max(ans,value);
            }
        }
        return dp[i][j1][j2]=ans;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return func(grid,0,0,m-1,m,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends