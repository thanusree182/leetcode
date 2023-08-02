//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool valid(vector<vector<int>> A, int N,int M,vector<vector<bool>>& vis,int x,int y){
        if( x>=N || y>=M || x<0 || y<0 || A[x][y]==0 || vis[x][y])
        return false;
        vis[x][y]=true;
        return true;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
         if(X>=N || Y>=M || A[0][0]==0 || A[X][Y]==0)
         return -1;
         vector<vector<bool>> vis(N,vector<bool> (M,false));
         queue<vector<int>> q;
         q.push({0,0,0});
         while(!q.empty()){
             auto it=q.front();
             q.pop();
             if(it[0]==X && it[1]==Y)
             return it[2];
             if(valid(A,N,M,vis,it[0]-1,it[1]))
             q.push({it[0]-1,it[1],it[2]+1});
              if(valid(A,N,M,vis,it[0]+1,it[1]))
             q.push({it[0]+1,it[1],it[2]+1});
              if(valid(A,N,M,vis,it[0],it[1]-1))
             q.push({it[0],it[1]-1,it[2]+1});
              if(valid(A,N,M,vis,it[0],it[1]+1))
             q.push({it[0],it[1]+1,it[2]+1});
         }
         
         return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends