//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isSafe(vector<vector<int>>& grid,int i,int j,string& v){
        if(i<grid.size() && i>=0 && j<grid[0].size() && j>=0 && grid[i][j]!=0) return true;
        v.push_back('E');
        return false;
    }
    void dfs(vector<vector<int>>& grid,string& v,int i,int j){
        grid[i][j]=0;
        if(isSafe(grid,i+1,j,v)){
            v.push_back('D');
            dfs(grid,v,i+1,j);
        }
        if(isSafe(grid,i-1,j,v)){
            v.push_back('U');
            dfs(grid,v,i-1,j);
        }
         if(isSafe(grid,i,j+1,v)){
            v.push_back('R');
            dfs(grid,v,i,j+1);
        }
        if(isSafe(grid,i,j-1,v)){
            v.push_back('L');
            dfs(grid,v,i,j-1);
        }
       
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        unordered_set<string> s;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    string v;
                    v.push_back('S');
                    dfs(grid,v,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends