class Solution {
public:
    int n,m;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        int ans=0;
       m=grid[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]) 
                    ans=max(ans,travel(i,j,grid));
            
        
        return ans;
    }
 private:
    
    int travel(int i,int j, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= n || j >= m || !grid[i][j])
            return 0;
        grid[i][j]=0;
        return 1 + travel(i-1, j, grid) + travel(i, j-1, grid) + travel(i+1, j, grid) + travel(i, j+1, grid);
    }
};

