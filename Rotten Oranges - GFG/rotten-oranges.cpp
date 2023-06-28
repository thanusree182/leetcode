//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        queue<pair<pair<int,int>,int>> q;
        int count_fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if (grid[i][j] == 1) count_fresh++;
            }
        }
        int maxi=0;
        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};
        int count=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;
            q.pop();
            maxi=max(maxi,time);
            for(int i=0;i<4;i++){
                int nrow= r+dr[i];
                int ncol=c+dc[i];
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1 ){
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol]=2;
                    count++;
                }
            }
        }
        if(count_fresh!=count){
            return -1;
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends