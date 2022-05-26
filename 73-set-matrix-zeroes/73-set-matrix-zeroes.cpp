

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> cols;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for(auto x:rows){
            for(int j=0;j<matrix[0].size();j++){
                 matrix[x][j]=0;
            }
        }
        for(auto x:cols){
            for(int j=0;j<n;j++){
                 matrix[j][x]=0;
            }
        }
        
    }
};