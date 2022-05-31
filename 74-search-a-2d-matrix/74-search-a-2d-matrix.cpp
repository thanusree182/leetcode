class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(m==0 || n==0)
            return false;
        int start=0;
        int end=m*n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int ind=matrix[mid/m][mid%m];
            if(target==ind)
                return 1;
           else if(target<ind)
                end = mid - 1;
            else
                start = mid + 1;   
        }
        return 0;
        
    }
};

