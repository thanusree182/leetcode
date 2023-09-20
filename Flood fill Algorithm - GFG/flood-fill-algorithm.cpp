//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>& image,int sr,int sc,int newColor,int initial_color,int dr[],int dc[],vector<vector<int>>& ans)
    {
        ans[sr][sc]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int newr=sr+dr[i];
            int newc=sc+dc[i];
            if(newr>=0 && newr<n && newc>=0 && newc<m && image[newr][newc]==initial_color && ans[newr][newc]!=newColor){
                dfs(image,newr,newc,newColor,initial_color,dr,dc,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> ans=image;
        int initial_color=image[sr][sc];
        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};
         dfs(image,sr,sc,newColor,initial_color,dr,dc,ans);
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends