//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   	bool isPossible(int i,int j,vector<vector<int>>& dirs,string word,vector<vector<char>>& grid){
	    int n=grid.size();
	    int m=grid[0].size();
	    for(auto it:dirs){
	        int newi=i;
	        int newj=j;
	        int len=0;
	        while(newi>=0 && newj>=0 && newi<n && newj<m && len<word.length() && grid[newi][newj]==word[len]){
	            newi+=it[0];
	            newj+=it[1];
	            len++;
	        }
	        if(len==word.length())
	        return true;
	    }
	    return false;
	}
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> ans;
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> dirs={{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,0},{1,1},{0,1}};
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0] && isPossible(i,j,dirs,word,grid)){
	                ans.push_back({i,j});
	            }
	        }
	    }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends