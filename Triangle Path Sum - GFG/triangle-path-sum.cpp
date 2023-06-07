//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

  public:
    int solve(vector<vector<int>>& triangle,int h,int j,vector<vector<int>>& dp){
        if(h==triangle.size()){
            return 0;
        }
        if(dp[h][j]!=-1){
            return dp[h][j];
        }
        int down=triangle[h][j]+solve(triangle,h+1,j,dp);
        int diag=triangle[h][j]+solve(triangle,h+1,j+1,dp);
        return dp[h][j]=min(down,diag);
    }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        int h=n;
        int j=h;
        vector<vector<int>> dp(h,vector<int>(j,-1));
       return  solve(triangle,0,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends