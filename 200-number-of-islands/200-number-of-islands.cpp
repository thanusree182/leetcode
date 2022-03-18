class Solution {
    void mark(vector<vector<char>>& matrix,int i,int j,int r,int c){
        if(i<0||i>=r||j<0||j>=c||matrix[i][j]!='1')
            return;
        matrix[i][j]='2';
        mark(matrix,i+1,j,r,c);
        mark(matrix,i,j+1,r,c);
        mark(matrix,i-1,j,r,c);
        mark(matrix,i,j-1,r,c);
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        if(rows==0)
            return 0;
        int cols=grid[0].size();
        int islands=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    mark(grid,i,j,rows,cols);
                    islands++;
                }
            }
        }
        return islands;
    }
};