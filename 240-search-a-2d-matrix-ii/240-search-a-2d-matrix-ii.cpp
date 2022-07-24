class Solution {
     
    
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int c=matrix[0].size()-1;
          int r=0;
       while(c>=0 && r<matrix.size()){ 
         if(target==matrix[r][c]){
             return 1;
         }
         else if(target<matrix[r][c]){
             c--;
         }
        else{
            r++;
            }
       }
         return 0;
    }
};